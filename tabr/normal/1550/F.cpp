#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

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
    int m = (int) 1e6 + 10;
    int inf = (int) 1e9;
    int n, tt, s, d;
    cin >> n >> tt >> s >> d;
    s--;
    vector<int> a(n);
    vector<int> inv_a(m, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        inv_a[a[i]] = i;
    }
    vector<vector<pair<int, int>>> q(m);
    for (int i = 0; i < tt; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        q[y].emplace_back(x, i);
    }
    vector<int> ans(tt);
    vector<vector<pair<int, int>>> b(m);
    vector<vector<int>> c(n);
    for (int i = 0; i < n; i++) {
        c[i].emplace_back(i);
    }
    dsu uf(n);
    int add = 0;
    set<int> st(a.begin(), a.end());
    while (add < n - 1) {
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n; i++) {
            if (uf.get(i) != i) {
                continue;
            }
            for (int k : c[i]) {
                st.erase(a[k]);
            }
            int cost = inf, x = -1, y = -1;
            for (int k : c[i]) {
                auto it = st.lower_bound(a[k] - d);
                for (int _ = 0; _ < 2; _++) {
                    if (_) {
                        it = st.lower_bound(a[k] + d);
                    }
                    if (it != st.end()) {
                        int v = *it;
                        int w = abs(d - abs(a[k] - v));
                        if (w < cost) {
                            cost = w;
                            x = k;
                            y = inv_a[v];
                        }
                    }
                    if (it != st.begin()) {
                        it = prev(it);
                        int v = *it;
                        int w = abs(d - abs(a[k] - v));
                        if (w < cost) {
                            cost = w;
                            x = k;
                            y = inv_a[v];
                        }
                    }
                }
            }
            for (int k : c[i]) {
                st.emplace(a[k]);
            }
            if (cost != inf) {
                edges.emplace_back(cost, x, y);
            }
        }
        for (auto [cost, x, y] : edges) {
            int from = uf.get(x);
            int to = uf.get(y);
            if (uf.unite(from, to)) {
                add++;
                if (uf.get(from) != to) {
                    swap(from, to);
                }
                b[cost].emplace_back(x, y);
                c[to].insert(c[to].end(), c[from].begin(), c[from].end());
            }
        }
    }
    uf = dsu(n);
    for (int k = 0; k < m; k++) {
        for (auto [x, y] : b[k]) {
            uf.unite(x, y);
        }
        for (auto [end, id] : q[k]) {
            if (uf.same(s, end)) {
                ans[id] = 1;
            }
        }
    }
    for (int i : ans) {
        if (i) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}