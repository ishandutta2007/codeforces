#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int dp[N][1<<8],n,k,p[N],pos[N],sum[N][N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            sum[i][o]=1;
        }
        for(int o=1;o<i;o++){
            sum[i][pos[o]]=0;
        }
        for(int o=1;o<=n;o++)sum[i][o]+=sum[i][o-1];
    }
    memset(dp,63,sizeof dp);
    dp[1][(1<<k)-1]=0;
    for(int i=1;i<=n;i++){
        for(int o=(1<<k)-1;o>=0;o--){
            for(int j=1;j<=k;j++){
                if(o&(1<<(j-1))){
                    int now=i+j,val=sum[i][pos[now]];
                    if(now>n)continue;
                    for(int u=1;u<=k;u++){
                        if(u+i>n)continue;
                        if(pos[u+i]<pos[now]&&(!(o&(1<<(u-1)))))val--;
                    }
                    dp[i][o^(1<<(j-1))]=min(dp[i][o^(1<<(j-1))],dp[i][o]+val-1);
                }
            }
            // cout<<i<<' '<<o<<' '<<dp[i][o]<<endl;
            int kk=o&(-o);
            int val=sum[i][pos[i]];
            for(int u=1;u<=k;u++){
                if(u+i>n)continue;
                if(pos[u+i]<pos[i]&&(!(o&(1<<(u-1)))))val--;
            }
            if(!kk){
                dp[i+k+1][(1<<k)-1]=min( dp[i+k+1][(1<<k)-1],dp[i][o]+val-1);
                continue;
            }
            int ct=__lg(kk)+1;
            int msk=((o/kk)>>1)+(1<<k)-(1<<(k-ct));
            dp[i+ct][msk]=min(dp[i+ct][msk],dp[i][o]+val-1);
        }
    }
    cout<<dp[n+1][(1<<k)-1];
    return 0;
}