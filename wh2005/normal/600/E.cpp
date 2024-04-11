#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;
int n,c[N],head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int siz[N],son[N];
void pre_dfs(int u,int fa){
    siz[u]=1,son[u]=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        pre_dfs(v,u);siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
int a[N];ll mx,sum,ans[N];
void solve(int u,int fa){
    a[c[u]]--;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        solve(v,u);
    }
}
void DFS(int u,int fa,int p){
    a[c[u]]++;
    if(a[c[u]]>mx) mx=a[c[u]],sum=c[u];
    else if(a[c[u]]==mx) sum+=c[u];
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||v==p) continue; 
        DFS(v,u,p);
    }
}
void dfs(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||v==son[u]) continue;
        dfs(v,u);solve(v,u);mx=0,sum=0;
    }
    if(son[u]) dfs(son[u],u);
    DFS(u,fa,son[u]);
    ans[u]=sum;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    pre_dfs(1,0);
    memset(a,0,sizeof(a));mx=0,sum=0;
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}