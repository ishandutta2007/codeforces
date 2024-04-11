#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 1005;
struct edge {
    int v,w;
};
vector<edge> g[maxn];
int dis[maxn][maxn], vis[maxn][maxn];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int u) {
    memset(vis[u],0,sizeof(vis[u]));
    memset(dis[u],0x3f,sizeof(dis[u]));
    dis[u][u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[u][cur.second]) continue;
        vis[u][cur.second] = 1;
        for(edge e : g[cur.second]) {
            if(dis[u][e.v] > dis[u][cur.second] + e.w) {
                dis[u][e.v] = dis[u][cur.second] + e.w;
                q.push({dis[u][e.v], e.v});
            }
        }
    }
}
pii e[maxn],es[maxn];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i) {
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v};
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;++i) dijkstra(i);
    int tot=0;
    for(int i=1;i<=k;++i) {
        int u,v;
        cin>>u>>v;
        es[i]={u,v};
        tot+=dis[u][v];
    }
    int ans=0;
    for(int i=1;i<=m;++i) {
        int u=e[i].first,v=e[i].second;
        int tmp=0;
        for(int j=1;j<=k;++j) {
            int x=es[j].first,y=es[j].second;
            int d=min(dis[u][x]+dis[v][y], dis[v][x]+dis[u][y]);
            if(d<dis[x][y]) tmp+=dis[x][y]-d;
        }
        ans=max(ans,tmp);
    }
    cout<<tot-ans<<endl;
}