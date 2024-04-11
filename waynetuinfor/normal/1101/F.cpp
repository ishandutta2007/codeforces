#include <bits/stdc++.h>
using namespace std;

int dp[401][401][401], a[401];

void dvcq(int l, int r, int vl, int vr, int tl, int tr) {
    if (vl > vr) return;
    int m = (vl + vr + 1) >> 1;
    if (m == 0) return;
    int f = -1;
    // dp[l][r][m] = 2e9;
    for (int i = tl; i <= min(r - 1, tr); ++i) {
        if (max(dp[l][i][m - 1], a[r] - a[i]) < dp[l][r][m]) {
            dp[l][r][m] = max(dp[l][i][m - 1], a[r] - a[i]);
            f = i;
        }
    }
    dvcq(l, r, vl, m - 1, tl, f);
    dvcq(l, r, m + 1, vr, f, tr);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dp[i][j][k] = 2e9;
            }
        }
        dp[i][i][0] = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dvcq(i, j, 0, j - i, i, j);
            for (int k = 1; k < n; ++k) 
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1]);
        }
    } 
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int s, f, c, r; scanf("%d%d%d%d", &s, &f, &c, &r);
        --s, --f;
        // printf("dp[%d][%d][%d] = %d\n", s[i], f[i], min(n - 1, r[i] + 1), dp[s[i]][f[i]][min(n - 1, r[i] + 1)]);
        ans = max(ans, c * 1ll * dp[s][f][min(n - 1, r + 1)]);
    }
    printf("%lld\n", ans);
    return 0;
}