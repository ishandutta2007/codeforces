#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int dp[MN][3], n, i, x;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        int a=x&2,b=x&1;
        if(a) dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        else dp[i][2]=1<<30;
        if(b) dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        else dp[i][1]=1<<30;
        dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
    }
    int ans = 1<<30;
    ans = min(dp[n][0],min(dp[n][1],dp[n][2]));
    printf("%d\n",ans);
    return 0;
}