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
        int zeros = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                zeros++;
                a[i] = 1;
            }
        }
        pair<int, vector<int>> ans;
        ans.first = (int) 1e9;
        {
            dsu uf(n);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (a[i] & a[j]) {
                        uf.unite(i, j);
                    }
                }
            }
            if (uf.size(0) == n) {
                ans = min(ans, make_pair(0, a));
            }
        }
        for (int add : {1, -1}) {
            for (int i = 0; i < n; i++) {
                a[i] += add;
                dsu uf(n + 30);
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 30; k++) {
                        if (a[j] & (1 << k)) {
                            uf.unite(j, n + k);
                        }
                    }
                }
                bool ok = true;
                for (int j = 0; j < n; j++) {
                    if (!uf.same(0, j)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans = min(ans, make_pair(1, a));
                }
                a[i] -= add;
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            c = max(c, __builtin_ctz(a[i]));
        }
        if (c > 0) {
            vector<int> b;
            for (int i = 0; i < n; i++) {
                if (__builtin_ctz(a[i]) == c) {
                    b.emplace_back(i);
                }
            }
            if (b.size() >= 2) {
                a[b[0]]++;
                a[b[1]]--;
                ans = min(ans, make_pair(2, a));
            }
        }
        cout << ans.first + zeros << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans.second[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}