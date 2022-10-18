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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<vector<int>> t(n);
    function<void(int, int, int)> build = [&](int v, int p, int s) {
        vector<int> x(1, s);
        for (int to : g[v]) {
            if (to == p) continue;
            x.emplace_back(to);
        }
        for (int i = 0; i < x.size() - 1; i++) {
            t[x[i]].emplace_back(x[i + 1]);
            t[x[i + 1]].emplace_back(x[i]);
        }
        for (int to : g[v]) {
            if (to == p) continue;
            build(to, v, x.back());
        }
    };
    build(0, -1, 0);
    vector<int> pos(n), end(n), depth(n);
    int sz = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        pos[v] = sz;
        sz++;
        for (int to : t[v]) {
            if (to == p) continue;
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
        end[v] = sz;
    };
    dfs(0, -1);
    auto eval = [&](int x, int y) {
        return (pos[x] <= pos[y] && end[y] <= end[x]) || (pos[y] <= pos[x] && end[x] <= end[y]);
    };
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<pair<int, int>> x(k);
        for (int j = 0; j < k; j++) {
            cin >> x[j].second;
            x[j].second--;
            x[j].first = depth[x[j].second];
        }
        sort(x.begin(), x.end());
        bool ok = true;
        for (int j = 0; j < k - 1; j++) {
            if (x[j].first == x[j + 1].first) {
                ok = false;
                break;
            }
            if (!eval(x[j].second, x[j + 1].second)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}