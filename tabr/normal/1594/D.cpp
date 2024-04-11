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
        dsu uf(2 * n);
        for (int i = 0; i < m; i++) {
            int x, y;
            string s;
            cin >> x >> y >> s;
            x--, y--;
            if (s[0] == 'i') {
                uf.unite(x, y + n);
                uf.unite(x + n, y);
            } else {
                uf.unite(x, y);
                uf.unite(x + n, y + n);
            }
        }
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (uf.same(i, i + n)) {
                ok = 0;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            int j = uf.get(i);
            if (j < n) {
                a[j]++;
            } else {
                b[j - n]++;
            }
        }
        for (int i = 0; i < n; i++) {
            ans += max(a[i], b[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}