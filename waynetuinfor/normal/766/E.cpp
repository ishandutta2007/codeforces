#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
int a[maxn];
long long dp[2][lg][maxn], ans[lg];
vector<int> G[maxn];

void dfs(int now, int fa) {
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        for (int i = 0; i < lg; ++i) {
            if (a[now] & (1 << i)) dp[1][i][now] += dp[0][i][u], dp[0][i][now] += dp[1][i][u];
            else dp[1][i][now] += dp[1][i][u], dp[0][i][now] += dp[0][i][u];
        }
    }
    vector<long long> tmp(lg, 0);
    for (int u : G[now]) if (u != fa) {
        for (int i = 0; i < lg; ++i) {
            if (a[now] & (1 << i)) dp[1][i][now] -= dp[0][i][u], dp[0][i][now] -= dp[1][i][u];
            else dp[1][i][now] -= dp[1][i][u], dp[0][i][now] -= dp[0][i][u];
            tmp[i] += dp[1][i][now] * dp[0][i][u] + dp[1][i][u] * dp[0][i][now];
            if (a[now] & (1 << i)) dp[1][i][now] += dp[0][i][u], dp[0][i][now] += dp[1][i][u];
            else dp[1][i][now] += dp[1][i][u], dp[0][i][now] += dp[0][i][u];
        }
    }
    for (int i = 0; i < lg; ++i) {
        if (a[now] & (1 << i)) ++dp[1][i][now];
        else ++dp[0][i][now];
    }
    for (int i = 0; i < lg; ++i) ans[i] += tmp[i] / 2;
    for (int i = 0; i < lg; ++i) ans[i] += dp[1][i][now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs(1, 0);
    long long sum = 0;
    for (int i = 0; i < lg; ++i) sum += (long long)(1 << i) * ans[i];
    cout << sum << endl;
    return 0;
}