#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 20;
int n,m,g[N][N];ll dp[N][1<<N];
int lowbit(int x){return x&(-x);}

int main(){
    memset(g,0,sizeof(g));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);g[u][v]=1,g[v][u]=1;
    }
    memset(dp,0,sizeof(dp));ll ans=0;
    for(int i=1;i<=n;i++) dp[i][(1<<(i-1))]=1;
    for(int mask=1;mask<(1<<n);mask++){
        for(int i=1;i<=n;i++)
            if(dp[i][mask]){
                for(int j=1;j<=n;j++){
                    if(!g[i][j]) continue;
                    if((1<<(j-1))<lowbit(mask)) continue;
                    if(mask&(1<<(j-1))){
                        if((1<<(j-1))==lowbit(mask)){
                            ans+=dp[i][mask];
                        }
                    }
                    else{
                        dp[j][mask|(1<<(j-1))]+=dp[i][mask];
                    }
                }
            }
    }
    printf("%lld\n",(ans-m)/2ll);
    return 0;
}