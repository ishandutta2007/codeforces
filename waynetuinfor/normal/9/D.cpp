#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
long long dp[maxn][maxn][maxn];
bool v[maxn][maxn][maxn];

long long dfs(int l, int r, int h) {
    if (l < r && h == 1) return 0;
    if (l == r) {
        if (h == 1) return 1;
        return 0;
    }
    if (v[l][r][h]) return dp[l][r][h];
    dp[l][r][h] = dfs(l + 1, r, h - 1) + dfs(l, r - 1, h - 1);
    for (int m = l + 1; m < r; ++m) {
        dp[l][r][h] += dfs(l, m - 1, h - 1) * dfs(m + 1, r, h - 1);
        for (int th = h - 2; th >= 1; --th) dp[l][r][h] += dfs(l, m - 1, th) * dfs(m + 1, r, h - 1);
        for (int th = h - 2; th >= 1; --th) dp[l][r][h] += dfs(l, m - 1, h - 1) * dfs(m + 1, r, th);
    }
    v[l][r][h] = true;
    // cout << "dp[" << l << "][" << r << "][" << h << "] = " << dp[l][r][h] << endl;
    return dp[l][r][h];
}

int main() {
    int n, h; cin >> n >> h;
    long long ans = 0;
    for (int i = h; i <= n; ++i) {
        // cout << "i = " << i << " dp = " << dfs(1, n, i) << endl;
        ans += dfs(1, n, i);
    }
    cout << ans << endl;
    return 0;
}