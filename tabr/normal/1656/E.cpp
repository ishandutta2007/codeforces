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
        dsu uf(2 * n);
        vector<int> deg(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            deg[x]++;
            deg[y]++;
            uf.unite(x, y + n);
            uf.unite(y, x + n);
        }
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                r = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            int ans = deg[i];
            if (!uf.same(i, r)) {
                ans = -ans;
            }
            cout << ans << " \n"[i == n - 1];
        }
    }
    return 0;
}