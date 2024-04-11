#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        if (sz[x] < sz[y]) {
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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                c = -1;
                break;
            }
        }
        if (c == -1) {
            cout << -1 << '\n';
            continue;
        }
        dsu uf(20);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                uf.unite(a[i] - 'a', b[i] - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < 20; i++) {
            if (uf.get(i) == i && uf.sz[i] != 1) {
                ans += uf.sz[i] - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}