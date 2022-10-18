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
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
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
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[i] = make_pair(x, y);
    }
    dsu uf(n);
    vector<pair<int, int>> new_edges;
    for (auto [x, y] : edges) {
        if (uf.unite(x, y)) {
            new_edges.emplace_back(x, y);
        }
    }
    swap(edges, new_edges);
    vector<int> c(n);
    int q;
    cin >> q;
    vector<int> a(q), b(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        c[a[i]] ^= 1;
        c[b[i]] ^= 1;
    }
    if (*max_element(c.begin(), c.end()) == 1) {
        cout << "NO" << '\n';
        vector<vector<int>> g(n);
        for (int i = 0; i < (int) edges.size(); i++) {
            auto [x, y] = edges[i];
            g[x].emplace_back(i);
            g[y].emplace_back(i);
        }
        vector<int> d(n - 1);
        for (int i = 0; i < q; i++) {
            int x = a[i], y = b[i];
            auto dfs = [&](auto &&self, int v, int p) -> bool {
                if (v == y) {
                    return true;
                }
                for (int id : g[v]) {
                    int to = v ^ edges[id].first ^ edges[id].second;
                    if (to == p) {
                        continue;
                    }
                    if (self(self, to, v)) {
                        d[id] ^= 1;
                        return true;
                    }
                }
                d.pop_back();
                return false;
            };
            dfs(dfs, x, -1);
        }
        int ans = 0;
        vector<int> e(n);
        for (int i = 0; i < n; i++) {
            if (e[i]) {
                continue;
            }
            auto dfs = [&](auto &&self, int v, int p) -> void {
                e[v] = 1;
                int t = 0;
                for (int id : g[v]) {
                    int to = v ^ edges[id].first ^ edges[id].second;
                    if (d[id] == 0 || to == p) {
                        continue;
                    }
                    self(self, to, v);
                    t++;
                }
                if (v == i) {
                    ans += (t + 1) / 2;
                } else {
                    ans += t / 2;
                }
            };
            dfs(dfs, i, -1);
        }
        cout << ans << '\n';
    } else {
        vector<vector<int>> g(n);
        for (auto [x, y] : edges) {
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        cout << "YES" << '\n';
        for (int i = 0; i < q; i++) {
            int x = a[i], y = b[i];
            vector<int> d;
            auto dfs = [&](auto &&self, int v, int p) -> bool {
                d.emplace_back(v);
                if (v == y) {
                    return true;
                }
                for (int to : g[v]) {
                    if (to == p) {
                        continue;
                    }
                    if (self(self, to, v)) {
                        return true;
                    }
                }
                d.pop_back();
                return false;
            };
            dfs(dfs, x, -1);
            cout << d.size() << '\n';
            for (int j : d) {
                cout << j + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}