#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[200001][2];
int main(){
    int n,c; cin >> n >> c;
    int a[n];
    int b[n];
    for(int i=0;i<n-1;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) cin >> b[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            dp[i][j] = 1000000000;
    dp[0][0] = 0;
    dp[0][1] = c;
    for(int i=1;i<n;i++){
        dp[i][1] = b[i-1]+min(dp[i-1][1],dp[i-1][0]+c);
        dp[i][0] = a[i-1]+min(dp[i-1][1],dp[i-1][0]);
    }
    for(int i=0;i<n;i++)
        cout << min(dp[i][0],dp[i][1]) << " ";
}