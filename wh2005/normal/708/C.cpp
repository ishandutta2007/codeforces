#include<bits/stdc++.h>
using namespace std;
const int N = 400009;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int siz[N],son[N],c[N];
void dfs(int u,int fa){
    siz[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);siz[u]+=siz[v];
        if(siz[v]>n/2) son[u]=v;
        c[u]=max(c[u],c[v]);
    }
    if(siz[u]<=(n/2)) c[u]=max(c[u],siz[u]);
}
int flag[N],e[N];
void DFS(int u,int fa){
    int fi=0,se=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(c[v]>c[fi]) se=fi,fi=v;
        else if(c[v]>c[se]) se=v;
    }
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(n-siz[v]<=(n/2)) flag[v]=1,e[v]=n-siz[v];
        else{
            int p=e[u];if(fi!=v) p=max(c[fi],p);
            if(se!=v) p=max(c[se],p);
            if(n-siz[v]-p<=(n/2)) flag[v]=1;
            else flag[v]=0;
            e[v]=p;
        }
    }
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(siz[v]>(n/2)&&siz[v]-c[v]>(n/2)) flag[u]=0;
        DFS(v,u);
    }
}
int main(){
    memset(c,0,sizeof(c));
    memset(head,-1,sizeof(head));tot=0;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,0);flag[1]=1;DFS(1,0);
    for(int i=1;i<=n;i++) printf("%d ",flag[i]);
    return 0;
}