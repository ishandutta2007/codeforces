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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, ll>> x(m);
        vector<ll> a(m), s(m);
        for (int i = 0; i < m; i++) {
            cin >> x[i].first >> x[i].second;
            a[i] = x[i].first;
        }
        sort(a.begin(), a.end());
        s = a;
        for (int i = m - 2; i >= 0; i--) {
            s[i] += s[i + 1];
        }
        ll ans = 0;
        if (n <= m) {
            for (int i = 0; i < n; i++) {
                ans += a[m - 1 - i];
            }
        }
        for (int i = 0; i < m; i++) {
            ll b = x[i].second;
            ll k = upper_bound(a.begin(), a.end(), b) - a.begin();
            if (k == m) {
                ans = max(ans, x[i].first + x[i].second * (n - 1));
                continue;
            }
            ll z = s[k];
            k = m - k;
            if (x[i].first <= x[i].second) {
                z += x[i].first;
                k++;
            }
            if (k > n) {
                continue;
            }
            z += x[i].second * (n - k);
            ans = max(ans, z);
        }
        cout << ans << '\n';
    }
    return 0;
}