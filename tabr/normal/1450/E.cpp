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
    dsu uf(2 * n);
    int inf = (int)1e9;
    vector<vector<int>> d(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int x, y, b;
        cin >> x >> y >> b;
        x--, y--;
        uf.unite(x, y + n);
        uf.unite(y, x + n);
        d[x][y] = 1;
        d[y][x] = 1 - 2 * b;
    }
    if (uf.same(0, n)) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    pair<int, int> ans(-1, -1);
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) {
            cout << "NO" << '\n';
            return 0;
        }
        for (int j = 0; j < n; j++) {
            ans = max(ans, {d[i][j], i});
        }
    }
    cout << "YES" << '\n';
    cout << ans.first << '\n';
    for (int i = 0; i < n; i++) {
        cout << d[ans.second][i] << " ";
    }
    return 0;
}