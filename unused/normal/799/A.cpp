#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    long long n,t,k,d;
    cin>>n>>t>>k>>d;

    long long t1 = (n + k - 1) / k * t;
    long long lo = d, hi = 100000000, t2 = 0;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if ((mid / t + (mid - d) / t) * k >= n)
        {
            t2 = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    if (t1 <= t2) printf("NO\n");
    else printf("YES\n");
}