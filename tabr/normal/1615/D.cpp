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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> x(n - 1), y(n - 1), z(n - 1), w(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> x[i] >> y[i] >> z[i];
            x[i]--, y[i]--;
            g[x[i]].emplace_back(i);
            g[y[i]].emplace_back(i);
            w[i] = z[i];
            if (z[i] != -1) {
                z[i] = __builtin_parity(z[i]);
            }
        }
        vector<int> dp(n);
        auto dfs = [&](auto &&self, int v, int p) -> void {
            for (int id : g[v]) {
                int to = v ^ x[id] ^ y[id];
                if (to == p) {
                    continue;
                }
                dp[to] = dp[v] ^ max(0, z[id]);
                self(self, to, v);
            }
        };
        dfs(dfs, 0, -1);
        dsu uf(2 * n);
        for (int i = 0; i < n - 1; i++) {
            if (z[i] != -1) {
                uf.unite(x[i], y[i]);
                uf.unite(x[i] + n, y[i] + n);
            }
        }
        vector<int> a(m), b(m), c(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--, b[i]--;
            int d = dp[a[i]] ^ dp[b[i]];
            if (c[i] != d) {
                uf.unite(a[i], b[i] + n);
                uf.unite(a[i] + n, b[i]);
            } else {
                uf.unite(a[i], b[i]);
                uf.unite(a[i] + n, b[i] + n);
            }
        }
        for (int i = 0; i < n; i++) {
            if (uf.same(i, i + n)) {
                uf.unite(0, n);
                break;
            }
        }
        if (uf.same(0, n)) {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            if (z[i] == -1) {
                if (!uf.same(x[i], y[i]) && !uf.same(x[i], y[i] + n)) {
                    uf.unite(x[i], y[i]);
                    uf.unite(x[i] + n, y[i] + n);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            assert(uf.same(0, i) || uf.same(0, i + n));
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n - 1; i++) {
            if (z[i] == -1) {
                z[i] = !uf.same(x[i], y[i]);
            } else {
                z[i] = w[i];
            }
            cout << x[i] + 1 << " " << y[i] + 1 << " " << z[i] << '\n';
        }
    }
    return 0;
}