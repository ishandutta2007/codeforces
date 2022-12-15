#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,mod=1e9+7;
int dp[MN], n, k, i, x, y;

int main(){
    scanf("%d%d",&n,&k);
    dp[0] = 1;
    for(i=1;i<=1e5;i++){
        dp[i] = dp[i-1];
        if(i>=k) dp[i]=(dp[i]+dp[i-k])%mod;
    }
    for(i=1;i<=1e5;i++)
        dp[i] = (dp[i]+dp[i-1])%mod;
    for(i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        int res = (dp[y]-dp[x-1]+mod)%mod;
        printf("%d\n",res);
    }
    return 0;
}