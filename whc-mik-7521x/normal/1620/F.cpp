#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int dp[N][2][2],a[N],n,t;
pair<int,int>trans[N][2][2];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)for(int o=0;o<2;o++)for(int k=0;k<2;k++)dp[i][o][k]=1e9,trans[i][o][k]={-1,-1};
        dp[1][0][0]=dp[1][0][1]=-1e9;
        for(int i=2;i<=n;i++){
            for(int o=0;o<2;o++){
                for(int k=0;k<2;k++){
                    if(dp[i-1][o][k]==1e9)continue;
                    int x=o?dp[i-1][o][k]:(k?-a[i-1]:a[i-1]),y=o?(k?-a[i-1]:a[i-1]):dp[i-1][o][k];
                    if(x<=y)continue;
                    if(y<a[i]&&a[i]<x)if(x<dp[i][1][0])dp[i][1][0]=min(x,dp[i][1][0]),trans[i][1][0]={o,k};
                    if(a[i]>x)if(y<dp[i][0][0])dp[i][0][0]=min(dp[i][0][0],y),trans[i][0][0]={o,k};
                    if(y<-a[i]&&-a[i]<x)if(x<dp[i][1][1])dp[i][1][1]=min(x,dp[i][1][1]),trans[i][1][1]={o,k};
                    if(-a[i]>x)if(y<dp[i][0][1])dp[i][0][1]=min(y,dp[i][0][1]),trans[i][0][1]={o,k};
                }
            }
        }
        pair<int,int>kk={-1,-1},now;
        for(int i=0;i<2;i++)for(int o=0;o<2;o++)kk=max(kk,trans[n][i][o]);
        if(kk.first==-1&&n>1){puts("NO");continue;}
        vector<int>ans;
        for(int i=0;i<2;i++)for(int o=0;o<2;o++)if(trans[n][i][o]==kk)now={i,o};
        for(int i=n;i>=1;i--){
            ans.push_back(now.second?-a[i]:a[i]);
            if(i!=1){now=trans[i][now.first][now.second];}
        }
        reverse(ans.begin(),ans.end());
        puts("YES");
        for(int i:ans)printf("%d ",i);
        puts("");
    }
    return 0;
}