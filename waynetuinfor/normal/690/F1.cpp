#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
vector<int> G[maxn];
long long dp[2][maxn];

void dfs(int now, int fa) {
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        dp[1][now] += dp[1][u];
        dp[1][now] += dp[0][u];
        ++dp[0][now];
    }
    dp[1][now] += dp[0][now] * (dp[0][now] - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1][1] << endl;
    return 0;
}