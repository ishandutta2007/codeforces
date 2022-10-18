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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n, -1), b(n, -1);
    vector<int> c(n);
    vector<vector<int>> d(n + 1);
    for (int i = 0; i < n; i++) {
        if (i) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
        }
        if (s[i] == '0') {
            a[i] = i;
        }
        if (s[i] == '1') {
            b[i] = i;
        }
        c[i] = i - min(a[i], b[i]);
        d[c[i]].emplace_back(i);
    }
    vector<int> ans(n);
    ans[0] = n;
    dsu uf(n + 1);
    for (int i = 2; i <= n; i++) {
        for (auto j : d[i - 1]) {
            uf.unite(j, j + 1);
        }
        int p = i - 1;
        while (p < n) {
            int it = uf.get(p);
            if (it == n) {
                break;
            }
            ans[i - 1]++;
            p = it + i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}