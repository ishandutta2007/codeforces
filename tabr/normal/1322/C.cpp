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
        int n, m;
        cin >> n >> m;
        vector<ll> c(n);
        vector<vector<int>> g(n);
        vector<pair<vector<int>, ll>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            v[i].second = c[i];
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[y].emplace_back(x);
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
            v[i].first = g[i];
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].first.empty()) {
                continue;
            }
            if (i != n - 1 && v[i].first == v[i + 1].first) {
                v[i + 1].second += v[i].second;
            } else {
                ans = __gcd(ans, v[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}