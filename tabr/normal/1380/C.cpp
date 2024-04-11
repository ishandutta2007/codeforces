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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        ll ans = 0;
        ll cur = 0;
        ll sz = 0;
        for (int i = 0; i < n; i++) {
            if (sz == 0) {
                sz++;
            } else {
                sz++;
            }
            cur = a[i];
            if (sz * cur >= x) {
                sz = 0;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}