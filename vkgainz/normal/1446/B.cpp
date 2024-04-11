#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main() {
    int n,m; cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int dp[n+1][m+1];
    dp[0][0] = 0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 0;
            if(a[i-1]==b[j-1]) dp[i][j] = max({dp[i][j], 2+dp[i-1][j-1],2});
            dp[i][j] = max({dp[i][j], -1+dp[i][j-1], -1+dp[i-1][j], -2+dp[i-1][j-1]});
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}