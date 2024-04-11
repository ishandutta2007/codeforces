#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int MOD = 998244353;
 	if(k == 2) {
        int ans = 0LL;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans += a[j] - a[i];
                if(ans > MOD) ans -= MOD;
            }
        }
        if(ans < 0) ans += MOD;
        cout << ans << "\n";
        return 0;
    }
    int mx = 100000/(k - 1) + 5;
    int ans = 0LL;
    for(int i = 1; i <= mx; i++) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        vector<int> lst(n + 1);
        int l = 1;
        for(int j = 1; j <= n; j++) {
            while(l <= n && a[j - 1] - a[l - 1] >= i)
                ++l;
            lst[j] = l - 1;
        }
        fill(dp[0].begin(), dp[0].end(), 0LL);
        dp[0][0] = 1LL;
        for(int idx = 1; idx <= n; idx++) {
            for(int j = 0; j <= k; j++) {
                if(j == 0) dp[idx][j] = 1LL;
                else {
                    dp[idx][j] = dp[idx - 1][j] + dp[lst[idx]][j - 1];
                    if(dp[idx][j] > MOD) dp[idx][j] -= MOD;
                }
            }
        }
        ans += dp[n][k];
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}