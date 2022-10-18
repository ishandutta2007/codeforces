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
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 == 0) {
                sum += a[i];
                a[i] = -a[i];
            }
        }
        vector<ll> mn(2);
        ll z = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i % 2;
            z += a[i];
            ans = max(ans, z - mn[j]);
            mn[j] = min(mn[j], z);
        }
        ans += sum;
        cout << ans << '\n';
    }
    return 0;
}