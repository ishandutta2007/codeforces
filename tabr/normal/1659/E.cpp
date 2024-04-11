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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<dsu> uf(60, dsu(n));
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        edges[i] = make_tuple(a, b, w);
        for (int j = 0; j < 30; j++) {
            if (w & (1 << j)) {
                uf[j].unite(a, b);
                uf[j + 30].unite(a, b);
            }
        }
        for (int j = 1; j < 30; j++) {
            if (w % 2 == 0 && !(w & (1 << j))) {
                uf[j + 30].unite(a, b);
            }
        }
    }
    vector<bool> a(n);
    for (int z = 1; z < 30; z++) {
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            b[uf[z + 30].get(i)].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (!uf[z + 30].root(i)) {
                continue;
            }
            set<int> st;
            for (int j : b[i]) {
                st.emplace(uf[0].get(j));
            }
            if (st.size() > 1) {
                for (int j : b[i]) {
                    a[j] = true;
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bool found = false;
        for (int i = 0; i < 30; i++) {
            if (uf[i].same(x, y)) {
                found = true;
            }
        }
        if (found) {
            cout << 0 << '\n';
            continue;
        }
        if (a[x]) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}