#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = int;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        return max(x, y);
    }

    sparse(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) {
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};

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
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> x(m), y(m);
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        vector<int> low(n - 1, -1), high(n - 1, m - 1);
        while (true) {
            vector<int> mid(n - 1);
            bool done = true;
            for (int i = 0; i < n - 1; i++) {
                if (high[i] - low[i] > 1) {
                    done = false;
                }
                mid[i] = (high[i] + low[i]) >> 1;
            }
            if (done) {
                break;
            }
            vector<vector<int>> at(m);
            for (int i = 0; i < n - 1; i++) {
                if (mid[i] == -1) {
                    continue;
                }
                at[mid[i]].emplace_back(i);
            }
            dsu uf(n);
            for (int i = 0; i < m; i++) {
                uf.unite(x[i], y[i]);
                for (int j : at[i]) {
                    if (uf.same(j, j + 1)) {
                        high[j] = mid[j];
                    } else {
                        low[j] = mid[j];
                    }
                }
            }
        }
        sparse sp(high);
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == r) {
                cout << 0 << " \n"[q == 0];
            } else {
                cout << sp.get(l, r) + 1 << " \n"[q == 0];
            }
        }
    }
    return 0;
}