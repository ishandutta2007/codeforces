#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, a[201], cnt[201], d[201][201], g[201][201], ans = 1e18, sum;
void checkmin(long long &x, long long y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        long long x;
        scanf("%lld", &x);
        if (x)
        {
            a[++sum] = x;
            if (sum > 150)
            {
                printf("3");
                return 0;
            }
            for (int j = 0; (1LL << j) <= a[sum]; j++)
            {
                if (a[sum] & (1LL << j))
                {
                    cnt[j]++;
                }
            }
        }
    }
    if (sum > 150)
    {
        printf("3");
        return 0;
    }
    for (int i = 0; i <= 100; i++)
    {
        if (cnt[i] > 2)
        {
            printf("3");
            return 0;
        }
    }
    memset(d, 127 / 3, sizeof(d));
    memset(g, 127 / 3, sizeof(g));
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if ((a[i] & a[j]) && i != j)
            {
                d[i][j] = d[j][i] = g[i][j] = g[j][i] = 1;
            }
        }
    }
    for (int k = 1; k <= sum; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                checkmin(ans, d[i][j] + g[i][k] + g[k][j]);
            }
        }
        for (int i = 1; i <= sum; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                checkmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    if (ans == 1e18)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", ans);
    }
    return 0;
}