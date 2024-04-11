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
        dsu uf(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            uf.unite(x, y);
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        if (uf.sz[uf.get(0)] != n) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<int> a(n);
        vector<int> b(n);
        set<int> st;
        st.emplace(0);
        while (!st.empty()) {
            int v = *st.begin();
            st.erase(st.begin());
            if (b[v]) {
                continue;
            }
            a[v] = 1;
            b[v] = 1;
            vector<int> c;
            for (int to : g[v]) {
                if (b[to]) {
                    continue;
                }
                b[to] = 1;
                c.emplace_back(to);
            }
            for (int u : c) {
                for (int to : g[u]) {
                    if (b[to]) {
                        continue;
                    } else {
                        st.emplace(to);
                    }
                }
            }
        }

        cout << accumulate(a.begin(), a.end(), 0) << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}