#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
long long q, n;
int main()
{
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld", &n);
        std::vector<long long> a(n + 1);
        long long max = 0;
        for (long long i = 1; i <= n; i++)
        {
            long long x;
            scanf("%lld", &x);
            a[x]++;
            if (x > max)
            {
                max = x;
            }
        }
        std::sort(a.rbegin(), a.rend());
        long long last = a[0], sum = a[0];
        for (long long i = 1; i < n; i++)
        {
            if (last <= 1)
            {
                printf("%lld\n", sum);
                goto next;
            }
            int temp = std::min(last - 1, a[i]);
            sum += temp;
            last = temp;
        }
        printf("%lld\n", sum);
        next:;
    }
    return 0;
}