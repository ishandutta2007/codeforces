#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i].first >> b[i].second;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        map<int, vector<int>> mq;
        for (auto [x, y] : mp) {
            mq[y].emplace_back(x);
        }
        vector<vector<int>> c;
        vector<int> d;
        for (auto [x, y] : mq) {
            c.emplace_back(y);
            d.emplace_back(x);
        }
        int sz = (int) mq.size();
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long csum = d[i] + d[j];
                long long mx = 0;
                for (int x = (int) c[i].size() - 1; x >= 0; x--) {
                    for (int y = (int) c[j].size() - 1; y >= 0; y--) {
                        if (mx >= c[i][x] + c[j][y]) {
                            break;
                        }
                        int xx = c[i][x];
                        int yy = c[j][y];
                        if (xx > yy) {
                            swap(xx, yy);
                        }
                        if (!binary_search(b.begin(), b.end(), make_pair(xx, yy))) {
                            mx = c[i][x] + c[j][y];
                            break;
                        }
                    }
                }
                ans = max(ans, csum * mx);
            }
            long long csum = d[i] + d[i];
            long long mx = 0;
            for (int x = (int) c[i].size() - 1; x >= 0; x--) {
                for (int y = x - 1; y >= 0; y--) {
                    if (mx >= c[i][x] + c[i][y]) {
                        break;
                    }
                    if (!binary_search(b.begin(), b.end(), make_pair(c[i][y], c[i][x]))) {
                        mx = c[i][x] + c[i][y];
                        break;
                    }
                }
            }
            ans = max(ans, csum * mx);
        }
        cout << ans << '\n';
    }
    return 0;
}