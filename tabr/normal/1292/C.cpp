#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

vector<vector<int>> g, par, sub;
vector<vector<ll>> dp;
int root;

void dfs(int u) {  //calc par and sub
    sub[root][u] = 1;
    for (int v : g[u]) {
        if (v == par[root][u]) continue;
        par[root][v] = u;
        dfs(v);
        sub[root][u] += sub[root][v];
    }
}

ll dpdfs(int u, int v) {
    if (u == v) return 0;
    if (dp[u][v] != -1) return dp[u][v];
    return dp[u][v] = (ll)sub[u][v] * sub[v][u] + max(dpdfs(u, par[u][v]), dpdfs(par[v][u], v));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    g.assign(n, vector<int>());
    par.assign(n, vector<int>(n, -1));
    sub.assign(n, vector<int>(n, -1));
    dp.assign(n, vector<ll>(n, -1));
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    rep(i, 0, n) {
        root = i;
        dfs(i);
    }

    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n) {
        ans = max(ans, dpdfs(i, j));
    }
    cout << ans << endl;
    return 0;
}