#include<bits/stdc++.h>
using namespace std;
#define db double
const int N = 100009;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int siz[N];
void dfs(int u){
    siz[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v);siz[u]+=siz[v];
    }
}
db f[N];
void Dfs(int u,int fa){
    if(fa) f[u]=f[fa]+((siz[fa]-1-siz[u])*1.0)/2.0+1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;Dfs(v,u);
    }
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){int x;scanf("%d",&x);add(x,i);}
    memset(siz,0,sizeof(siz));dfs(1);
    f[1]=1.0;Dfs(1,0);
    for(int i=1;i<=n;i++) printf("%lf ",f[i]);
    return 0;
}