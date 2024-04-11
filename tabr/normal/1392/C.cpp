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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            if (i) {
                b[i] = max(b[i], b[i - 1]);
            }
        }
        ll ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == b[i]) {
                continue;
            }
            ll s = b[i] - a[i];
            ll pre = 0;
            if (i != n - 1 && b[i] == b[i + 1]) {
                pre = b[i] - a[i + 1];
            }
            s -= pre;
            s = max(s, 0LL);
            ans += s;
        }
        cout << ans << '\n';
    }
    return 0;
}