#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll ,int >
#define mcp make_pair
const int N = 1009;
const int M = 20009;
int n,m,l,s,t,head[N],tot,a[M],b[M];
struct pp{int nxt,to,val,flag,id;}g[M<<1];
void add(int u,int v,int w,int flag,int bl){
    g[++tot].nxt=head[u],g[tot].to=v,g[tot].val=w,g[tot].flag=flag,g[tot].id=bl,head[u]=tot;
}
ll dis[N];ll vis[N];
priority_queue<pi >q;
void dij(){
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    memset(dis,-1,sizeof(dis));dis[s]=0;
    q.push(mcp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;vis[u]=1;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;
            if(dis[v]==-1||dis[v]>dis[u]+g[i].val){
                dis[v]=dis[u]+g[i].val;
                q.push(mcp(-dis[v],v));
            }
        }
    }
}
ll len[N],dif,e[M];
void dij2(){
    memset(len,-1,sizeof(len));len[s]=0;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    q.push(mcp(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;vis[u]=1;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;
            if(g[i].flag&&dis[v]+dif>len[u]+e[g[i].id]){
                e[g[i].id]=dis[v]+dif-len[u];
                g[i].val=e[g[i].id],g[i^1].val=e[g[i].id];
            }
            if(len[v]==-1||len[v]>len[u]+g[i].val){
                len[v]=len[u]+g[i].val;
                q.push(mcp(-len[v],v));
            }
        }
    }
}
int main(){
    memset(head,-1,sizeof(head));tot=-1;
    scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);a[i]=u,b[i]=v,e[i]=w;
        add(u,v,w,(w==0),i);add(v,u,w,(w==0),i);
    }
    for(int i=1;i<=tot;i++)
        if(g[i].flag) g[i].val=1,e[g[i].id]=1;
    dij();
    if(dis[t]>l){printf("NO\n");return 0;}
    dif=l-dis[t];
    dij2();
    if(len[t]!=l){printf("NO\n");return 0;}
    printf("YES\n");
    for(int i=1;i<=m;i++){
        printf("%d %d %lld\n",a[i],b[i],e[i]);
    }
    return 0;
}