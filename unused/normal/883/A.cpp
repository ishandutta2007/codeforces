#include <bits/stdc++.h>
using namespace std;

long long t[100005];

int main()
{
    cin.sync_with_stdio(false);

    long long n, m, a; long long d;
    cin >> n >> m >> a >> d;
    for (int i = 0; i < m; i++) cin >> t[i];

    long long L = 1, R = 0;
    long long ans = 0, last = 0;
    while (L <= n && R < m)
    {
        if (t[R] <= L * a)
        {
            last = t[R] + d + 1;
            L = min(n + 1, max(L, (last - 1) / a + 1));
            ++ans;
        }
        else if (L >= n - 100 || t[R] <= L * a + d * 2)
        {
            last = L * a + d + 1;
            L = min(n + 1, max(L, (last - 1) / a + 1));
            ++ans;
        }
        else
        {
            long long upper = max(L, min(n, (t[R] - d * 2) / a)) * a;
            long long cnt = upper / a - L + 1;
            long long X = d / a + 1;
            long long p = (cnt + X - 1) / X;

            ans += p;

            last = (L + (p - 1) * X) * a + d + 1;
            L = min(n + 1, max(L, (last - 1) / a + 1));
        }
        while (R < m && t[R] < last) ++R;
    }

    if (L <= n)
    {
        long long cnt = n - L + 1;
        long long X = d / a + 1;
        ans += (cnt + X - 1) / X;
    }

    while (R < m)
    {
        long long closed = t[R] + d;
        while (R < m && t[R] <= closed) ++R;
        ++ans;
    }

    printf("%lld\n", ans);
}