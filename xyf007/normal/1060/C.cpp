#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long n, m, a[2001], b[2001], sum1[2001], sum2[2001], x;
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(long long &x, long long y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    memset(sum1, 127, sizeof(sum1));
    memset(sum2, 127, sizeof(sum2));
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
    }
    scanf("%lld", &x);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            checkmin(sum1[j - i], a[j] - a[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            checkmin(sum2[j - i], b[j] - b[i]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sum1[i] * sum2[j] <= x)
            {
                checkmax(ans, i * j);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}