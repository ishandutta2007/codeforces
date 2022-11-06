#include <bits/stdc++.h>
using namespace std;

const int maxn = 16;
vector<int> a[maxn];
int cost[maxn][maxn], ht[maxn][maxn];
int dp[maxn][maxn][1 << maxn];

int dfs(int h, int t, int s) {
    if (dp[h][t][s] >= 0) return dp[h][t][s];
    if (h == t && s == (1 << h)) return 1e9;
    dp[h][t][s] = 0;
    for (int x = 0; x < maxn; ++x) {
        if ((s >> x & 1) ^ 1) continue;
        if (x == t) continue;
        dp[h][t][s] = max(dp[h][t][s], min(dfs(h, x, s ^ (1 << t)), cost[x][t]));
    }
    return dp[h][t][s];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cost[i][j] = 1e9;
            for (int k = 0; k < m; ++k)
                cost[i][j] = min(cost[i][j], abs(a[i][k] - a[j][k]));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ht[i][j] = 1e9;
            for (int k = 0; k + 1 < m; ++k)
                ht[i][j] = min(ht[i][j], abs(a[i][k] - a[j][k + 1]));
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cd = min(ht[i][j], dfs(i, j, (1 << n) - 1));
            ans = max(ans, cd);
        }
    }
    printf("%d\n", ans);
    return 0;
}