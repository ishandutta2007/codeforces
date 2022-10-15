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
const int N=107;
const int K=10;

mt19937 rng(1234);

int a[N];
int dp[N*107],f[N*107];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        int n;
        cin>>n;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        rep(i,2*n) cin>>a[i];
        rep(i,2*n) assert(a[i]>=1&&a[i]<=100);
        int sum=0;
        rep(i,n){
            memset(f,0,sizeof(f));
            rep(k,i*100+1){
                f[k+a[i]]|=dp[k];
                f[k+a[i+n]]|=dp[k];
            }
            rep(k,N*107) dp[k]=f[k];
        }
        rep(i,2*n) sum+=a[i];
        int now=INF, id=-1;
        rep(i,n*100+1) {
            if (dp[i]) now=min(now,i*i+(sum-i)*(sum-i)); 
        }
        int ans=now;
        for (int i=0;i<2*n;++i) ans+=(n-2)*a[i]*a[i];
        // ans+=id*id+(sum-id)*(sum-id);
        cout<<ans<<"\n";
    }
    return 0;
}