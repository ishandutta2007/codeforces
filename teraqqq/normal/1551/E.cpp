#include <iostream>
#include <vector>

using namespace std;

const int N = 2000;

int t, n, k, dp[N+1][N+1], a[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j-1] + (a[i-1] == j ? 1 : 0), dp[i-1][j]);
        }
    }

    int ans = -1;
    for (int j = 0; j <= n; ++j) if (dp[n][j] >= k) ans = n - j;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) solve();
}