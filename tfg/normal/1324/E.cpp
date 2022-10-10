#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(h, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < h; k++) {
            for(int j = a[i-1]-1; j <= a[i-1]; j++) {
                int m = (k - j + h) % h;
                if(dp[i-1][m] >= 0) {
                    dp[i][k] = max(dp[i][k], dp[i-1][m] + (l <= k && k <= r));
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++) {  
        ans = max(ans, dp[n][i]);
    }
    cout << ans << '\n';
}