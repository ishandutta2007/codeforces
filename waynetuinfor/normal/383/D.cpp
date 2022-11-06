#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxv = 10000 + 10, mod = 1e9 + 7;
int a[maxn], dp[2][maxv << 1];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    dp[0][maxv] = 1; int cur = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int j = maxv * 2 - a[i]; j >= 0; --j) dp[cur][j] = add(dp[cur][j], dp[cur ^ 1][j + a[i]]);
        for (int j = maxv * 2; j >= a[i]; --j) dp[cur][j] = add(dp[cur][j], dp[cur ^ 1][j - a[i]]);
        ans = add(ans, dp[cur][maxv]);
        dp[cur][maxv] = add(dp[cur][maxv], 1);
        cur ^= 1;
    }
    cout << ans << endl;
    return 0;
}