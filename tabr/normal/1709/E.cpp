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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dsu uf(n);
    vector<set<int>> dp(n);
    int ans = 0;
    function<void(int, int)> Dfs = [&](int v, int p) {
        vector<int> c;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            a[to] ^= a[v];
            Dfs(to, v);
            c.emplace_back(to);
        }
        if (c.empty()) {
            dp[v].emplace(a[v]);
            return;
        }
        sort(c.begin(), c.end(), [&](int i, int j) {
            return dp[i].size() > dp[j].size();
        });
        int bad = 0;
        int b = (p == -1 ? 0 : a[p]);
        for (int i = 1; i < (int) c.size(); i++) {
            for (auto x : dp[c[i]]) {
                if (dp[c[0]].count(x ^ a[v] ^ b)) {
                    bad = 1;
                }
            }
            for (auto x : dp[c[i]]) {
                dp[c[0]].emplace(x);
            }
        }
        if (dp[c[0]].count(b)) {
            bad = 1;
        }
        debug(v, a[v], dp[c[0]]);
        if (bad) {
            ans++;
        } else {
            dp[c[0]].emplace(a[v]);
            swap(dp[v], dp[c[0]]);
        }
    };
    Dfs(0, -1);
    cout << ans << '\n';
    return 0;
}