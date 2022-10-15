#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
long long n, ans;
int main()
{
    scanf("%lld", &n);
    for (int i = 2; i <= n; i++)
    {
        ans += (4LL * (n / i - 1)) * i;
    }
    printf("%lld\n", ans);
    return 0;
}