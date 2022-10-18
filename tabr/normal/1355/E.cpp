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
    ll n, a, r, m;
    cin >> n >> a >> r >> m;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<ll> h(n), sh(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++) {
        sh[i] = h[i] + (i ? sh[i - 1] : 0);
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ll s = h[i] * (i + 1) - sh[i];
        ll t = sh[n - 1] - sh[i] - h[i] * (n - 1 - i);
        ans = min(ans, s * a + t * r);
        debug(ans, s, t);
        if (s <= t) {
            ans = min(ans, s * m + (t - s) * r);
            if (i == n - 1) {
                continue;
            }
            ll lo = h[i], hi = h[i + 1] + 1;
            while (hi - lo > 1) {
                ll mid = (hi + lo) / 2;
                s = mid * (i + 1) - sh[i];
                t = sh[n - 1] - sh[i] - mid * (n - 1 - i);
                if (s <= t) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            s = lo * (i + 1) - sh[i];
            t = sh[n - 1] - sh[i] - lo * (n - 1 - i);
            assert(s <= t);
            ans = min(ans, s * m + (t - s) * r);
        } else {
            ans = min(ans, t * m + (s - t) * a);
            if (i == 0) {
                continue;
            }
            ll lo = h[i - 1] - 1, hi = h[i];
            while (hi - lo > 1) {
                ll mid = (hi + lo) / 2;
                s = mid * (i + 1) - sh[i];
                t = sh[n - 1] - sh[i] - mid * (n - 1 - i);
                if (s <= t) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            s = hi * (i)-sh[i - 1];
            t = sh[n - 1] - sh[i - 1] - hi * (n - i);
            assert(s > t);
            ans = min(ans, t * m + (s - t) * a);
            debug(s, t);
        }
        debug(ans);
    }
    cout << ans << '\n';
    return 0;
}