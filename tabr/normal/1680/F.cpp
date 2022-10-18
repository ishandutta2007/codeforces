#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(i);
            g[y].emplace_back(i);
            edges[i] = make_pair(x, y);
        }
        vector<int> was(n);
        vector<int> pe(n, -1);
        vector<int> pv(n, -1);
        vector<int> depth(n);
        function<void(int)> Dfs = [&](int v) {
            was[v] = 1;
            for (int id : g[v]) {
                int to = v ^ edges[id].first ^ edges[id].second;
                if (was[to]) {
                    continue;
                }
                pe[to] = id;
                pv[to] = v;
                depth[to] = depth[v] + 1;
                Dfs(to);
            }
        };
        for (int i = 0; i < n; i++) {
            if (was[i]) {
                continue;
            }
            Dfs(i);
        }
        vector<int> a(n);
        for (auto [x, y] : edges) {
            if (depth[x] < depth[y]) {
                swap(x, y);
            }
            if (depth[x] % 2 == depth[y] % 2) {
                a[x]++;
                a[y]--;
            } else {
                a[x]--;
                a[y]++;
            }
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return depth[i] > depth[j];
        });
        for (int v : order) {
            if (pv[v] != -1) {
                a[pv[v]] += a[v];
            }
        }
        vector<int> ignores;
        ignores.emplace_back(pe[max_element(a.begin(), a.end()) - a.begin()]);
        for (int id = 0; id < m; id++) {
            auto [x, y] = edges[id];
            if (depth[x] % 2 == depth[y] % 2) {
                if (depth[x] < depth[y]) {
                    swap(x, y);
                }
                ignores.emplace_back(id);
                break;
            }
        }
        for (int ign : ignores) {
            dsu uf(2 * n + 1);
            for (int i = 0; i < m; i++) {
                auto [x, y] = edges[i];
                if (i == ign) {
                    uf.unite(x, 2 * n);
                    uf.unite(y, 2 * n);
                    continue;
                }
                uf.unite(x, y + n);
                uf.unite(x + n, y);
            }
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (uf.same(i, i + n)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "YES" << '\n';
                string ans;
                for (int i = 0; i < n; i++) {
                    if (uf.same(i, 2 * n)) {
                        ans += "1";
                    } else if (uf.same(i + n, 2 * n)) {
                        ans += "0";
                    } else if (uf.get(i) < uf.get(i + n)) {
                        ans += "1";
                    } else {
                        ans += "0";
                    }
                }
                cout << ans << '\n';
                break;
            } else if (ign == ignores.back()) {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}