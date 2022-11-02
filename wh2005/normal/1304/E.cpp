#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int f[N][21],d[N];
void dfs(int u,int fa){
    f[u][0]=fa,d[u]=d[fa]+1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(d[u]<d[v]) swap(u,v);
    for(int i=20;i>=0;i--)
        if(d[f[u][i]]>=d[v]) u=f[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--)
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];       
}
int dist(int u,int v){
    return d[u]+d[v]-d[lca(u,v)]*2;
}
int q;
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    d[0]=0;dfs(1,0);
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x,y,a,b,k;scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int p=dist(a,b),t=dist(x,y);
        if(k-p>=0&&(k-p)%2==0) printf("YES\n");
        else if(k-dist(a,x)-1-dist(y,b)>=0&&(k-dist(a,x)-1-dist(y,b))%2==0) printf("YES\n");
        else if(k-dist(a,x)-t-dist(y,b)>=0&&(k-dist(a,x)-t-dist(y,b))%2==0) printf("YES\n");
        else if(k-dist(a,y)-1-dist(x,b)>=0&&(k-dist(a,y)-1-dist(x,b))%2==0) printf("YES\n");
        else if(k-dist(a,y)-t-dist(x,b)>=0&&(k-dist(a,y)-t-dist(x,b))%2==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}