#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x, y, l, r;
    cin >> x >> y >> l >> r;

    vector<long long> vt;

    for (long long A = 1; A <= r;)
    {
        for (long long B = 1; A + B <= r;)
        {
            if (A + B >= l) vt.push_back(A + B);

            if (B > r / y) break;
            B *= y;
        }

        if (A > r / x) break;
        A *= x;
    }

    sort(vt.begin(), vt.end());
    vt.push_back(r + 1);
    long long L = l;
    long long ans = 0;
    for (auto e : vt)
    {
        ans = max(ans, e - L);
        L = e + 1;
    }
    printf("%lld\n", ans);
}