#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
int a[maxn], dp[2][maxn];

void dfs(int now, int fa) {
    dp[0][now] = 0; dp[1][now] = -inf;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        int d0 = dp[0][now], d1 = dp[1][now];
        dp[0][now] = max(d0 + dp[0][u], d1 + dp[1][u]);
        dp[1][now] = max(d1 + dp[0][u], d0 + dp[1][u]);
    }
    int d0 = dp[0][now], d1 = dp[1][now];
    dp[1][now] = max(dp[1][now], d0 + a[now]);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int p; cin >> p >> a[i];
        if (p == -1) root = i;
        else G[i].push_back(p), G[p].push_back(i);
    }
    dfs(root, 0);
    cout << max(dp[0][root], dp[1][root]) << endl;
    return 0;
}