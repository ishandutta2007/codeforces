#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2009;
int n,pos,vis[N];
ll dis[N],g[N][N],mi;
void dij(int u){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    vis[u]=1;
    for(int i=1;i<=n;i++){
        dis[i]=g[u][i];
        for(int j=1;j<=n;j++) if(j!=i) dis[i]=min(dis[i],2*g[i][j]);
    }
    for(int i=1;i<n;i++){
        int u=-1;for(int j=1;j<=n;j++) if(!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
        vis[u]=1;for(int j=1;j<=n;j++) if(!vis[j]&&dis[j]>dis[u]+g[u][j]) dis[j]=dis[u]+g[u][j];
    }
    return ;
}
int main(){
    scanf("%d",&n);mi=1e10,pos=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            scanf("%lld",&g[i][j]);g[j][i]=g[i][j];
            if(g[i][j]<mi) mi=g[i][j],pos=i;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j) g[i][j]-=mi;
    dij(pos);
    for(int i=1;i<=n;i++){
        printf("%lld\n",mi*(n-1)+dis[i]);
    }
    return 0;
}