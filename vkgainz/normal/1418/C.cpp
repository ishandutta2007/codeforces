#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        int dp[n+1][2];
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        dp[n-1][0] = a[n-1];
        dp[n-1][1] = 0;
        for(int i=n-2;i>=0;i--){
            dp[i][0] = min(a[i]+a[i+1]+dp[i+2][1],a[i]+dp[i+1][1]);
            dp[i][1] = min(dp[i+1][0],dp[i+2][0]);
        }
        cout << dp[0][0] << endl;

    }
}