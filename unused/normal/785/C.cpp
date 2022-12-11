#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n, m;
    scanf("%lld%lld",&n,&m);
    long long lo = 0, hi = 2e9, ans = n;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (mid * (mid + 1) / 2 >= n - m)
        {
            ans = min(ans, m + mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%lld\n", ans);
}