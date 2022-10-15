// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=100007;
const int K=407;
int n,m,cnt;
int dp[N][K];
map<vi,int> st;
map<int,vi> rst;
vector<pii> g[N];
int to[K][K];
bool chd[N],done[N];
int col[N];
bool vis[N];
struct XORBasis{
    int n;
    vi s;
    XORBasis(int n):n(n),s(n,0){}
    bool add(int u){
        for (int i=n-1;i>-1;--i){
            if (u>>i&1) {
                if (s[i]) {u^=s[i]; continue;}
                s[i]=u;
                for (int j=i-1;j>-1;--j) {
                    if (!s[j]) continue;
                    if (s[i]>>j&1) s[i]^=s[j];
                }
                for (int j=i+1;j<n;++j) if (s[j]>>i&1) s[j]^=s[i];
                return 1;
            }
        }
        return 0;
    }
    int val(){
        vi fk;
        for (int i=n-1;i>-1;--i){
            if (s[i]) fk.pb(s[i]);
        }
        return st[fk];
    }
};
void dfs(vi vec,int all){
    rst[cnt]=vec, st[vec]=cnt++;
    int mx=(sz(vec)?vec.back():32);
    for (int i=1;i<mx;++i){
        int j=1;
        while (j<=i) j<<=1;
        j>>=1;
        if (j&all) continue;
        vec.pb(i);
        dfs(vec,all|i);
        vec.pop_back();
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n>>m;
    vi vec;
    dfs(vec,0);
    vis[0]=1;
    rep(i,cnt) {
        if (i) to[i][i]=-1;
        rep(j,i){
            XORBasis x(5);
            int fk=0;
            for (auto c:rst[i]) if (!x.add(c)) fk=-1;
            for (auto c:rst[j]) if (!x.add(c)) fk=-1;
            if (fk!=-1) to[i][j]=to[j][i]=x.val();
            else to[i][j]=to[j][i]=-1;
        }
    }
    rep(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        g[u].pb({v,w}), g[v].pb({u,w});
    }
    for (auto [v,w]:g[0]) chd[v]=1;
    int now=0;
    dp[0][0]=1;
    for (auto [v,w]:g[0]){
        if (done[v]) continue;
        bool fkkk=1;
        for (auto [c,_]:g[v]) {
            if (c==0) continue;
            if (!chd[c]) continue;
            vi cur; 
            XORBasis x(5);
            bool ok=1;
            vector<tuple<int,int,int>> edges;
            function<void(int,int)> dfs=[&](int u,int p){
                vis[u]=1, cur.pb(u);
                for (auto [v,w]:g[u]){
                    if (v==p) continue;
                    if (v==0) continue;
                    if (vis[v]) edges.emplace_back(min(u,v),max(u,v),w);
                    else{
                        col[v]=col[u]^w;
                        dfs(v,u);
                    }
                }
            };
            col[v]=w, dfs(v,0);
            sort(range(edges));
            edges.erase(unique(range(edges)),edges.end());
            for (auto [u,v,w]:edges){
                if ((col[u]^col[v])==w||!x.add(col[u]^col[v]^w)) ok=0;
            }
            for (auto c:cur) vis[c]=0;
            rep(i,sz(rst)) dp[now+1][i]=(dp[now+1][i]+dp[now][i])%mod;
            if (ok){
                int val=x.val();
                // cerr<<"hii1: "<<val<<endl;
                rep(i,sz(rst)){
                    if (to[i][val]!=-1) dp[now+1][to[i][val]]=(dp[now+1][to[i][val]]+2*dp[now][i])%mod;
                }
                int __=-1;
                for (auto [x,y]:g[c]) if (!x) __=y;
                if (col[c]!=__&&x.add(col[c]^__)){
                    int val=x.val();
                    rep(i,sz(rst)){
                        if (to[i][val]!=-1) dp[now+1][to[i][val]]=(dp[now+1][to[i][val]]+dp[now][i])%mod;
                    }
                }
            }
            now++;
            fkkk=0, done[c]=done[v]=1;
        }
        if (fkkk) {
            XORBasis x(5);
            vi cur;
            bool ok=1;
            vector<tuple<int,int,int>> edges;
            function<void(int,int)> dfs=[&](int u,int p){
                    // cerr<<"visit: "<<u<<endl;
                    vis[u]=1, cur.pb(u);
                    for (auto [v,w]:g[u]){
                        if (v==p) continue;
                        if (v==0) continue;
                        if (vis[v]) edges.emplace_back(min(u,v),max(u,v),w);
                        else{
                            col[v]=col[u]^w;
                            dfs(v,u);
                        }
                    }
            };
            col[v]=w; dfs(v,0);
            sort(range(edges));
            edges.erase(unique(range(edges)),edges.end());
            // cerr<<v<<": ";
            for (auto [u,v,w]:edges){
                // cerr<<(col[u]^col[v]^w)<<" ";
                if ((col[u]^col[v])==w||!x.add(col[u]^col[v]^w)) ok=0;
            }
            // cerr<<endl;
            for (auto c:cur) vis[c]=0;
            rep(i,sz(rst)) dp[now+1][i]=(dp[now+1][i]+dp[now][i])%mod;
            if (ok){
                int val=x.val();
                rep(i,sz(rst)){
                    if (to[i][val]!=-1) dp[now+1][to[i][val]]=(dp[now+1][to[i][val]]+dp[now][i])%mod;
                }
            }
            now++;
        }
    }
    int sum=0;
    rep(i,sz(rst)) sum=(sum+dp[now][i])%mod;
    cout<<sum;
    return 0;
}