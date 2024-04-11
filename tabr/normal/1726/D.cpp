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
        int n, m;
        cin >> n >> m;
        dsu uf(n);
        string ans(m, '0');
        vector<int> x(m), y(m);
        auto Check = [&](vector<int> a) {
            debug(a);
            dsu d(n);
            d.unite(x[a[0]], y[a[0]]);
            d.unite(x[a[1]], y[a[1]]);
            return d.same(x[a[2]], y[a[2]]);
        };
        vector<int> c;
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        for (int i = 0; i < m; i++) {
            if (uf.unite(x[i], y[i])) {
                ans[i] = '1';
            } else {
                c.emplace_back(i);
            }
        }
        if (m - n == 2 && Check(c)) {
            for (int z : c) {
                uf = dsu(n);
                string t(m, '0');
                t[z] = '1';
                uf.unite(x[z], y[z]);
                vector<int> d;
                for (int i = 0; i < m; i++) {
                    if (z != i && uf.unite(x[i], y[i])) {
                        t[i] = '1';
                    } else if (z != i) {
                        d.emplace_back(i);
                    }
                }
                debug(t);
                if (!Check(d)) {
                    ans = t;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}