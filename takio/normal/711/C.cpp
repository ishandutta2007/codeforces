#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const LL N = 110, INF = 1LL << 60;

LL dp[N][N][N];
int a[N], d[N][N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf ("%d", &d[i][j]);
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= n; k++) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= i; k++) if (dp[i][j][k] != INF) {
                if (a[i + 1]) {
                    dp[i + 1][a[i + 1]][k + (a[i + 1] != j)] = min (dp[i + 1][a[i + 1]][k + (a[i + 1] != j)], dp[i][j][k]);
                } else {
                    for (int l = 1; l <= m; l++) {
                        dp[i + 1][l][k + (l != j)] = min (dp[i + 1][l][k + (l != j)], dp[i][j][k] + d[i + 1][l]);
                    }
                }
            }
        }
    }
    LL res = INF;
    for (int i = 1; i <= m; i++) res = min (res, dp[n][i][k]);
    if (res == INF) cout << -1;
    else cout << res;
}