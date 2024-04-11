#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
int n,m,head[N],tot;
struct Edge{int u,v;}e[N];
struct pp{int nxt,to,id;}g[N<<1];
void add(int u,int v,int id){g[++tot].nxt=head[u],g[tot].to=v,g[tot].id=id,head[u]=tot;}
int pa[N],vis[N],f[N][21],dep[N],cut[N];
int find(int x){return pa[x]==x?x:(pa[x]=find(pa[x]));}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,f[u][0]=fa;vis[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int ji[N],flag;vector<int >ans;
void dfs2(int u,int fa){
    vis[u]=1;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        dfs2(v,u);ji[u]+=ji[v];
        if(ji[v]==flag) ans.push_back(g[i].id);
    }
    return ;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);e[i].u=u,e[i].v=v;
    }
    memset(cut,0,sizeof(cut));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) pa[i]=i;
    for(int i=1;i<=m;i++){
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu!=fv){pa[fu]=fv;add(e[i].u,e[i].v,i);add(e[i].v,e[i].u,i);cut[i]=1;}
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
    for(int j=1;j<=20;j++) 
        for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    flag=0;ans.clear();int wc=0;
    for(int i=1;i<=m;i++)
        if(!cut[i]){
            int p=lca(e[i].u,e[i].v);
            int len=dep[e[i].u]+dep[e[i].v]-2*dep[p]+1;
            if(len%2==1){
                flag++;wc=i;
                ji[e[i].u]+=1,ji[e[i].v]+=1,ji[p]-=2;
            }
            else ji[e[i].u]-=1,ji[e[i].v]-=1,ji[p]+=2;
        }
    if(!flag){
        printf("%d\n",m);
        for(int i=1;i<=m;i++) printf("%d ",i);puts("");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs2(i,0);
    if(flag==1) ans.push_back(wc);sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);puts("");
    return 0;
}
//