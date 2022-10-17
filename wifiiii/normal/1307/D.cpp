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
typedef pair<int,int> pii;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define D(x...) cerr << "[" << #x << "] = ["; _print(x)

const int maxn = 200005;
vector<int> g[maxn];
int dis[2][maxn], vis[2][maxn];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int u, int p) {
    memset(dis[p],0x3f,sizeof(dis[p]));
    dis[p][u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        pii cur = q.top(); q.pop();
        if(vis[p][cur.second]) continue;
        vis[p][cur.second] = 1;
        for(int v : g[cur.second]) {
            if(dis[p][v] > dis[p][cur.second] + 1) {
                dis[p][v] = dis[p][cur.second] + 1;
                q.push({dis[p][v], v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(k);
    for(int i=0;i<k;++i) cin>>a[i];
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    int ans = dis[0][n];
    vector<pair<int,int>> v;
    for(int i=0;i<k;++i) {
        v.push_back({dis[0][a[i]], dis[1][a[i]]});
    }
//    D(ans);
    sort(all(v), [&](pair<int,int> i,pair<int,int> j) {
        return i.first < j.first || (i.first == j.first && i.second > j.second);
    });
    for(int i=1;i<k;++i) {
        if(v[i].second >= v[i-1].second) return cout << ans << endl, 0;
    }
//    D(v);
    int mx = 0;
    ans = 0;
    for(int i=0;i<k;++i) {
        if(i) ans = max(ans, mx + v[i].second + 1);
        mx = max(mx, v[i].first);
    }
    cout << min(ans, dis[0][n]) << endl;
}