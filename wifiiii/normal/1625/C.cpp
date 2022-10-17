#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n + 1), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i]; a[n] = l;
    for(int i = 0; i < n; ++i) cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int p = i + 1; p <= n; ++p) {
                dp[p][j + 1] = min(dp[p][j + 1], dp[i][j] + (a[p] - a[i]) * b[i]);
            }
        }
    }
    int ans = 1e9;
    for(int i = n; i >= n - k; --i) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}