#include <bits/stdc++.h>
using namespace std;

int x[60006],v[60006];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&x[i]);
    for (int i = 0; i < n; i++) scanf("%d",&v[i]);

    double lo = 0, hi = 1e18, ans;
    for (int i = 0; i < 100; i++)
    {
        double mid = (lo + hi) / 2;

        double l = -1e100, r = 1e100;

        for (int j = 0; j < n; j++)
        {
            l = max(l, x[j] - v[j] * mid);
            r = min(r, x[j] + v[j] * mid);
        }

        if (l <= r)
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%.9f\n", ans);
}