#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,m,head[N],tot,ont[N];
struct Edge{int u,v,w,ans,id;}e[N];
struct pp{int nxt,to,val,bl;}g[N<<1];
void add(int u,int v,int w,int bl){g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,g[tot].bl=bl;head[u]=tot;}
bool cmp(Edge x,Edge y){return x.w<y.w;}
int pa[N];int find(int x){return x==pa[x]?x:(pa[x]=find(pa[x]));}
void kruskal(){
    memset(ont,0,sizeof(ont));
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            add(e[i].u,e[i].v,e[i].w,i);
            add(e[i].v,e[i].u,e[i].w,i);
            pa[fu]=fv;ont[i]=1;
        }
    }
}
int f[N][22],w[N][22],dep[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);f[v][0]=u,w[v][0]=g[i].val;
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int j=21;j>=0;j--)
        if(dep[f[u][j]]>=dep[v]) u=f[u][j];
    if(u==v) return u;
    for(int j=21;j>=0;j--)
        if(f[u][j]!=f[v][j]) u=f[u][j],v=f[v][j];
    return f[u][0];
}
int Val(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);int Ans=0;
    for(int j=21;j>=0;j--)
        if(dep[f[u][j]]>=dep[v]) Ans=max(w[u][j],Ans),u=f[u][j];
    if(u==v) return Ans;
    for(int j=21;j>=0;j--)
        if(f[u][j]!=f[v][j]) Ans=max(Ans,max(w[u][j],w[v][j])),u=f[u][j],v=f[v][j];
    Ans=max(Ans,max(w[u][0],w[v][0]));
    return Ans;
}
vector<int >p[N];
int num[N];
void dfs2(int u,int fa){
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        int ecp=num[g[i].val];
        dfs2(v,u);
        if(num[g[i].val]>ecp) e[g[i].bl].ans=2;
        else e[g[i].bl].ans=1;
    }
    for(int i=0;i<(int)p[u].size();i++){
        int x=p[u][i];
        if(x>0) num[x]++;
        else if(x<0) x=-x,num[x]-=2;
    }
}
bool cmpid(Edge x,Edge y){return x.id<y.id;}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);e[i].id=i;}
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++) pa[i]=i;
    kruskal();dfs(1,0);
    for(int j=1;j<=21;j++)
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1],w[i][j]=max(w[i][j-1],w[f[i][j-1]][j-1]);
    for(int i=1;i<=m;i++)
        if(!ont[i]){
            p[e[i].u].push_back(e[i].w);p[e[i].v].push_back(e[i].w);
            p[lca(e[i].u,e[i].v)].push_back(-e[i].w);
            if(e[i].w==Val(e[i].u,e[i].v)) e[i].ans=2;
            else e[i].ans=3;
        }
    dfs2(1,0);
    sort(e+1,e+m+1,cmpid);
    for(int i=1;i<=m;i++){
        if(e[i].ans==1) printf("any\n");
        else if(e[i].ans==2) printf("at least one\n");
        else if(e[i].ans==3) printf("none\n");
    }
    return 0;
}