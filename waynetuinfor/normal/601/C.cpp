#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxnm = 1e5 + 10;
double dp[2][maxnm];
int x[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    if (m == 1) return cout << fixed << setprecision(20) << 1.0 << endl, 0;
    int r = 0;
    for (int i = 1; i <= n; ++i) cin >> x[i], r += x[i];
    for (int i = 1; i <= n * m; ++i) {
        dp[0][i] = dp[0][i - 1];
        if (i != x[1] && i <= m) ++dp[0][i];
    }
    int cur = 1;
    for (int i = 2; i <= n; ++i) {
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int s = 1; s <= n * m; ++s) {
            dp[cur][s] = dp[cur ^ 1][s - 1] - dp[cur ^ 1][max(0, s - m - 1)]; 
            if (s - x[i] >= 1) dp[cur][s] -= dp[cur ^ 1][s - x[i]] - dp[cur ^ 1][s - x[i] - 1];
            dp[cur][s] /= (double)(m - 1);
            if (s) dp[cur][s] += dp[cur][s - 1];
        }
        cur ^= 1;
    }
    cout << fixed << setprecision(20) << dp[cur ^ 1][r - 1] + 1.0 << endl;
    return 0;
}