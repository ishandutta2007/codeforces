#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 2e9 + 1;
int dp[maxn], a[maxn], n, k;

bool check(int c) {
    fill(dp, dp + maxn, inf);
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i], i - 1);
        for (int j = i + 1; j <= n; ++j) {
            if (j == n) dp[j] = min(dp[j], dp[i] + n - i);
            if (abs(a[j] - a[i]) <= (long long)(j - i) * (long long)c) dp[j] = min(dp[j], dp[i] + j - i - 1);
        }
    }
    return dp[n] <= k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long d = 1; while (d < inf) d <<= 1;
    int ans = inf;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}