#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    bool dp[701][701][2];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(j<i){
                dp[i][j][0] = 1;
                dp[i][j][1] = 1;
            }
        }
    }
    int g[701][701];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j] = __gcd(a[i-1],a[j-1]);
        }
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n;i++){
            int j = i+len-1;
            if(j>n) continue;
            for(int k=i;k<=j;k++){
                    
                if(i==1 || g[i-1][k]>1){
                    dp[i][j][0] = dp[i][j][0]||(dp[i][k-1][1]&&dp[k+1][j][0]);
                }
                if(j==n || g[k][j+1]>1){
                    dp[i][j][1] = dp[i][j][1]||(dp[i][k-1][1]&&dp[k+1][j][0]);
                }
            }
        }
    }
    if(dp[1][n][0] || dp[1][n][1]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}