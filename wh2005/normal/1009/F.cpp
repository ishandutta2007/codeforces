#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int dep[N],son[N],id[N],f[N],cnt;
void dfs1(int u,int fa){
    dep[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs1(v,u);
        dep[u]=max(dep[u],dep[v]+1);
        if(dep[v]>dep[son[u]]) son[u]=v;
    }
    return ;
}
void dfs2(int u,int fa){
    id[u]=++cnt;
    if(son[u]) dfs2(son[u],u);
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||son[u]==v) continue;
        dfs2(v,u);
    }
    return ;
}
int mxp[N];
void add(int x,int y,int u){
    f[x]+=y;
    if(f[x]>f[id[u]+mxp[u]]) mxp[u]=x-id[u];
    else if(f[x]==f[id[u]+mxp[u]]) mxp[u]=min(mxp[u],x-id[u]);
}
void dfs3(int u,int fa){
    if(son[u]) dfs3(son[u],u);
    else{mxp[u]=0;add(id[u],1,u);return ;}
    mxp[u]=mxp[son[u]]+1;add(id[u],1,u);
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa||son[u]==v) continue;dfs3(v,u);
        for(int j=id[v];j<=id[v]+dep[v]-1;j++) add(id[u]+j-id[v]+1,f[j],u);
    }
    return ;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    cnt=0;memset(dep,0,sizeof(dep));
    dfs1(1,0);dfs2(1,0);dfs3(1,0);
    for(int i=1;i<=n;i++) printf("%d\n",mxp[i]);
    return 0;
}