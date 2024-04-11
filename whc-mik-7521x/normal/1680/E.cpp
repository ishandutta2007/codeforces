#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,mp[2][N],n,dp[N][2];
int main(){
    scanf("%d",&t);
    while(t--){
        char s1[N],s2[N]; 
        scanf("%d%s%s",&n,s1+1,s2+1);
        for(int i=1;i<=n;i++)mp[0][i]=s1[i]=='*',mp[1][i]=s2[i]=='*',dp[i][0]=dp[i][1]=1e9;
        int i,o;
        for(i=1;i<=n;i++){
            if(mp[0][i]||mp[1][i])break;
        }
        for(o=n;o>=1;o--)if(mp[0][o]||mp[1][o])break;
        if(mp[0][i]&&mp[1][i])dp[i][0]=dp[i][1]=1;
        else if(mp[1][i])dp[i][1]=0,dp[i][0]=1;
        else dp[i][0]=0,dp[i][1]=1;
        for(i=i+1;i<=o;i++){
            if(!mp[1][i]&&!mp[0][i]){
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
            }
            if(!mp[1][i]&&mp[0][i]){
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=min(dp[i-1][0],dp[i-1][1])+2;
            }
            if(mp[1][i]&&!mp[0][i]){
                dp[i][0]=min(dp[i-1][1],dp[i-1][0])+2;
                dp[i][1]=dp[i-1][1]+1;
            }
            if(mp[1][i]&&mp[0][i]){
                dp[i][0]=dp[i][1]=min(dp[i-1][1],dp[i-1][0])+2;
            }
            dp[i][0]=min(dp[i][0],dp[i][1]+1);
            dp[i][1]=min(dp[i][1],dp[i][0]+1);
        }
        printf("%d\n",min(dp[o][0],dp[o][1]));
    }
    return  0;
}