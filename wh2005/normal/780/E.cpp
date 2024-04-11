#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,m,k,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int vis[N],unit,st[N],top,bl[N];
void dfs(int u){
    vis[u]=1,st[++top]=u;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(vis[v]) continue;dfs(v);
        st[++top]=u;
    }
}

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    if(2*n%k==0) unit=2*n/k;else unit=2*n/k+1;
    memset(vis,0,sizeof(vis));top=0;
    dfs(1);
    for(int i=1;i<=top;i++) bl[i]=(i-1)/unit+1;
    for(int i=1;i<=k;i++){
        int l=(i-1)*unit+1,r=min(i*unit,top);
        if(r-l+1<=0){
            printf("1 1\n");
        }
        else{
            printf("%d ",r-l+1);
            for(int j=l;j<=r;j++) printf("%d ",st[j]);
            puts("");
        }
    }
    return 0;
}