#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
const int N = 3e5+9;
int n,m,head[N],tot,vis[N],pa[N];ll dep[N];
struct pp{int nxt,to;ll val;}g[N<<1];
void add(int u,int v,ll w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
int siz[N];
void dfs(int u,int fa){
    siz[u]=1;
    if(u==n) vis[u]=1;pa[u]=fa;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dep[v]=dep[u]+g[i].val;dfs(v,u);
        if(vis[v]) vis[u]=1;siz[u]+=siz[v];
    }
    return ;
}
int flag;ll mx,ans;
void dfs2(int u,int fa,int xj){
    if(vis[u]) xj=u;
    ans=max(ans,dep[u]-2ll*dep[xj]+mx);
    if(fa) mx=max(mx,dep[fa]);
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||vis[v]) continue;dfs2(v,u,xj);
    }
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||!vis[v]) continue;dfs2(v,u,xj);
    }
    mx=max(mx,dep[u]);
}
int main(){
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);add(u,v,w);add(v,u,w);
    }
    flag=0,dep[1]=0,dep[0]=0,mx=-inf,ans=-inf;dfs(1,0);dfs2(1,0,0);
    for(int i=1;i<=m;i++){
        ll x;scanf("%lld",&x);
        printf("%lld\n",dep[n]+min(ans+x,0ll));
    }
    return 0;
}