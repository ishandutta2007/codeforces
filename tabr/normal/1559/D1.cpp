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

struct matching {
    vector<vector<int>> g;
    vector<int> pa;
    vector<int> pb;
    vector<int> was;
    int n, m;
    int res;
    int iter;

    matching(int _n, int _m) : n(_n), m(_m) {
        pa.assign(n, -1);
        pb.assign(m, -1);
        was.resize(n);
        g.resize(n);
        res = 0;
        iter = 0;
    }

    void add(int from, int to) {
        g[from].emplace_back(to);
    }

    bool dfs(int v) {
        was[v] = iter;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        for (int u : g[v]) {
            if (was[pb[u]] != iter && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            iter++;
            int add = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    add++;
                }
            }
            if (add == 0) {
                break;
            }
            res += add;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    for (int i = 0; i < m1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d1.unite(x, y);
    }
    for (int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d2.unite(x, y);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!d1.same(i, j) && !d2.same(i, j)) {
                d1.unite(i, j);
                d2.unite(i, j);
                ans.emplace_back(i, j);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << '\n';
    }
    return 0;
}