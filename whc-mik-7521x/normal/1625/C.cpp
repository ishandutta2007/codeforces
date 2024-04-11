#include<bits/stdc++.h>
using namespace std;
const int N=505;
int dp[N][N],l,k,n,len[N],spe[N];
int main(){
    scanf("%d%d%d",&n,&l,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&len[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&spe[i]);
    }
    len[n+1]=l;
    if(n==1)return printf("%d",l*spe[1]),0;
    memset(dp,127,sizeof dp);
    dp[1][0]=0;
    for(int i=2;i<=n+1;i++){
        for(int o=0;o<i-1&&o<=k;o++){
            for(int j=1;j<i;j++){
                if(o-(i-j-1)>=0&&dp[j][o-(i-j-1)]<(int)1e9)dp[i][o]=min(dp[i][o],dp[j][o-(i-j-1)]+spe[j]*(len[i]-len[j]));
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<=k;i++)ans=min(ans,dp[n+1][i]);
    printf("%d",ans);
    return  0;
}