#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int N = 10005;
const int M = 100005;
const int inf = 1e9;

int head[N],Next[M],ver[M],edge[M],cost[M],tot=1;
inline void add(int u,int v,int e,int c=0){
    ver[++tot]=v,Next[tot]=head[u],head[u]=tot,edge[tot]=e,cost[tot]=c;
    ver[++tot]=u,Next[tot]=head[v],head[v]=tot,edge[tot]=0,cost[tot]=-c;
}
int dis[N],vis[N],cur[N],S,T,ans;
queue<int> q;
bool spfa(){
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memcpy(cur,head,sizeof(head));
    q.push(T),dis[T]=0,vis[T]=1;
    while(!q.empty()){
        int u=q.front();q.pop(),vis[u]=0;
        for(int i=head[u];i;i=Next[i])
        if(edge[i^1]){
            int v=ver[i],c=cost[i];
            if(dis[v]<0||dis[v]>dis[u]-c){
                dis[v]=dis[u]-c;
                if(!vis[v]) vis[v]=1,q.push(v);
            }
        }
    }
    return ~dis[S];
}
int dfs(int u,int limit){
    if(!limit||u==T) return limit;
    int flow=0,f;vis[u]=1;
    for(int i=cur[u];i;cur[u]=i=Next[i]){
        int v=ver[i];
        if(dis[v]==dis[u]-cost[i]&&!vis[v]&&(f=dfs(v,min(limit,edge[i])))){
            flow+=f,limit-=f;
            edge[i]-=f,edge[i^1]+=f;
            ans-=f*cost[i];
            if(!limit) break;
        }
    }
    vis[u]=0;
    return flow;
}
int mp[105][105],win[105][105],n,cnt;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i!=j) mp[i][j]=2;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v] = 1;
        mp[v][u] = 0;
    }
    S=0,cnt=n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j){
            add(S,++cnt,1);
            if(mp[i][j]==0||mp[i][j]==2) add(cnt,i,1),win[j][i]=tot-1;
            if(mp[i][j]==1||mp[i][j]==2) add(cnt,j,1),win[i][j]=tot-1;
    }
    T=cnt+1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<n;++j)
            add(i,T,1,j);
    while(spfa()) dfs(S,inf);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            if(!win[i][j] || edge[win[i][j]]) cout<<0;
            else cout<<1;
        cout<<" "<<endl;
    }
}