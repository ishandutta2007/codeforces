// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=1000007;
const int K=18;
mt19937 rng(time(NULL));


int n,m;
int par[N];
vi g[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}

bool unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return 0;
    par[pu]=pv;
    return 1;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>m;
    rep1(i,n+m) par[i]=i;
    vector<pii> edges;
    rep1(i,n) {
        int k;
        cin>>k;
        if (k==1){
            int u;
            cin>>u;
            g[u].pb(m+i), g[m+1].pb(u);
            edges.pb({u,m+1});
        }
        else{
            int u,v;
            cin>>u>>v;
            g[u].pb(v), g[v].pb(u);
            edges.pb({u,v});
        }
    }
    vi ans;
    rep(i,n){
        auto [x,y]=edges[i];
        // cerr<<x<<" "<<y<<endl;
        if (unite(x,y)) ans.pb(i);
    } 
    int ret=1;
    rep(i,sz(ans)) ret=ret*2%mod;
    cout<<ret<<" "<<sz(ans)<<"\n";
    for (auto c:ans) cout<<c+1<<" ";
    return 0;
}


/*
10

*/