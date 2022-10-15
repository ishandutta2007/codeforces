#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
long long n, k, q, a, b;
int main()
{
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
        if (k <= n * b)
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", std::min(n, (k - 1 - n * b) / (a - b)));
    }
    return 0;
}