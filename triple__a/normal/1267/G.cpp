// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
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
const int maxn=107;
const double EPS=1e-9;
 
int n,x;
int a[maxn],sum;
__int128_t dp[maxn][maxn*maxn],f[maxn][maxn*maxn];

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(20);
    cin>>n>>x;
    rep1(i,n) cin>>a[i], sum+=a[i];
    dp[0][0]=1;
    rep1(i,n) {
        rep(k,i) rep(j,10001-a[i]){
            f[k+1][j+a[i]]+=dp[k][j];
            f[k][j]+=dp[k][j];
        }
        memcpy(dp,f,sizeof(f));
        memset(f,0,sizeof(f));
    }
    long double ans=0;
    long double binom=1;
    rep(i,n){
        rep(s,10001) {
            ans+=1.0*dp[i][s]/binom*min(1.0*(sum-s)/(n-i),1.0*x/2*(1.0*n/(n-i)+1));
        }
        binom*=n-i, binom/=i+1;
    }
    cout<<ans;
    return 0;
}