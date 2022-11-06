#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5, inf = 1e9;
int dp[maxn][maxn];
int x[maxn], p[maxn];
int s[maxn];
vector<int> u[maxn];

int main() {
    int a, n, m; scanf("%d %d %d", &a, &n, &m);
    while (n--) {
        int l, r; scanf("%d %d", &l, &r);
        ++l, ++r;
        ++s[l], --s[r];
    }
    ++a;
    for (int i = 1; i <= a; ++i) s[i] += s[i - 1];
    for (int i = 1; i <= m; ++i) scanf("%d %d", &x[i], &p[i]), ++x[i], u[x[i]].push_back(i);
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j <= m; ++j) if (dp[i][j] != inf) {
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            if (s[i + 1] == 0 || j > 0) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + p[j]);
            for (int k : u[i + 1]) dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + p[k]);
            if (s[i + 1] == 0) dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
        }
    }
    int ans = inf;
    for (int i = 0; i <= m; ++i) ans = min(ans, dp[a][i]);
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
    return 0;
}