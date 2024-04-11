#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxk = 2000 + 10;
const long long inf = 1e18;
long long dp[maxn][maxk], a[maxn], b[maxk];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, p; cin >> n >> k >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];
    sort(a, a + n); sort(b, b + k);
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= k; ++j) dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int tr = 0;
        int ind = 0;
        while (ind <= k && dp[i - 1][ind] < dp[i - 1][tr]) ++ind;
        tr = ind;
        for (int j = 1; j <= k; ++j) {
            long long dis = abs(a[i - 1] - b[j - 1]) + abs(p - b[j - 1]);
            dp[i][j] = min(dp[i][j], max(dp[i - 1][tr], dis));
            if (dp[i - 1][j] < dp[i - 1][tr]) tr = j;
        }
    }
    long long ans = inf;
    for (int i = 0; i <= k; ++i) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}