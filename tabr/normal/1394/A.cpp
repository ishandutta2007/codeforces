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
    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> x, y;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (a > m) {
            x.emplace_back(a);
        } else {
            y.emplace_back(a);
        }
    }
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    for (int i = 1; i < y.size(); i++) {
        y[i] += y[i - 1];
    }
    ll ans = 0;
    ll s = 0;
    ll sz = y.size();
    for (ll i = 0; i <= x.size(); i++) {
        if (i != 0) {
            s += x[i - 1];
        }
        if (i + max(0LL, i - 1) * d > n) {
            break;
        }
        ll mn = max(0LL, n - d * i - i);
        ll mx = max(0LL, n - d * (i - 1) - i);
        mx = min(mx, n);
        if (mn <= sz) {
            ll t = s;
            if (!y.empty() && mx != 0) {
                t += y[min(mx - 1, (ll)(sz - 1))];
            }
            ans = max(ans, t);
        }
    }
    cout << ans << '\n';
    return 0;
}