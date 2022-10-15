#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, ans;
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    if ((n - 1) % k > 1)
    {
        ans = (n - 1) / k * 2 + 2;
    }
    else
    {
        if ((n - 1) % k == 1)
        {
            ans = (n - 1) / k * 2 + 1;
        }
        else
        {
            ans = (n - 1) / k * 2;
        }
    }
    printf("%d\n", ans);
    int t = (n - 1) % k, cnt = 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= (n - 1) / k; j++)
        {
            if (!j)
            {
                printf("1 %d\n", ++cnt);
            }
            else
            {
                printf("%d %d\n", cnt++, cnt);
            }
        }
    }
    for (int i = t + 1; i <= k; i++)
    {
        for (int j = 1; j <= (n - 1) / k; j++)
        {
            if (j == 1)
            {
                printf("1 %d\n", ++cnt);
            }
            else
            {
                printf("%d %d\n", cnt++, cnt);
            }
        }
    }
    return 0;
}