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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> g(n);
    vector<int> ans = c;
    dsu uf(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        if (c[x]) {
            ans[y] = 1;
        }
        if (c[y]) {
            ans[x] = 1;
        }
        if (c[x] + c[y] == 0) {
            uf.unite(x, y);
        }
    }
    dsu uf2(n);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (j < i) {
                continue;
            }
            if (c[i] == 0 && c[j] == 0 && ans[i] == 0 && ans[j] == 0) {
                uf2.unite(i, j);
            }
        }
    }
    vector<int> cnt2(n);
    for (int i = 0; i < n; i++) {
        if (c[i] == 0 && ans[i] == 1) {
            for (int j : g[i]) {
                cnt2[uf2.get(j)]++;
            }
        }
    }
    int found = 0;
    {
        vector<int> dp(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            vector<int> x(3);
            dp[v] = c[v];
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                dfs(to, v);
                dp[v] = min(2, max(dp[v], dp[to] + c[v]));
                x[dp[to]]++;
            }
            if (c[v]) {
                if (x[1] + x[2] >= 2) {
                    found = 1;
                }
            } else {
                if (x[2] == 1 && x[1] >= 1) {
                    found = 1;
                } else if (x[2] > 1) {
                    found = 1;
                }
            }
        };
        dfs(0, -1);
    }
    if (!found) {
        vector<int> dp(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            vector<int> x(3);
            int y = 0;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                dfs(to, v);
                x[dp[to]]++;
                y += c[to];
            }
            if (c[v]) {
                if (x[2] >= 1) {
                    found = 1;
                }
            } else {
                if (x[2] == 1 && x[1] >= 1) {
                    found = 1;
                } else if (x[2] > 1) {
                    found = 1;
                } else if (x[1] >= 3 && y >= 1) {
                    found = 1;
                }
            }
            if (x[2] >= 1) {
                dp[v] = 2;
            } else if (x[1] >= 1) {
                dp[v] = 1;
                if (x[1] >= 2 && y >= 1) {
                    dp[v] = 2;
                }
            }
        };
        dfs(0, -1);
    }
    if (found) {
        ans = vector<int>(n, 1);
    } else {
        vector<int> cnt(n);
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                d++;
                for (int j : g[i]) {
                    if (!c[j]) {
                        cnt[uf.get(j)]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                continue;
            }
            if (cnt[uf.get(i)] != d) {
                ans[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                continue;
            }
            if (cnt2[uf2.get(i)] != d) {
                ans[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}