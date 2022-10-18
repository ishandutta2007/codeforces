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
        vector<int> p(n * 2);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
            p[i + n] = p[i];
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[(n + i - p[i]) % n]++;
        }
        sort(b.begin(), b.end(), [&](int i, int j) {
            return d[i] > d[j];
        });
        // debug(d);
        // debug(b);
        b.resize(min(10, n));
        sort(b.begin(), b.end());
        vector<int> a;
        for (int k : b) {
            int c = 0;
            dsu uf(n);
            for (int i = 0; i < n; i++) {
                uf.unite(i, p[i + k]);
            }
            for (int i = 0; i < n; i++) {
                if (uf.get(i) == i) {
                    c++;
                }
            }
            // debug(k, c);
            if (c >= n - m) {
                a.emplace_back(k);
            }
        }
        cout << a.size();
        for (int i : a) {
            cout << " " << i;
        }
        cout << '\n';
    }
    return 0;
}