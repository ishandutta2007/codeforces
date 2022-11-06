#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int dp[maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        dp[a[i]] = max(dp[a[i]], 1);
        for (int j = 2; a[i] * j < maxn; ++j) dp[a[i] * j] = max(dp[a[i] * j], dp[a[i]] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[a[i]]);
    cout << ans << endl;
    return 0;
}