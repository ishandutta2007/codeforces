#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
vector<int> compress(vector<T> a) {
    vector<T> t = a;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    int n = (int)a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = (int)(lower_bound(t.begin(), t.end(), a[i]) - t.begin());
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a = compress(a);
    int m = *max_element(a.begin(), a.end()) + 1;
    vector<int> c(m);
    for (int i : a) {
        c[i]++;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    set<pair<int, int>> edges;
    vector<int> b(m);
    function<void(int, int)> eval = [&](int v, int p) {
        if (b[a[v]]) {
            edges.emplace(v, p);
        }
        b[a[v]]++;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            int before = b[a[v]];
            eval(to, v);
            if (before != b[a[v]]) {
                edges.emplace(v, to);
            }
        }
        if (b[a[v]] != c[a[v]]) {
            edges.emplace(v, p);
        }
    };
    eval(0, -1);
    debug(edges);
    vector<int> dp(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            dp[v] += dp[to];
            if (edges.count({to, v})) {
                dp[v]++;
            }
        }
    };
    dfs(0, -1);
    debug(dp);
    int ans = 0;
    function<void(int, int)> reroot = [&](int v, int p) {
        if (dp[v] == (int)edges.size()) {
            ans++;
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            int dpv = dp[v];
            int dpto = dp[to];
            dp[v] -= dp[to];
            if (edges.count({to, v})) {
                dp[v]--;
            }
            dp[to] += dp[v];
            if (edges.count({v, to})) {
                dp[to]++;
            }
            reroot(to, v);
            dp[v] = dpv;
            dp[to] = dpto;
        }
    };
    reroot(0, -1);
    cout << ans << '\n';
    return 0;
}