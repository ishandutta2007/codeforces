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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            a[i] -= v;
        }
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            a[i] += t;
        }
        vector<vector<int>> g(n);
        dsu uf(n * 2);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            uf.unite(x, y + n);
            uf.unite(x + n, y);
        }
        vector<int> was(n);
        auto dfs = [&](auto &&self, int v) -> void {
            was[v] = 1;
            for (int to : g[v]) {
                if (was[to]) {
                    continue;
                }
                self(self, to);
                a[v] -= a[to];
                a[to] = 0;
            }
        };
        dfs(dfs, 0);
        long long k = abs(a[0]);
        if (uf.same(0, n)) {
            if (k % 2 == 0) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            if (k == 0) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}