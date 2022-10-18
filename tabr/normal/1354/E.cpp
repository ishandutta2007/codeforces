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

    dsu(int _n)
        : n(_n) {
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    dsu uf(2 * n), u(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        u.unite(x, y);
        uf.unite(x, y + n);
        uf.unite(y, x + n);
    }
    for (int i = 0; i < n; i++) {
        if (uf.get(i) == uf.get(i + n)) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i++) {
        int j = u.get(i);
        if (uf.get(i) == uf.get(j)) {
            c[j]++;
        }
    }
    vector<vector<int>> s(n), t(n);
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            d[i] = u.sz[i] - c[i];
            for (int j = 0; j < n; j++) {
                if (u.get(i) != u.get(j)) {
                    continue;
                }
                if (uf.get(i) == uf.get(j)) {
                    s[i].emplace_back(j);
                } else {
                    t[i].emplace_back(j);
                }
            }
            assert(s[i].size() == c[i] && t[i].size() == d[i]);
            if (c[i] > d[i]) {
                swap(c[i], d[i]);
                swap(s[i], t[i]);
            }
        }
    }
    int mn = accumulate(c.begin(), c.end(), 0);
    if (mn > a[1]) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        for (int j = 0, dif = d[i] - c[i]; dif <= n; j++, dif++) {
            if (dp[i][j]) {
                dp[i + 1][dif] = true;
            }
        }
    }
    if (!dp[n][a[1] - mn]) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> wh(n);
    int cur = a[1] - mn;
    for (int i = n - 1; i >= 0; i--) {
        int dif = d[i] - c[i];
        if (cur - dif >= 0 && dp[i][cur - dif]) {
            cur -= dif;
            wh[i] = 1;
        }
    }
    assert(cur == 0);
    cout << "YES" << '\n';
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (wh[i] == 0) {
            for (int j : s[i]) {
                ans[j] = 2;
            }
        } else {
            for (int j : t[i]) {
                ans[j] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            if (a[0]) {
                ans[i] = 1;
                a[0]--;
            } else {
                ans[i] = 3;
                a[2]--;
            }
        } else {
            a[1]--;
        }
        cout << ans[i];
    }
    cout << '\n';
    assert(a[0] + a[1] + a[2] == 0);
    return 0;
}