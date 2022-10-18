#include <bits/stdc++.h>
using namespace std;
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x(n), y(m);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> y[i];
        }
        vector<pair<int, int>> p(k);
        for (int i = 0; i < k; i++) {
            cin >> p[i].first >> p[i].second;
        }
        long long ans = 0;
        for (int _ = 0; _ < 2; _++) {
            vector<vector<int>> b(n);
            for (int i = 0; i < k; i++) {
                if (!binary_search(x.begin(), x.end(), p[i].first)) {
                    int id = (int) (lower_bound(x.begin(), x.end(), p[i].first) - x.begin());
                    b[id].emplace_back(p[i].second);
                }
            }
            for (int i = 0; i < n; i++) {
                if (b[i].empty()) {
                    continue;
                }
                long long c = (long long) b[i].size();
                c = c * (c - 1) / 2;
                map<int, int> mp;
                for (int j : b[i]) {
                    mp[j]++;
                }
                for (auto [key, val] : mp) {
                    c -= 1LL * val * (val - 1) / 2;
                }
                ans += c;
            }
            swap(x, y);
            swap(n, m);
            for (int i = 0; i < k; i++) {
                swap(p[i].first, p[i].second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}