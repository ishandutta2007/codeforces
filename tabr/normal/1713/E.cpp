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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        dsu uf(2 * n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (uf.same(i, j) || uf.same(i, j + n)) {
                    continue;
                }
                if (a[i][j] > a[j][i]) {
                    uf.unite(i, j + n);
                    uf.unite(i + n, j);
                } else if (a[i][j] < a[j][i]) {
                    uf.unite(i, j);
                    uf.unite(i + n, j + n);
                }
            }
        }
        auto Swap = [&](int i) {
            for (int j = 0; j < n; j++) {
                swap(a[i][j], a[j][i]);
            }
        };
        for (int i = 0; i < n; i++) {
            if (uf.get(i) < uf.get(i + n)) {
                Swap(i);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " \n"[j == n - 1];
            }
        }
    }
    return 0;
}