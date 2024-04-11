#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
int n;
int main()
{
    scanf("%d", &n);
    int ans = 1, nn = n;
    for (int i = 2; i <= n; i++)
    {
        if (!(n % i))
        {
            ans *= i;
            while (!(n % i))
            {
                n /= i;
            }
        }
    }
    printf("%d ", ans);
    int sum = 0;
    while (ans % nn)
    {
        ans *= ans;
        sum++;
    }
    if (ans == nn)
    {
        printf("%d", sum);
    }
    else
    {
        printf("%d", sum + 1);
    }
    return 0;
}