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
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll ans = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    long double pi = acosl(-1);
    vector<long double> p(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p[j] = atan2l(x[j] - x[i], y[j] - y[i]);
            } else {
                p[j] = 100;
            }
        }
        sort(p.begin(), p.end());
        debug(p);
        for (int j = 0; j < n - 1; j++) {
            ll c = lower_bound(p.begin(), p.end(), p[j] + pi) - p.begin();
            c -= j + 1;
            c += lower_bound(p.begin(), p.end(), p[j] - pi) - p.begin();
            debug(c);
            ans -= c * (c - 1) * (c - 2) / 6;
        }
    }
    cout << ans << '\n';
    return 0;
}