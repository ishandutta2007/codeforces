#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n,m,head[N],tot,pre[N],prtot;
struct pp{int nxt,to;}g[N<<1],G[N<<1];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
void Add(int u,int v){
    G[++prtot].nxt=pre[u],G[tot].to=v,pre[u]=prtot;
}
int p[N],num,dis[N];
void bfs(int u){
    memset(dis,-1,sizeof(dis));
    queue<int >q;while(!q.empty()) q.pop();
    q.push(u);dis[u]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    memset(pre,-1,sizeof(pre));prtot=0;
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);add(v,u);Add(u,v);
    }
    scanf("%d",&num);
    for(int i=1;i<=num;i++) scanf("%d",&p[i]);
    bfs(p[num]);
    int mn=0,mx=0;
    for(int i=num-1;i>=1;i--){
        int u=p[i];
        if(dis[u]!=dis[p[i+1]]+1) mn++,mx++;
        else{
            for(int j=pre[u];j!=-1;j=G[j].nxt){
                int v=G[j].to;if(v==p[i+1]) continue;
                if(dis[u]==dis[v]+1){mx++;break;}
            }
        }
    }
    printf("%d %d\n",mn,mx);
    return 0;
}