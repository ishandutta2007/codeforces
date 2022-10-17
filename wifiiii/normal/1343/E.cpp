#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

const int maxn = 200005;
struct edge {
    int v,w;
};
vector<edge> g[maxn];
ll dis[3][maxn];
int vis[3][maxn];
typedef pair<ll,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
int n;
void dijkstra(int u, int p) {
    memset(vis[p],0,sizeof(int)*(n+1));
    memset(dis[p],0x3f,sizeof(ll)*(n+1));
    dis[p][u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[p][cur.second]) continue;
        vis[p][cur.second] = 1;
        for(edge e : g[cur.second]) {
            if(dis[p][e.v] > dis[p][cur.second] + e.w) {
                dis[p][e.v] = dis[p][cur.second] + e.w;
                q.push({dis[p][e.v], e.v});
            }
        }
    }
}
ll w[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t -- ) {
        int m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        for(int i=1;i<=m;++i) cin>>w[i];
        ii g[i].clear();
        for(int i=1;i<=m;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back({v,1});
            g[v].push_back({u,1});
        }
        sort(w+1,w+1+m);
        for(int i=1;i<=m;++i) w[i]+=w[i-1];
        dijkstra(a, 0);
        dijkstra(b, 1);
        dijkstra(c, 2);
        ll ans = 1e18;
        for(int i=1;i<=n;++i) {
            ll a2 = dis[1][i], a1 = dis[0][i] + dis[2][i];
            if(a1 + a2 > m) continue;
            ans = min(ans, w[a2]+w[a2+a1]);
        }
        cout << ans << endl;
    }
}