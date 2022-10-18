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

vector<int> topsort(const vector<vector<int>> &g) {
    int n = (int) g.size();
    vector<int> deg(n);
    for (int v = 0; v < n; v++) {
        for (int to : g[v]) {
            deg[to]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            res.emplace_back(i);
        }
    }
    for (int i = 0; i < (int) res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int) res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dsu uf(2 * n);
    vector<vector<pair<int, int>>> d(n);
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        op--, x--, y--;
        uf.unite(x, y + n);
        uf.unite(y, x + n);
        d[x].emplace_back(y, op);
        d[y].emplace_back(x, op);
    }
    for (int i = 0; i < n; i++) {
        if (uf.same(i, i + n)) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    vector<vector<int>> c(2 * n);
    for (int i = 0; i < n; i++) {
        c[uf.get(i)].emplace_back(i);
    }
    string dir(n, '?');
    vector<int> pos(n);
    vector<vector<int>> g(n);
    for (int z = 0; z < 2 * n; z++) {
        if (!uf.root(z)) {
            continue;
        }
        int w = uf.get(z < n ? z + n : z - n);
        if (z > w) {
            continue;
        }
        for (int i : c[w]) {
            dir[i] = 'L';
        }
        for (int i : c[z]) {
            dir[i] = 'R';
        }
        for (int i : c[w]) {
            for (auto [j, k] : d[i]) {
                if (k == 0) {
                    g[i].emplace_back(j);
                } else {
                    g[j].emplace_back(i);
                }
            }
        }
    }
    vector<int> b = topsort(g);
    if (b.empty()) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << dir[i] << " " << pos[i] << '\n';
    }
    return 0;
}