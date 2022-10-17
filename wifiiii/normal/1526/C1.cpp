#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1e18));
    dp[0][0] = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0];
        for(int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-1] + a[i-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i-1]);
            if(dp[i][j] >= 0) ans = max(ans, j);
        }
    }
    cout << ans << endl;
}