#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> dp(2001, 1e9);
        dp[0] = 0;
        for(int x : a) {
            vector<int> ndp(2001, 1e9);
            for(int i = 0; i <= 2000; ++i) {
                if(dp[i] == 1e9) continue;
                if(x <= i) {
                    ndp[i - x] = min(ndp[i - x], dp[i] + x);
                } else {
                    ndp[0] = min(ndp[0], dp[i] + x);
                }
                if(x <= dp[i]) {
                    if(i + x <= 2000) ndp[i + x] = min(ndp[i + x], dp[i] - x);
                } else {
                    if(i + x <= 2000) ndp[i + x] = min(ndp[i + x], 0);
                }
            }
            dp = ndp;
        }
        int ans = 1e9;
        for(int i = 0; i <= 2000; ++i) {
            ans = min(ans, i + dp[i]);
        }
        cout << ans << '\n';
    }
}