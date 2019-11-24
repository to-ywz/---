#include <stdlib.h>
#include <stdio.h>
#include "Search.h"
/**
 * @brief  斐波那契查找
 * @note   
 * @param  arr[]: 查找数组
 * @param  arrsize: 数组大小
 * @param  searchValue: 待查找元素
 * @retval 存在返回索引，返回-1
 */
int FibSearch(int arr[], int arrsize, int searchValue)
{
    int *temparr = (int *)malloc(sizeof(int)*arrsize);
    for (int i = 0; i < arrsize; i++)
    {
        temparr[i] = arr[i];
    }
    const int MAXSIZE = 100;
    int left = 0, right = arrsize - 1, mid;
    int Fib[MAXSIZE];
    //printf("start search!\n");
    int k = 0;
    //printf("Start create the Fibonacci array\n");
    ProduceFib(Fib, MAXSIZE);
    //printf("Finish create the Fibonacci array\n");
    while (right > Fib[k++] - 1)
        ;
    //printf("Get the index of the min Fibonacci number\n");
    for (int i = arrsize; i <= Fib[k] - 1; i++)
    {
        temparr[i] = temparr[right];
    }
    //printf("Finish the completing!\n");
    while (left <= right)
    {
        mid = left + Fib[k - 1] - 1;

        if (arr[mid] == searchValue)
        {
            if (mid <= arrsize - 1)
            {
                return mid;
            }
            else
            {
                return arrsize - 1;
            }
        }

        if (temparr[mid] > searchValue)
        {
            right = mid - 1;
            k--;
        }
        if (temparr[mid] < searchValue)
        {
            left = mid + 1;
            k -= 2;
        }
    }
    free(temparr);
    return -1;
}

void ProduceFib(int fib[], int size)
{
    fib[0] = fib[1] = 1;

    for (int i = 2; i < size; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

/**
 * @brief  二分查找
 * @note   无Bug版
 * @param  arr[]: 待查找数组
 * @param  n: 数组长度
 * @param  pivot: 待查找元素
 * @retval 存在返回索引，返回-1
 */
int binary_search(int arr[], int n, int pivot)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (pivot < arr[mid])
        {
            right = mid - 1;
            continue;
        }

        if (pivot > arr[mid])
        {
            left = mid + 1;
            continue;
        }

        return mid;
    }
    return -1;
}

/**
 * @brief  插值查找
 * @note   mid是公式，其实自己理解一下就好了，很简单
 * @param  arr[]: 待查找数组
 * @param  n: 数组长度
 * @param  pivot: 待查找元素
 * @retval 存在返回索引，返回-1
 */
int InterPolationSearch(int arr[], int arrsize, int pivot)
{
    int left = 0, mid, right = arrsize - 1;

    while (left <= right)
    {
        mid = left + ((pivot - arr[left]) / (arr[right] - arr[left]) * (right - left));
        if (pivot < arr[mid])
        {
            right = mid - 1;
            continue;
        }
        if (pivot > arr[mid])
        {
            left = mid + 1;
            continue;
        }
        return mid;
    }
    return -1;
}