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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            q[p[i]] = i;
        }
        dsu uf(n);
        for (int i = 0; i < n; i++) {
            uf.unite(i, p[i]);
        }
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            if (uf.root(i)) {
                int j = i;
                do {
                    a[i].emplace_back(j);
                    j = q[j];
                } while (j != i);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (!uf.same(i, i + 1)) {
                int x = uf.get(i);
                int y = uf.get(i + 1);
                rotate(a[x].begin(), find(a[x].begin(), a[x].end(), i), a[x].end());
                rotate(a[y].begin(), find(a[y].begin(), a[y].end(), q[i + 1]), a[y].end());
                a[x].insert(a[x].begin() + 1, a[y].begin(), a[y].end());
                a[y].clear();
                uf.unite(y, x);
            }
        }
        vector<int> ans = a[uf.get(0)];
        for (int i = 0; i < n; i++) {
            cout << ans[i] + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}