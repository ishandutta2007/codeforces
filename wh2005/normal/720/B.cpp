#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,m,head[N],tot;
struct pp{int nxt,to,c;}g[N];
void add(int u,int v,int w){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].c=w,head[u]=tot;
}
vector<int >dcc[N];
int cnt,low[N],dfn[N],num,s[N],top,siz[N];
void tarjan(int u){
    dfn[u]=low[u]=++num,s[++top]=u;int flag=0;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
            if(low[v]>=dfn[u]){
                ++cnt;siz[cnt]=1;
                do{
                    dcc[cnt].push_back(s[top]);siz[cnt]++;
                }while(s[top--]!=v);
                dcc[cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int hd[N],cur[N];
struct Edge{int nxt,to,val;}G[N];
void Add(int u,int v,int w){
    G[++tot].nxt=hd[u],G[tot].to=v,G[tot].val=w,hd[u]=tot;
}
void inAdd(int u,int v,int w){Add(u,v,w);Add(v,u,0);return ;}
int vis[N],S,T;
void dfs(int u,int fa,int id){
    vis[u]=2;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;
        if(vis[v]){
            inAdd(g[i].c,id+m,1);
            if(vis[v]==1) dfs(v,u,id);
        }
    }
}
int dep[N];
int bfs(){
    for(int i=0;i<=T;i++) dep[i]=0;
    queue<int>q;dep[S]=1;q.push(S); 
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=hd[u];i!=-1;i=G[i].nxt){
            int v=G[i].to;
            if(G[i].val&&!dep[v]){dep[v]=dep[u]+1;q.push(v);}
        }
    }
    return dep[T];
}
int Dinic(int u,int flow){
    if(u==T) return flow;
    int ct=0;
    for(int &i=cur[u];i!=-1;i=G[i].nxt){
        int v=G[i].to;
        if(G[i].val&&dep[v]==dep[u]+1){
            int res=Dinic(v,min(flow,G[i].val));
            G[i].val-=res,G[i^1].val+=res;
            ct+=res,flow-=res;
        }
        if(!flow) break;
    }
    if(!ct) dep[u]=0;
    return ct;
}
int mxflow(){
    int ans=0;
    while(bfs()){
        for(int i=0;i<=T;i++) cur[i]=hd[i];
        ans+=Dinic(S,1e9);
    }
    return ans;
}
int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);add(u,v,w);add(v,u,w);
    }
    top=0,cnt=0,num=0;
    tarjan(1);tot=-1;
    memset(hd,-1,sizeof(hd));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<dcc[i].size();j++) vis[dcc[i][j]]=1;
        dfs(dcc[i][0],0,i);
        for(int j=0;j<dcc[i].size();j++) vis[dcc[i][j]]=0;
    }
    S=0,T=m+cnt+1;
    for(int i=1;i<=m;i++) inAdd(S,i,1);
    for(int i=1;i<=cnt;i++) inAdd(m+i,T,siz[i]-1);
    printf("%d\n",mxflow());
    return 0;
}