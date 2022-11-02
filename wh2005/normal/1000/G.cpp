#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+9;
int n,m,head[N],tot;ll a[N];
struct pp{int nxt,to;ll val;}g[N<<1];
void add(int u,int v,ll w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,head[u]=tot;
}
int f[N][22],dep[N];ll dp[N],up[N],w[N][22],Dp[N][22];
void dfs(int u,int fa){
    f[u][0]=fa,dep[u]=dep[fa]+1;
    int cnt=0;dp[u]=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);cnt++;dp[u]+=max(dp[v]-2ll*g[i].val,0ll);
    }
    if(!cnt){dp[u]=a[u];return ;}
    dp[u]+=a[u];return ;
}
void dfs2(int u,int fa){
    Dp[u][0]=dp[u];
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        up[v]=max(up[u]+dp[u]-max(dp[v]-2*g[i].val,0ll)-2*g[i].val,0ll);
        w[v][0]=max(dp[v]-2*g[i].val,0ll)+g[i].val;dfs2(v,u); 
    }
}
ll lca(int u,int v){
    if(u==v) return dp[u]+up[u];
    ll ans=0;
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=21;i>=0;i--)
        if(dep[f[u][i]]>=dep[v]){
            ans+=Dp[u][i];ans-=w[u][i];
            u=f[u][i];
        }
    if(u==v){
        ans+=up[u];ans+=dp[u];
        return ans;
    }
    for(int i=21;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            ans+=Dp[u][i];ans-=w[u][i];
            ans+=Dp[v][i];ans-=w[v][i];
            u=f[u][i],v=f[v][i];
        }
    }
    ans+=dp[u];ans+=dp[v];ans-=w[u][0],ans-=w[v][0];
    ans+=Dp[f[u][0]][0];ans+=up[f[u][0]];
    return ans;
}
signed main(){
    memset(head,-1,sizeof(head));tot=0;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v,w;scanf("%d%d%lld",&u,&v,&w);add(u,v,w);add(v,u,w);
    }
    dep[0]=0;dfs(1,0);dfs2(1,0);
    for(int j=1;j<=21;j++) 
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1],w[i][j]=w[i][j-1]+w[f[i][j-1]][j-1];
    for(int j=1;j<=21;j++)
        for(int i=1;i<=n;i++) Dp[i][j]=Dp[i][j-1]+Dp[f[i][j-1]][j-1];
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        printf("%lld\n",lca(u,v));
    }
    return 0;
}
//(x,y)(x,y)
//dfs
//
//uu
//dp[u]=\sum{max(dp[v]-2*g[i].val,0)}+a[u];