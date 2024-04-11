#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    ll d;
    cin >> d;
    vector<ll> a(n);
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x[i] = min(r2, r1 * (a[i] + 1)) + r1;
        y[i] = r3 + r1 * a[i];
    }
    debug(x, y);
    vector<ll> dp(2);
    for (int i = 0; i < n - 1; i++) {
        vector<ll> ndp(2);
        ndp[0] = dp[1] + x[i] + d;
        ndp[1] = min(dp[1] + y[i] + d, dp[0] + min(x[i], y[i]) + d * 3);
        ndp[0] = min(ndp[0], ndp[1]);
        swap(dp, ndp);
        debug(dp);
    }
    cout << min(dp[0] + min(y[n - 1] + d, x[n - 1] + d * 2), dp[1] + min(y[n - 1], x[n - 1] + d * 2)) << '\n';
    return 0;
}