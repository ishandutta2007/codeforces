#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
const long long inf = 1e18 + 1;
long long dp1[maxn][maxn], dp2[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) dp1[i][j] = dp2[i][j] = inf;
    } 
    while (m--) {
        int l, r, c; cin >> l >> r >> c;
        dp1[l][r] = min(dp1[l][r], c * 1ll);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            dp1[i][j] = min(dp1[i][j], dp1[i - 1][j]);
            dp1[i][j] = min(dp1[i][j], dp1[i][j + 1]);
        }
    } 
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j]);
        }
    } 
    dp2[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp2[i][j] = dp2[i - 1][j];
            for (int k = 1; k <= i && j - k >= 0; ++k) dp2[i][j] = min(dp2[i][j], dp2[i - k][j - k] + dp1[i - k + 1][i]);
        }
    } 
    long long ans = inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j <= n; ++j) ans = min(ans, dp2[i][j]);
    }
    if (ans == inf) cout << "-1" << endl;
    else cout << ans << endl;
    return 0; 
}