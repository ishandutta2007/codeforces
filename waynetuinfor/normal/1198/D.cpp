#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
char s[maxn][maxn];
int cnt[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int query(int u, int d, int l, int r) {
    return cnt[d][r] - cnt[u - 1][r] - cnt[d][l - 1] + cnt[u - 1][l - 1];
}

int dfs(int l, int r, int u, int d) {
    if (l > r || u > d) return 0;
    if (dp[l][r][u][d] >= 0) return dp[l][r][u][d];
    dp[l][r][u][d] = 1e9;
    for (int x = 1; x <= min(r - l + 1, d - u + 1); ++x) {
        int i = r - x + 1;
        int j = d - x + 1;
        int cost = x;
        if (query(j, d, i, r) == 0) {
            cost = 0;
        }
        dp[l][r][u][d] = min(dp[l][r][u][d], dfs(l, i - 1, u, d) + dfs(i, r, u, j - 1) + cost);
        dp[l][r][u][d] = min(dp[l][r][u][d], dfs(l, r, u, j - 1) + dfs(l, i - 1, j, d) + cost);
        /* if (i == r && j == d && s[d][r] != '#') {
            dp[l][r][u][d] = min(dp[l][r][u][d], dfs(l, i - 1, u, d) + dfs(i, r, u, j - 1));
            dp[l][r][u][d] = min(dp[l][r][u][d], dfs(l, r, u, j - 1) + dfs(l, i - 1, j, d));
        } */
    }
    return dp[l][r][u][d];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            if (s[i][j] == '#') cnt[i][j]++;
        }
    }
    printf("%d\n", dfs(1, n, 1, n));
}