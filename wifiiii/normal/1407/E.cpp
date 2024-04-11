#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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

struct edge {
    int v,w;
};
const int maxn = 500005;
vector<edge> g[maxn];
int vis[maxn], col[maxn], dis[maxn];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i) {
        int u,v,w;
        cin>>u>>v>>w;
//        g[u].push_back({v, w});
        if(w == 0) w = -1;
        g[v].push_back({u, w});
    }
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    dis[n] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(edge e : g[cur]) {
            int v = e.v;
            if(vis[v]) continue;
            else if(col[v] && e.w != col[v]) continue;
            else if(!col[v]) {col[v] = -e.w; continue;}
            vis[v] = 1;
            dis[v] = dis[cur] + 1;
            q.push(v);
        }
    }
    if(vis[1]) cout << dis[1] << endl;
    else cout << -1 << endl;
    for(int i=1;i<=n;++i) if(col[i] == 1) cout << 1; else cout << 0;
    cout << endl;
}