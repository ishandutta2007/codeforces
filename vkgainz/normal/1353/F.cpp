#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll grid[101][101];
ll best = 1e18;
ll ans(ll set){
    ll dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j] = 0;
    if(grid[0][0]>=set) dp[0][0] = grid[0][0]-set;
    else dp[0][0] = 1e18;
    for(int i=1;i<n;i++){
        if(grid[i][0]>=set) dp[i][0]=dp[i-1][0]+grid[i][0]-set;
        else dp[i][0] = 1e18;
    }
    for(int j=1;j<m;j++){
        if(grid[0][j]>=set) dp[0][j] = dp[0][j-1]+grid[0][j]-set;
        else dp[0][j] = 1e18;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j]>=set) dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j]-set;
            else dp[i][j] = 1e18;
        }
    }
    return dp[n-1][m-1];
}
void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            grid[i][j]-=(i+j);
        }
    }
    best = 1e18;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            best = min(best,ans(grid[i][j]));
        }
    }
    cout << best << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}