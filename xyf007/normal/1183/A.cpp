#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n;
int main()
{
    scanf("%d", &n);
    for (int i = n;; i++)
    {
        int sum = 0, temp = i;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (!(sum % 4))
        {
            printf("%d", i);
            return 0;
        }
    }
 
    return 0;
}//