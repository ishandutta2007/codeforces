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
        int a, b, q;
        cin >> a >> b >> q;
        vector<ll> c(a * b);
        for (int i = 0; i < a * b; i++) {
            if ((i % a) % b != (i % b) % a) {
                c[i]++;
            }
            if (i) {
                c[i] += c[i - 1];
            }
        }
        while (q--) {
            ll l, r, ans = 0;
            cin >> l >> r;
            ll x = l % (a * b);
            ll y = r % (a * b);
            ll s = l / (a * b);
            ll t = r / (a * b);
            ans = (t - s) * c[a * b - 1];
            ans += c[y];
            if (x) {
                ans -= c[x - 1];
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
    return 0;
}