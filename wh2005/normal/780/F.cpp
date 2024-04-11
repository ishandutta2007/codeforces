#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define bi bitset<N >
const int N = 509;
int n,m;
bi g[61][N],f[61][N],h[61][N],e[61][N];int vis[61][N];
ll pre[2][N],suf[2][N];


int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(!w) g[0][u][v]=1,h[0][v][u]=1;if(w) f[0][u][v]=1,e[0][v][u]=1;
    }
    int T=61;
    for(int t=1;t<T;t++){
        for(int i=1;i<=n;i++) vis[t-1][i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) vis[t-1][i]|=(f[t-1][i][j]|g[t-1][i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                bi x=g[t-1][i]&e[t-1][j];
                if(x.count()) g[t][i][j]=1,h[t][j][i]=1;
                x=f[t-1][i]&h[t-1][j];
                if(x.count()) f[t][i][j]=1,e[t][j][i]=1; 
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(g[T-1][i][j]==1){printf("-1\n");return 0;}
    ll sum=0;
    for(int t=0;t<T;t++){
        for(int i=1;i<=n;i++) suf[0][i]=pre[0][i],suf[1][i]=pre[1][i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(g[t][i][j]) pre[0][i]=(1ll<<t),sum=max(sum,pre[0][i]);
                if(f[t][i][j]) pre[1][i]=(1ll<<t);
                if(t){
                    if(g[t-1][i][j]) pre[0][i]=max(pre[0][i],(1ll<<(t-1))+suf[1][j]),sum=max(sum,pre[0][i]);
                    if(f[t-1][i][j]) pre[1][i]=max(pre[1][i],(1ll<<(t-1))+suf[0][j]);
                }
            }
    }
    if(sum>1e18) printf("-1\n");
    else printf("%lld\n",sum);
    return 0;
}