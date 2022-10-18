#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int n;
ll ans = 0;
vector<int> siz(200010);
vector<ll> dp(200010);
vector<vector<int>> g(200010);

int csize(int i, int p = -1) {
    siz[i] = 1;
    for (auto to : g[i])
        if (to != p)
            siz[i] += csize(to, i);
    return siz[i];
}

ll cdp(int i, int p = -1) {
    dp[i] = siz[i];
    for (auto to : g[i])
        if (to != p)
            dp[i] += cdp(to, i);
    return dp[i];
}
void dfs(int v, int p = -1) {
    ans = max(ans, dp[v]);
    for (auto to : g[v]) {
        if (to == p)
            continue;
        dp[v] -= dp[to];
        dp[v] -= siz[to];
        siz[v] -= siz[to];
        siz[to] += siz[v];
        dp[to] += siz[v];
        dp[to] += dp[v];

        dfs(to, v);

        dp[to] -= dp[v];
        dp[to] -= siz[v];
        siz[to] -= siz[v];
        siz[v] += siz[to];
        dp[v] += siz[to];
        dp[v] += dp[to];
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    csize(0);
    cdp(0);
    dfs(0);
    cout << ans << endl;
    return 0;
}