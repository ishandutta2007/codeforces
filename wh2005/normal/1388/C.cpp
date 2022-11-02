#include<bits/stdc++.h>
using namespace std;
const int N = 100009;
int t,n,m,p[N],h[N],head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int l[N],r[N],flag,c[N];
void dfs(int u,int fa){
    int sum=0,sumr=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);p[u]+=p[v];sum+=l[v],sumr+=r[v];
    }
    if((p[u]-h[u])%2==1) flag=0;
    l[u]=(p[u]+h[u])/2,r[u]=(p[u]-h[u])/2;
    if(l[u]<sum) flag=0;
    if(p[u]<h[u]||h[u]<(-p[u])) flag=0;
    if(sumr+c[u]<r[u]) flag=0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(head,-1,sizeof(head));tot=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]),c[i]=p[i];
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
        }
        flag=1;
        dfs(1,0);
        if(!flag){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}