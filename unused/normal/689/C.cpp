#include <bits/stdc++.h>
using namespace std;

constexpr long long LIM = (long long)1e15;

int main()
{
    long long m;
    cin >> m;

    long long lo = 1, hi = 1e18, ans = -1;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        long long total = 0;
        for (long long i = 2; i * i * i <= mid; i++)
        {
            total += mid / i / i / i;
        }
        if (total > m)
        {
            hi = mid - 1;
        }
        else if (total < m)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }
    }

    printf("%lld\n", ans);
}