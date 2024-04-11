#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        int t[n];
        for(int i=0;i<n;i++) cin >> t[i];
        sort(t,t+n);
        int dp[n+1][401];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=400;j++) dp[i][j] = 1000000000;
        }
        for(int j=0;j<=400;j++) dp[0][j] = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=400;j++) {
                for(int x=j-1;x>=0;x--) {
                    dp[i][j] = min(dp[i][j],dp[i-1][x]+abs(t[i-1]-j));
                }
            }
        }
        int ans = 100000000;
        for(int i=1;i<=400;i++) ans = min(ans,dp[n][i]);
        cout << ans << endl;
    }
}