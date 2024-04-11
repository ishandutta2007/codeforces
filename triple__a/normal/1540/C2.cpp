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
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=107;
int n;
int a[N],b[N];
map<int,int> ret;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    int pd=1;
    rep1(i,n) cin>>a[i], pd=pd*(a[i]+1)%mod;
    rep1(i,n-1) cin>>b[i];
    rep1(i,n-1) b[i]+=b[i-1];
    int _;
    cin>>_;
    while (_--){
        int x;
        cin>>x;
        if (x>100) {cout<<0<<"\n"; continue;}
        if (x<-5000) {cout<<pd<<"\n"; continue;}
        if (ret.find(x)!=ret.end()){cout<<ret[x]<<"\n"; continue;}
        vi dp(N*N,0);
        dp[0]=1;
        int lb=x,csum=0;
        rep1(i,n){
            vi s(N*N,0);
            csum+=a[i];
            for (int j=0;j<=csum;++j) s[j]=dp[j];
            for (int j=1;j<=csum;++j) s[j]=(s[j]+s[j-1])%mod;
            for (int j=max(0ll,lb);j<=csum;++j) dp[j]=(s[j]-(j<=a[i]?0:s[j-a[i]-1])+mod)%mod;
            for (int j=0;j<min(N*N,max(0ll,lb));++j) dp[j]=0;
            lb+=b[i]+x;
        }
        int ans=0;
        for (int i=0;i<=csum;++i) ans=(ans+dp[i])%mod;
        cout<<(ret[x]=ans)<<"\n";
    }
    
    return 0;
}