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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<vector<int>> edges(m);
    vector<int> deg(n);
    vector<vector<int>> a(k);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(i);
        edges[i] = {u, v, w};
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [&](int x, int y) {
            return edges[x][2] < edges[y][2];
        });
        deg[i] = g[i].size();
        a[deg[i] - 1].emplace_back(i);
        for (int j = 0; j < deg[i]; j++) {
            g[i][j] = edges[g[i][j]][1];
        }
    }
    vector<vector<vector<bool>>> c(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            bool ok = true;
            vector<bool> t(n);
            for (int v : a[i]) {
                if (t[g[v][j]]) {
                    ok = false;
                    break;
                }
                t[g[v][j]] = true;
            }
            if (ok) {
                c[i].emplace_back(t);
            }
        }
    }
    map<vector<bool>, int> dp;
    dp[vector<bool>(n)] = 1;
    for (int i = 0; i < k; i++) {
        map<vector<bool>, int> ndp;
        for (int j = 0; j < c[i].size(); j++) {
            for (auto e : dp) {
                vector<bool> v = e.first;
                bool ok = true;
                for (int l = 0; l < n; l++) {
                    if (v[l] && c[i][j][l]) {
                        ok = false;
                        break;
                    }
                    if (c[i][j][l]) {
                        v[l] = true;
                    }
                }
                if (ok) {
                    ndp[v] += e.second;
                }
            }
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (auto e : dp) {
        ans += e.second;
    }
    cout << ans << '\n';
    return 0;
}