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
        string s;
        cin >> s;
        dsu uf(2 * n);
        for (int i = 1; i < 2 * n; i++) {
            if (s[i - 1] != s[i]) {
                uf.unite(i, i - 1);
            }
        }
        vector<int> pos;
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '(') {
                pos.emplace_back(i);
            } else {
                uf.unite(pos.back(), i);
                pos.pop_back();
            }
        }
        int ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            ans += uf.root(i);
        }
        cout << ans << '\n';
    }
    return 0;
}