#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, l, a[200001], dis[200001];
int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        cin >> n >> l;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            dis[i] = a[i] - a[i - 1];
        }
        dis[n + 1] = l - a[n];
        double ans = 0, v1 = 1, v2 = 1, d1 = dis[1], d2 = dis[n + 1];
        int p1 = 1, p2 = n + 1;
        while (p1 < p2)
        {
            double t1 = d1 / v1, t2 = d2 / v2;
            if (t1 == t2)
            {
                ans += t1;
                d1 = dis[++p1];
                d2 = dis[--p2];
                v1 += 1;
                v2 += 1;
                continue;
            }
            if (t1 < t2)
            {
                ans += t1;
                d1 = dis[++p1];
                v1 += 1;
                d2 -= t1 * v2;
            }
            else
            {
                ans += t2;
                d2 = dis[--p2];
                v2 += 1;
                d1 -= t2 * v1;
            }
        }
        if (p1 == p2)
        {
            ans += min(d1, d2) / (v1 + v2);
        }
        cout << fixed << setprecision(8) << ans << '\n';
    }
    return 0;
}