#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
long double dp[maxn][maxn][maxn], f[maxn];
int a[maxn], p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int t = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], t += a[i];
    f[0] = 1;
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * 1ll * i;
    cin >> p;
    if (t <= p) return cout << n << endl, 0;
    long double ans = 0;
    for (int now = 1; now <= n; ++now) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int k = 0; k <= p; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (i != now && k - a[i] >= 0 && j > 0) dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int k = p; k + a[now] > p; --k) ans += dp[n][j][k] * f[j] * f[n - j - 1] * j;
        }
    }
    cout << fixed << setprecision(20) << ans / f[n] << endl;
    return 0;
}