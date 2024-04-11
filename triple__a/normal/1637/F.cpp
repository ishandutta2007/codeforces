// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
using namespace std;


// namespace std {
 
// template<class Fun>
// class y_combinator_result {
// 	Fun fun_;
// public:
// 	template<class T>
// 	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
// 	template<class ...Args>
// 	decltype(auto) operator()(Args &&...args) {
// 		return fun_(std::ref(*this), std::forward<Args>(args)...);
// 	}
// };
 
// template<class Fun>
// decltype(auto) y_combinator(Fun &&fun) {
// 	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
// }
 
// } // namespace std
 
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
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=300007;
const int K=10;

mt19937 rng(1234);
int n;
vi g[N];
int ans;
int h[N],a[N],p[N];
int vis[N];
int par[N],sz[N],in[N], emp[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}

void unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return;
    par[pu]=pv, sz[pv]+=sz[pu], h[pv]=max(h[pv],h[pu]), emp[pv]+=emp[pu], emp[pv]-=2;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
    }
    rep(i,n) par[i]=i;
    rep(i,n){
        if (sz(g[i])==1){
            sz[i]=1;
        }
        emp[i]=sz(g[i]);
    }
    rep(i,n) p[i]=i;
    sort(p,p+n,[&](int u,int v){return a[u]<a[v];});
    rep(i,n){
        int u=p[i];
        // cerr<<u<<" "<<ans<<endl;
        vi lst; 
        if (sz(g[u])==1) lst.pb(0);
        in[u]=1;
        int fked=0;
        for (auto c:g[u]){
            if (!in[c]) {fked++; continue;}
            int rt=fnd(c);
            if (emp[rt]>1) {fked++; unite(c,u); continue;}
            lst.pb(h[rt]);
            unite(c,u);
        }
        if (fked>=2) continue;
        sort(range(lst),[&](int u,int v){return u>v;});
        if (fked==1){
            assert(sz(lst));
            int rt=fnd(u);
            h[rt]=max(h[rt],a[u]);
            ans+=max(0ll,a[u]-lst[0]);
            continue;
        }
        assert(sz(lst)>1);
        ans+=max(0ll,a[u]-lst[0])+max(0ll,a[u]-lst[1]);
    }
    cout<<ans;
    return 0;
}

/*
6
1 2 3 4 5 6
1 2
1 3
1 4
1 6
4 5
*/