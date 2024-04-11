#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
double dp[maxn][maxn][maxn << 1];
int a[maxn];
double p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, l, k; cin >> n >> l >> k;
    for (int i = 1; i <= n; ++i) {
        int per; cin >> per;
        p[i] = (double)per / 100.0;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dp[0][0][maxn + k] = 1.0;
    for (int g = 1; g <= n; ++g) {
        for (int w = 0; w <= g; ++w) {
            for (int c = 0; c < maxn * 2; ++c) {
                if (a[g] != -1) {
                    int bac = min(maxn * 2 - 1, c + a[g]);
                    dp[g][w + 1][bac] += dp[g - 1][w][c] * p[g];
                } else {
                    if (c > 0) dp[g][w + 1][c - 1] += p[g] * dp[g - 1][w][c];
                }
                dp[g][w][c] += (1 - p[g]) * dp[g - 1][w][c];
            }
        }
    }
    double ans = 0.0;
    for (int i = 0; i < maxn; ++i) {
        for (int j = l; j <= n; ++j) ans += dp[n][j][i + maxn];
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}