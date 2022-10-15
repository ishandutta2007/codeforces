// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
using namespace std;
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
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
const double EPS=1e-9;
const int N=300007;
int n,m,k;
int sz[N],c[N],w[N];
vector<pii> g[N],gd[N];
vector<pii> edges;
bool is_bridges[N];
int par[N],low[N],dfn[N];
int cnt,sum[N];
bool vis[N],ve[N];
int dp[N],ans[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}

void unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return;
    par[pu]=pv, sz[pv]+=sz[pu], c[pv]+=c[pu];
}

void dfs(int u,int p,int _){
    vis[u]=1;
    dfn[u]=low[u]=cnt++;
    for (auto [v,idx]:g[u]){
        if (v==p) continue;
        if (vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
        else{
            dfs(v,u,idx);
            low[u]=min(low[u],low[v]);
        }
    }
    if (low[u]>dfn[p]) is_bridges[_]=1;
}

void dfs2(int u,int p){
    dp[u]=c[u];
    for (auto [v,idx]:gd[u]){
        if (v==p) continue;
        dfs2(v,u);
        sz[u]+=sz[v];
        if (sz[v]&&sz[v]<k) dp[u]+=max(0ll,dp[v]-w[idx]);
        else dp[u]+=dp[v];
    }
}

void dfs3(int u,int p){
    ans[u]=dp[u];
    for (auto [v,idx]:gd[u]){
        if (v==p) continue;
        if (sz[v]&&sz[v]<k) dp[u]-=max(0ll,dp[v]-w[idx]);
        else dp[u]-=dp[v];
        sz[u]-=sz[v];
        if (sz[u]&&sz[u]<k) dp[v]+=max(0ll,dp[u]-w[idx]);
        else dp[v]+=dp[u];
        sz[v]+=sz[u];
        dfs3(v,u);
        if (sz[u]&&sz[u]<k) dp[v]-=max(0ll,dp[u]-w[idx]);
        else dp[v]-=dp[u];
        sz[v]-=sz[u];
        if (sz[v]&&sz[v]<k) dp[u]+=max(0ll,dp[v]-w[idx]);
        else dp[u]+=dp[v];
        sz[u]+=sz[v];
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    rep(i,k){
        int w;
        cin>>w;
        w--;
        sz[w]++;
    } 
    rep(i,n) cin>>c[i];
    rep(i,m) cin>>w[i];
    rep(i,n) par[i]=i;
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edges.pb({u,v});
        g[u].pb({v,i}), g[v].pb({u,i});
    }
    dfs(0,0,-1);
    rep(i,m){
        if (is_bridges[i]) continue;
        unite(edges[i].F, edges[i].S);
    }   
    rep(i,m){
        if (is_bridges[i]){
            int u=fnd(edges[i].F), v=fnd(edges[i].S);
            gd[u].pb({v,i}), gd[v].pb({u,i});           
        }
    }
    int rt=fnd(0);
    dfs2(rt,rt);
    dfs3(rt,rt);
    rep(i,n) cout<<ans[fnd(i)]<<" ";
    return 0;
}