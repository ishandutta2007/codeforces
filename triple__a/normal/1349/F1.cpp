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
const int N=5007;
int n,m,k;
int dp[N][N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    dp[1][0]=1;
    for (int i=2;i<=n;++i){
        for (int j=0;j<i-1;++j){
            dp[i][j]=(dp[i][j]+(j+1)*dp[i-1][j])%mod;
            dp[i][j+1]=(dp[i][j+1]+(i-j-1)*dp[i-1][j])%mod;
        }
    }
    rep(k,n) {
        int ans=0, t=1;
        for (int i=n;i>=k;--i){
            ans=(ans+dp[i][k]*t)%mod;
            t=t*i%mod;
        }
        cout<<ans<<" ";
    }
    return 0;
}