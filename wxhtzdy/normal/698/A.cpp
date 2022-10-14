#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n],cnt=0,lst=0,k=0;
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int dp[n+2][3];
    for(int i=0;i<=n;i++)dp[i][0]=0,dp[i][1]=0,dp[i][2]=0;
    for(int i=0;i<n;i++){
        dp[i+1][0]=max(dp[i][0],max(dp[i][1],dp[i][2]));
        if(a[i]&1){
            dp[i+1][1]=max(dp[i][0]+1,dp[i][2]+1);
        }
        if(a[i]&2){
            dp[i+1][2]=max(dp[i][0]+1,dp[i][1]+1);
        }
    }
    printf("%i",n-max(dp[n][0],max(dp[n][1],dp[n][2])));
}