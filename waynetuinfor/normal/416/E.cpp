#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10, inf = 1e9 + 1;
int dp[maxn][maxn], w[maxn][maxn], c[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    fill(&dp[0][0], &dp[maxn - 1][maxn - 1] + 1, inf);
    fill(&w[0][0], &w[maxn - 1][maxn - 1] + 1, inf);
    for (int i = 0; i < maxn; ++i) dp[i][i] = 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = dp[b][a] = c;
        w[a][b] = w[b][a] = c;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][j] == inf) continue;
                if (dp[i][k] + w[k][j] == dp[i][j]) ++c[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int cnt = 0;
            for (int k = 1; k <= n; ++k) {
                if (dp[i][k] + dp[k][j] == dp[i][j]) cnt += c[i][k];
            }
            cout << cnt << ' ';
        }
    }
    cout << endl;
    return 0;
}