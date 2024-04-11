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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll s = a[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ll t = s - a[i];
            if (t > 0) {
                ans = max(ans, 32 - __builtin_clz(s - a[i]));
            }
            s = max(a[i], s);
        }
        cout << ans << '\n';
    }
    return 0;
}