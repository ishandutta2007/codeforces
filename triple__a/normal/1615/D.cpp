// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>

#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=LLONG_MAX/4;
const int maxn=1000007;
const double EPS=1e-9;
int _;
int n,m;
vector<tuple<int,int,int>> edges;
vector<pii> g[maxn];
bool vis[maxn];
int col[maxn];
bool ok=1;

void dfs(int u,int c){
    if (vis[u]){
        if (c!=col[u]) ok=0;
        return;
    }
    col[u]=c, vis[u]=1;
    for (auto [x,w]:g[u]){
        dfs(x,c^w);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>_;
    while (_--){
        cin>>n>>m;
        edges.clear();
        rep1(i,n) g[i].clear(), vis[i]=0, col[i]=0;
        rep(i,n-1){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
            if (w==-1) continue;
            if (__builtin_popcount(w)&1) g[u].pb({v,1}), g[v].pb({u,1});
            else g[u].pb({v,0}), g[v].pb({u,0});
        }
        rep(i,m){
            int u,v,w;
            cin>>u>>v>>w;
            if (__builtin_popcount(w)&1) g[u].pb({v,1}), g[v].pb({u,1});
            else g[u].pb({v,0}), g[v].pb({u,0});
        }
        ok=1;
        rep1(i,n){
            if (vis[i]) continue;
            dfs(i,0);
        }
        if (!ok){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for (auto [u,v,w]:edges){
            if (w!=-1) cout<<u<<" "<<v<<" "<<w<<"\n";
            else cout<<u<<" "<<v<<" "<<(col[u]^col[v])<<"\n";
        }
    }
    return 0;
}

/*
5 3 
3 0 2 3 
3 3 0 1
4 0 1 3 4

2 0 3 1 4

1 0 3 4 
*/