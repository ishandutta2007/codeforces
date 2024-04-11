// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
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
const int N=2001;
const int M=51;
int n,k;
int a[N],ff[N],rf[N];
int modpow(int u,int v){
    int ans=1,t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    rep1(i,n) cin>>a[i];
    ff[0]=1;
    for (int i=1;i<N;++i) ff[i]=ff[i-1]*i%mod;
    rf[N-1]=modpow(ff[N-1],mod-2);
    for (int i=N-1;i>0;--i) rf[i-1]=rf[i]*i%mod;
    vector<vi> dp(2*M,vi(N,0));
    dp[M][0]=1;
    rep1(i,n){
        vector<vi> f(2*M,vi(N,0));
        vector<vi> sum(N+2*M,vi(2*M,0));
        for (int j=max(-k,-a[i-1]);j<=k;++j){
            int pos=j+a[i-1]-a[i];
            if (pos<-k||pos>k) continue;
            for (int w=0;w<=i;++w){
                f[pos+M][w]=(f[pos+M][w]+(j+a[i-1]+w)*dp[j+M][w])%mod;
                f[pos+M][w+1]=(f[pos+M][w+1]+dp[j+M][w])%mod;
            }
        }
        //-k~k+i
        for (int j=max(-k,-a[i-1]);j<=k;++j){
            for (int w=0;w<=i;++w){
                sum[j+w+M][j+M]=(sum[j+w+M][j+M]+ff[w]*dp[j+M][w])%mod;
            }
        }
        for (int s=max(-k,-a[i-1]);s<=k+i;++s){
            for (int j=max(-k,-a[i-1]);j<=k;++j){
                sum[s+M][j+M]=(sum[s+M][j+M]+sum[s+M][j-1+M])%mod;
            }
        }
        for (int j=max(-k,-a[i]);j<=k;++j){
            int pos=j+a[i]-a[i-1];
            for (int w=max(0ll,-pos+1-k);w<=min(i,i+k+1-pos);++w){
                f[j+M][w]=(f[j+M][w]+rf[w]*sum[pos+w-1+M][max(min(pos-1,k),-k-1)+M])%mod;
            }
        }
        swap(dp,f);
    }
    int ans=0;
    for (int j=max(-k,-a[n]);j<=k;++j){
        int val=j+a[n];
        for (int w=0;w<=n;++w){
            if (val+w<=n) ans=(ans+ff[n-val]*rf[n-val-w]%mod*dp[j+M][w])%mod;
        }
    }
    cout<<ans;
    return 0;
}