#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 5e5+9;
const int M = (1<<23);
int n,head[N],tot,a[N];
char s[19];
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}

int sz[N],son[N];

void dfs(int u){
    sz[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v);sz[u]+=sz[v];if(!son[u]||sz[son[u]]<sz[v]) son[u]=v;
    }
    return ;
}

int t[M],tag,dep,f[N];

void clear(int u,int ms){
    t[ms^tag]=-inf;
    for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;clear(v,ms^(1<<a[v]));}
    return ;
}

void dfs2(int u,int ms,int d,int c){
    f[c]=max(f[c],d+t[ms^tag]+dep);
    for(int i=0;i<22;i++) f[c]=max(f[c],d+t[(1<<i)^ms^tag]+dep);
    for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;dfs2(v,ms^(1<<a[v]),d+1,c);}
    return ;
}

void dfs3(int u,int ms,int d){
    t[ms^tag]=max(t[ms^tag],d-dep);
    for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;dfs3(v,ms^(1<<a[v]),d+1);}
    return ;
}

void dfs1(int u){
    f[u]=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==son[u]) continue;dfs1(v);clear(v,0);tag=0,dep=0;f[u]=max(f[u],f[v]);
    }
    if(!son[u]){t[tag]=max(t[tag],0);return ;}
    dfs1(son[u]);tag^=(1<<a[son[u]]),dep+=1;
    t[tag]=max(-dep,t[tag]);
    f[u]=max(f[u],f[son[u]]);
    f[u]=max(f[u],t[tag]+dep);
    for(int i=0;i<22;i++){
        f[u]=max(f[u],t[(1<<i)^tag]+dep);
    }
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==son[u]) continue;dfs2(v,1<<a[v],1,u);dfs3(v,1<<a[v],1);
    }
    return ;
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){int fa;scanf("%d%s",&fa,s);a[i]=s[0]-'a';add(fa,i);}
    dfs(1);tag=0,dep=0;
    for(int i=0;i<(1<<22);i++) t[i]=-inf;
    dfs1(1);
    for(int i=1;i<=n;i++) printf("%d\n",f[i]);
    return 0;
}