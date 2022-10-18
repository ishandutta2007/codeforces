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
    int tt;
    cin >> tt;
    while (tt--) {
        ll p, f;
        cin >> p >> f;
        ll cs, cw;
        cin >> cs >> cw;
        ll s, w;
        cin >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cs, cw);
        }
        ll ans = 0;
        for (ll i = 0; i <= cs; i++) {
            ll sum = i;
            if (s * i > p) {
                break;
            }
            ll x = min((p - i * s) / w, cw);
            sum += x;
            ll rs = cs - i, rw = cw - x;
            if (rs * s <= f) {
                sum += rs;
                sum += min((f - rs * s) / w, rw);
            } else {
                sum += f / s;
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}