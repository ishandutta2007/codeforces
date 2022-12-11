#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int dp[N][2],n,mp[N][2],kk;
int main(){
    scanf("%d",&n);
    for(int o=0;o<=1;o++)for(int i=1;i<=n;i++)scanf("%1d",&mp[i][o]),kk+=mp[i][o];
    memset(dp,-63,sizeof dp);
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int o=0;o<=1;o++){
            dp[i+1][o]=max(dp[i+1][o],dp[i][o]+mp[i+1][o]);
			if(mp[i][o^1])dp[min(n+1,i+2)][o^1]=max(dp[min(n+1,i+2)][o^1],dp[i][o]+1+mp[i+1][o^1]+mp[i+2][o^1]);
        }
    }
    printf("%d",max(dp[n+1][0],dp[n+1][1]));
    return 0;
}