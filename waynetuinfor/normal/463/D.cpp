#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[10][maxn], pos[10][maxn], n, k, dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j], pos[i][a[i][j]] = j;
    }
    fill(dp, dp + maxn, 1);
    for (int i = 1; i <= n; ++i) {
        int t = a[1][i];
        for (int j = 1; j <= n; ++j) {
            bool valid = true;
            for (int o = 1; o <= k; ++o) if (pos[o][j] >= pos[o][t]) valid = false;
            if (valid) dp[t] = max(dp[t], dp[j] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) cerr << dp[i] << ' ';
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}