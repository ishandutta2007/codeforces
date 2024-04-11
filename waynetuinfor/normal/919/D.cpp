#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
vector<int> G[maxn];
char c[maxn];
int v[maxn], dp[maxn];

bool dfs(int now) {
    v[now] = 1;
    bool ret = false;
    for (int u : G[now]) {
        if (v[u] == -1) ret |= dfs(u);
        else if (v[u] == 1) ret = true;
    }
    v[now] = 0;
    return ret;
}

int dfs2(int now, char ch) {
    if (~dp[now]) return dp[now];
    dp[now] = 0;
    for (int u : G[now]) {
        dp[now] = max(dp[now], dfs2(u, ch));
    }
    dp[now] += (ch == c[now]);
    return dp[now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    fill(v, v + maxn, -1);
    for (int i = 1; i <= n; ++i) if (v[i] == -1) {
        if (dfs(i)) return cout << "-1" << endl, 0;
    }
    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        fill(dp, dp + maxn, -1);
        for (int i = 1; i <= n; ++i) if (dp[i] == -1) ans = max(ans, dfs2(i, ch));
    }
    cout << ans << endl;
    return 0;
}