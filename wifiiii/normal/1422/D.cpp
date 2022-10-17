#include<bits/stdc++.h>

typedef long long ll;
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;

const int maxn = 100005;
int x[maxn], y[maxn];
struct edge {
    int v,w;
};
vector<edge> g[maxn];
ll dis[maxn], vis[maxn];
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int u) {
    memset(dis,0x3f,sizeof(dis));
    dis[u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = 1;
        for(edge e : g[cur.second]) {
            if(dis[e.v] > dis[cur.second] + e.w) {
                dis[e.v] = dis[cur.second] + e.w;
                q.push({dis[e.v], e.v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    for(int i=1;i<=m;++i) {
        cin>>x[i]>>y[i];
    }
    int s=m+1,t=m+2;
    x[s]=sx,y[s]=sy,x[t]=tx,y[t]=ty;
    vector<int> ord(m);
    iota(all(ord),1);
    sort(all(ord),[&](int i,int j){return x[i]<x[j];});
    for(int i=1;i<m;++i) {
        int w = min(abs(x[ord[i-1]] - x[ord[i]]), abs(y[ord[i-1]] - y[ord[i]]));
        g[ord[i-1]].push_back({ord[i], w});
        g[ord[i]].push_back({ord[i-1], w});
    }
    sort(all(ord),[&](int i,int j){return y[i]<y[j];});
    for(int i=1;i<m;++i) {
        int w = min(abs(x[ord[i-1]] - x[ord[i]]), abs(y[ord[i-1]] - y[ord[i]]));
        g[ord[i-1]].push_back({ord[i], w});
        g[ord[i]].push_back({ord[i-1], w});
    }
    for(int i=1;i<=m;++i) {
        int w = min(abs(x[i]-x[s]), abs(y[i]-y[s]));
        g[s].push_back({i, w});
        int w2 = abs(x[i]-x[t]) + abs(y[i]-y[t]);
        g[i].push_back({t, w2});
    }
    ll ans = abs(x[s]-x[t]) + abs(y[s]-y[t]);
    dijkstra(s);
    cout << min(ans, dis[t]) << endl;
}