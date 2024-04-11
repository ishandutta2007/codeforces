#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000;
int n, s, m, k;
int l[maxn], r[maxn];
int a[maxn], b[maxn], c[maxn];
int dp[maxn][maxn], prv[maxn];
vector<int> seg[maxn];

bool check(int x) {
    for (int i = 1; i <= n; ++i) b[i] = (a[i] <= x);
    for (int i = 1; i <= n; ++i) c[i] = c[i - 1] + b[i];
    c[maxn - 1] = maxn;
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = max(dp[i][j], dp[prv[i] - 1][j - 1] + c[i] - c[prv[i] - 1]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return dp[n][m] >= k;
}
 
int main() {
    scanf("%d%d%d%d", &n, &s, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < s; ++i) scanf("%d%d", &l[i], &r[i]);
    for (int i = 1; i <= n; ++i) {
        prv[i] = maxn;
        for (int j = 0; j < s; ++j) {
            if (l[j] <= i && i <= r[j]) prv[i] = min(prv[i], l[j]);
        }
    }
    int ans = 1000000001, d = 31;
    while (d--) {
        int x = ans - (1 << d);
        if (x < 0) continue;
        if (check(x)) ans = x;
    }
    if (ans == 1000000001) ans = -1;
    printf("%d\n", ans);
    return 0;
}