#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

const int maxn = 200005;
struct edge {
    int v,w;
};
vector<edge> g[maxn];
int dis[maxn], vis[maxn], cnt[maxn];
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
                cnt[e.v] = 1;
            } else if(dis[e.v] == dis[cur.second] + e.w) cnt[e.v]+=1;
        }
    }
}
int a[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ij {
        int u,v;
        cin>>u>>v;
        g[v].push_back({u,1});
    };
    int k;
    cin>>k;
    for(int i=1;i<=k;++i) cin>>a[i];
    dijkstra(a[k]);
    int x = 0, y = 0;
    for(int i=1;i<k;++i) {
        if(dis[a[i]] - 1 != dis[a[i+1]]) {
            x += 1;
            y += 1;
        } else if(cnt[a[i]] > 1) y++;
    }
    cout << x << " " << y << endl;
}