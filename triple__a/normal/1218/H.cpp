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
const int N=200007;
int n,a[N],d[N];
int sum[2*N];
vector<pii> q[N];
bool vis[N],cyc[N];
vi g[N];
vi lst[N];
int ans[N];

struct BIT{
    int n;
    vi C;
    BIT(int n):n(n),C(n+1,0){}
    int lowbit(int u){return u&(-u);}
    void update(int u,int w){
        for (int i=u;i<=n;i+=lowbit(i)) C[i]+=w;
    }
    int query(int u){
        assert(u<=n);
        int ans=0;
        for (int i=u;i>0;i-=lowbit(i)) ans+=C[i];
        return ans;
    }
};  
void dfs(int u){
    for (auto c:g[u]){
        dfs(c);
        d[u]=max(d[u],d[c]);
    }
    d[u]++;
}

void dfs2(int u,vi& lst){
    sort(range(g[u]),[&](int l,int r){return d[l]>d[r];});
    if (sz(g[u])) {
        dfs2(g[u][0],lst);
        rep1(i,sz(g[u])-1){
            vi fk;
            dfs2(g[u][i],fk);
            rep(j,sz(fk)) lst[j+sz(lst)-sz(fk)]+=fk[j];
        }
    }
    lst.pb(1);       
    if (!cyc[u]) 
    for (auto [m,_]:q[u]){
        if (m>=sz(lst)) ans[_]=0;
        else ans[_]=lst[sz(lst)-m-1];
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    rep(i,n) cin>>a[i], a[i]--;
    int _;
    cin>>_;
    rep(i,_){
        int u,v;
        cin>>u>>v;
        v--;
        q[v].pb({u,i});
    }
    rep(i,n){
        vi path;
        int now=i;
        while (!vis[now]){
            path.pb(now), vis[now]=1, now=a[now];
        }
        reverse(range(path));
        rep(k,sz(path)){
            if (path[k]==now) {
                rep(j,k+1) cyc[path[j]]=1;
                break;
            }
        }
    }
    rep(i,n){
        if (!cyc[i]) g[a[i]].pb(i);
    }
    rep(i,n){
        if (cyc[i]) dfs(i), dfs2(i,lst[i]), reverse(range(lst[i]));
    } 
    rep(i,n){
        if (cyc[i]){
            vi cycle;
            int now=i;
            while (1){
                cycle.pb(now), cyc[now]=0, now=a[now];
                if (now==i) break;
            } 
            int mn=INF, mx=-INF, m=sz(cycle);
            rep(j,m) mn=min(mn,-j), mx=max(mx,j+sz(lst[cycle[j]])-1);
            int L=mn/m-1, R=mx/m+1;
            {
            vector<BIT> sum(m,R-L+1);
            rep(j,m) {
                rep(k,sz(lst[cycle[j]])){
                    int cur=-j+k, md=(cur%m+m)%m, dv=(cur-md)/m;
                    sum[md].update(dv-L+1,lst[cycle[j]][k]);
                }
                for (auto [w,_]:q[cycle[j]]){
                    int cur=w-j, md=(cur%m+m)%m, dv=(cur-md)/m;
                    dv=min(dv,R);
                    ans[_]+=sum[md].query(dv-L+1); 
                }
            }
            }
            {
            vector<BIT> sum(m,R-L+1);
            for (int j=m-1;j>-1;--j){
                for (auto [w,_]:q[cycle[j]]){
                    int cur=w-j-m, md=(cur%m+m)%m, dv=(cur-md)/m;
                    dv=min(dv,R), dv=max(dv,L-1);
                    ans[_]+=sum[md].query(dv-L+1); 
                }
                rep(k,sz(lst[cycle[j]])){
                    int cur=-j+k, md=(cur%m+m)%m, dv=(cur-md)/m;
                    sum[md].update(dv-L+1,lst[cycle[j]][k]);
                }
            }
            }
        }
    }
    rep(i,_) cout<<ans[i]<<"\n";
    return 0;
}