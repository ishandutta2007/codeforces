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
        dsu uf(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        for (int i = 0; i < n; i++) {
            uf.unite(a[i], b[i]);
        }
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if (uf.root(i)) {
                c.emplace_back(uf.size(i));
            }
        }
        sort(c.begin(), c.end());
        int d = 0;
        for (int i : c) {
            d += i / 2;
        }
        long long ans = 0;
        for (int i = 0; i < d; i++) {
            ans += n - i;
            ans -= i + 1;
        }
        ans *= 2;
        cout << ans << '\n';
    }
    return 0;
}