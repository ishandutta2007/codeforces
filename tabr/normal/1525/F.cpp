#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

struct matching {
    vector<vector<int>> g;
    vector<int> pa;
    vector<int> pb;
    vector<int> was;
    int n, m;
    int res;
    int iter;

    matching(int _n, int _m) : n(_n), m(_m) {
        pa.assign(n, -1);
        pb.assign(m, -1);
        was.resize(n);
        g.resize(n);
        res = 0;
        iter = 0;
    }

    void add(int from, int to) {
        g[from].emplace_back(to);
    }

    bool dfs(int v) {
        was[v] = iter;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        for (int u : g[v]) {
            if (was[pb[u]] != iter && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            iter++;
            int add = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    add++;
                }
            }
            if (add == 0) {
                break;
            }
            res += add;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    matching fg(n, n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        fg.add(x, y);
    }
    vector<long long> x(k), y(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }
    int c = n - fg.solve();  // max vertex cover
    long long inf = (long long)1e18;
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == -inf) {
                continue;
            }
            for (int nj = j; nj <= n; nj++) {
                dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + max(0LL, x[i] - y[i] * (nj - j)));
            }
        }
        for (int j = 0; j <= i + 1 - c; j++) {
            dp[i + 1][j] = -inf;
        }
    }
    vector<int> res;
    {
        int i = k;
        int j = n;
        while (j > 0 && dp[i][j - 1] != -inf) {
            j--;
        }
        while (i > 0) {
            res.emplace_back(0);
            for (int nj = j; nj >= 0; nj--) {
                if (dp[i][j] == dp[i - 1][nj] + max(0LL, x[i - 1] - y[i - 1] * (j - nj))) {
                    for (int l = 0; l < j - nj; l++) {
                        res.emplace_back(1);
                    }
                    i--;
                    j = nj;
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
    }
    debug(res);
    vector<int> a(n), b(n);
    c = n - c;
    for (int &i : res) {
        if (i == 0) {
            continue;
        }
        bool ok = false;
        for (int p = 0; p < n; p++) {
            if (a[p]) {
                continue;
            }
            a[p] = 1;
            matching t(n, n);
            for (int j = 0; j < n; j++) {
                for (int l : g[j]) {
                    if (!a[j] && !b[l]) {
                        t.add(j, l);
                    }
                }
            }
            if (t.solve() == c - 1) {
                c--;
                i = p + 1;
                ok = true;
                break;
            }
            a[p] = 0;
        }
        if (ok) {
            continue;
        }
        for (int p = 0; p < n; p++) {
            if (b[p]) {
                continue;
            }
            b[p] = 1;
            matching t(n, n);
            for (int j = 0; j < n; j++) {
                for (int l : g[j]) {
                    if (!a[j] && !b[l]) {
                        t.add(j, l);
                    }
                }
            }
            if (t.solve() == c - 1) {
                c--;
                i = -1 - p;
                ok = true;
                break;
            }
            b[p] = 0;
        }
        assert(ok);
    }
    cout << res.size() << '\n';
    for (int i : res) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}