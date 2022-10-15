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
int a[N];
vi lst[N],label[N];

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        vi lvl;
        int n,m;
        cin>>n>>m;
        rep(i,n) cin>>a[i];
        rep1(i,n) lst[i].clear(), label[i].clear();
        map<int,int> cnt;
        rep(i,n){
            cnt[a[i]]++;
        }
        unordered_map<int,pii> pos;
        for (auto [u,v]:cnt){
            lst[v].pb(u);
        }
        rep1(i,n) sort(range(lst[i]),[&](int u,int v){return u>v;}), label[i].resize(sz(lst[i]),0);
        vi val;
        rep1(i,n) {
            rep(j,sz(lst[i])){
                pos[lst[i][j]]={i,j}, val.pb(lst[i][j]);
            }
            if (sz(lst[i])) lvl.pb(i);
        }
        unordered_map<int,vi> banned;
        rep(i,m){
            int u,v;
            cin>>u>>v;
            banned[u].pb(v), banned[v].pb(u);
        }
        int mxans=0;
        for (auto v:val){
            auto [ll,___]=pos[v];
            for (auto c:banned[v]){
                auto [x,y]=pos[c];
                label[x][y]=1;
            }
            for (auto l:lvl){
                rep(i,sz(lst[l])){
                    if (!label[l][i]&&lst[l][i]!=v) {
                        mxans=max(mxans,(l+ll)*(v+lst[l][i])); 
                        // cerr<<"fk: "<<v<<" "<<lst[l][i]<<"\n";
                        break;
                    }
                }
            }
            for (auto c:banned[v]){
                auto [x,y]=pos[c];
                label[x][y]=0;
            }
        }
        cout<<mxans<<"\n";
    }
    return 0;
}