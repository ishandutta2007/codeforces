#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, maxk = 1000 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int dp[2][maxn][maxk], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int cur = 0;
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int m = 0; m <= k; ++m) {
            for (int j = 0; j <= i; ++j) {
                int know = m + (a[i] - a[i - 1]) * j;
                if (know > k) continue;
                dp[cur][j][know] = add(dp[cur][j][know], mul(dp[cur ^ 1][j][m], j + 1));
                if (j) dp[cur][j - 1][know] = add(dp[cur][j - 1][know], mul(dp[cur ^ 1][j][m], j));
                dp[cur][j + 1][know] = add(dp[cur][j + 1][know], dp[cur ^ 1][j][m]);
            }
        }
        cur ^= 1;
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) ans = add(ans, dp[cur ^ 1][0][i]);
    cout << ans << endl;
    return 0;
}