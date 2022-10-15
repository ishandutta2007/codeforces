#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
long long n, a[100001], sum[100001];
int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sum[0] = a[0] + 1;
    for (int i = 1; i < n; i++)
    {
        sum[i] = std::max(sum[i - 1], a[i] + 1);
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (sum[i] - sum[i - 1] > 1)
        {
            sum[i - 1] = sum[i] - 1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += sum[i] - a[i] - 1;
    }
    printf("%lld", ans);
    return 0;
}//gg