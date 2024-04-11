#include <bits/stdc++.h>
using namespace std;

int t;
int solve(char a[],int x, int y,int m){
    int dp[m+2];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<=m+1;i++){
        dp[i] = 1000000000;
        if(a[i-2]=='.'){
            if(i>=3 && a[i-3]=='.'){
                dp[i] = min(dp[i],y+dp[i-2]);
            }
            dp[i] =min(dp[i],dp[i-1]+x);
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    return dp[m+1];
}
int main(){
    cin >> t;
    while(t--){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        char grid[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(grid[i],x,y,m);
        }
        cout << ans<< endl;
    }
}