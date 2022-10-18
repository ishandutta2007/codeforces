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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        string ans = "NO";
        for (int x = 0; x < 5; x++) {
            for (int y = x + 1; y < 5; y++) {
                vector<int> b(3);
                for (int i = 0; i < n; i++) {
                    int c = 0;
                    if (a[i][x]) {
                        c++;
                    }
                    if (a[i][y]) {
                        c += 2;
                    }
                    if (c == 0) {
                        b[0] = b[1] = b[2] = n;
                        break;
                    } else {
                        b[c - 1]++;
                    }
                }
                if (b[0] <= n / 2 && b[1] <= n / 2) {
                    ans = "YES";
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}