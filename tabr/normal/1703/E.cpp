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
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        dsu uf(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                uf.unite(i * n + j, (n - 1 - j) * n + i);
            }
        }
        vector<vector<int>> b(2, vector<int>(n * n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[a[i][j]][uf.get(i * n + j)]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n * n; i++) {
            ans += min(b[0][i], b[1][i]);
        }
        cout << ans << '\n';
    }
    return 0;
}