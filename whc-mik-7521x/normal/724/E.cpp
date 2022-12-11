#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long dp[2][N];
int n,c,p[N],s[N];
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    dp[1][0]=p[1];
    dp[1][1]=s[1];
    for(int i=2;i<=n;i++){
        dp[i&1][0]=dp[(i-1)&1][0]+p[i];
        for(int o=1;o<i;o++){
            dp[i&1][o]=min(dp[(i-1)&1][o]+p[i]+1ll*(o)*c,dp[(i-1)&1][o-1]+s[i]);
        }
        dp[i&1][i]=dp[(i-1)&1][i-1]+s[i];
    }
    long long ans=1e18;
    for(int i=0;i<=n;i++)ans=min(ans,dp[n&1][i]);
    printf("%lld",ans);
    return  0;
}