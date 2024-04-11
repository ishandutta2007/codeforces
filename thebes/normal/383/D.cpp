#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7, m = 1e4, sz = m+1;
int dp[2][2*sz], n, i, j, x, ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        memset(dp[i%2],0,sizeof(dp[i%2]));
        dp[(i+1)%2][sz]=(dp[(i+1)%2][sz]+1)%mod;
        for(j=-m;j<=m;j++){
            if(j+x<=m) dp[i%2][j+sz]=(dp[i%2][j+sz]+dp[(i+1)%2][j+sz+x])%mod;
            if(j-x>=-m) dp[i%2][j+sz]=(dp[i%2][j+sz]+dp[(i+1)%2][j+sz-x])%mod;
        }
        ans = (ans+dp[i%2][sz])%mod;
    }
    printf("%d\n",ans);
    return 0;
}