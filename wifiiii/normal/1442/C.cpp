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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

const int maxn = 200005;
struct edge {
    int v,f;
};
vector<edge> g[maxn];
int dis[maxn][30], vis[maxn][30];
pair<int,int> dis2[maxn][2];
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
priority_queue<piii,vector<piii>,greater<piii>> q2;
const int K = 30;
void dijkstra(int u) {
    memset(dis,0x3f,sizeof(dis));
    memset(dis2,0x3f,sizeof(dis2));
    dis[u][0] = 0;
    queue<piii> q;
    q.push({{0, 0}, u});
    while(!q.empty()) {
        piii cur = q.front(); q.pop();
        if(vis[cur.second][cur.first.second]) continue;
        vis[cur.second][cur.first.second] = 1;
        for(edge e : g[cur.second]) {
//            cout << cur.second << "->" << e.v << endl;
            if(e.f == cur.first.second % 2) {
                if(dis[e.v][cur.first.second] > dis[cur.second][cur.first.second] + 1) {
                    dis[e.v][cur.first.second] = dis[cur.second][cur.first.second] + 1;
                    q.push({{dis[e.v][cur.first.second], cur.first.second}, e.v});
                }
            } else {
//                cout << cur.second << " -> " << e.v << endl;
                if(cur.first.second + 1 < K && dis[e.v][cur.first.second + 1] > dis[cur.second][cur.first.second] + 1) {
                    dis[e.v][cur.first.second + 1] = dis[cur.second][cur.first.second] + 1;
                    q.push({{dis[e.v][cur.first.second + 1], cur.first.second + 1}, e.v});
                    if(cur.first.second + 1 == K - 1) {
                        pii nxt = {K, dis[cur.second][cur.first.second] + 1};
                        if(dis2[e.v][K&1] > nxt) {
                            dis2[e.v][K&1] = nxt;
                            q2.push({nxt, e.v});
                        }
                    }
                } else if(cur.first.second + 1 == K) {
                    pii nxt = {K, dis[cur.second][cur.first.second] + 1};
                    if(dis2[e.v][K&1] > nxt) {
                        dis2[e.v][K&1] = nxt;
                        q2.push({nxt, e.v});
//                        cout << e.v <<  " " << nxt.first << " " << nxt.second << endl;
                    }
                }
            }
        }
    }
}
const int mod = 998244353;

int vis2[maxn][2];
typedef pair<int,int> pii;
void dijkstra2(int u) {
    while(!q2.empty()) {
        piii cur = q2.top(); q2.pop();
        if(vis2[cur.second][cur.first.first&1]) continue;
        vis2[cur.second][cur.first.first&1] = 1;
//        cout << cur.second << " " << dis2[cur.second].first << " " << dis2[cur.second].second << endl;
        for(edge e : g[cur.second]) {
            if(e.f == (cur.first.first&1)) {
                pii nxt = pair<int,int>{dis2[cur.second][cur.first.first&1].first, dis2[cur.second][cur.first.first&1].second+1};
                if(dis2[e.v][cur.first.first&1] > nxt) {
                    dis2[e.v][cur.first.first&1] = nxt;
                    q2.push({dis2[e.v][cur.first.first&1], e.v});
                }
            } else {
                pii nxt = pair<int,int>{dis2[cur.second][cur.first.first&1].first+1, dis2[cur.second][cur.first.first&1].second+1};
                if(dis2[e.v][1^(cur.first.first&1)] > nxt) {
                    dis2[e.v][1^(cur.first.first&1)] = nxt;
                    q2.push({dis2[e.v][1^(cur.first.first&1)], e.v});
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    dijkstra(1);
    dijkstra2(1);
    ll ans=1e18;
    int ok=0;
    for(int i=0;i<K;++i) {
        if(dis[n][i] < 1e9) {
            ans = min(ans, dis[n][i] + (1ll<<i) - 1);
            ok = 1;
        }
        ans %= mod;
    }
    if(!ok) {
        auto tmp = min(dis2[n][0], dis2[n][1]);
        assert(tmp.first <= 1e9);
        int cnt = tmp.first, d = tmp.second;
//        cerr << " " << cnt << " " << d << endl;
        ans = 1;
        for(int i=1;i<=cnt;++i) ans = ans * 2 % mod;
        ans = ans - 1 + d;
        ans %= mod;
        if(ans < 0) ans += mod;
    }
    cout << ans << endl;
}