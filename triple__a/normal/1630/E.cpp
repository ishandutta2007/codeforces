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
const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=1000007;
const int K=407;
int n,m;
int a[N],cnt[N],num[N],den[N],f[N],rf[N];
int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15);
    int _;
    cin>>_;
    f[0]=rf[0]=1;
    for (int i=1;i<=1000000;++i) f[i]=f[i-1]*i%mod;
    rf[1000000]=modpow(f[1000000],mod-2);
    for (int i=1000000;i>0;--i) rf[i-1]=rf[i]*i%mod;
    while (_--){
        cin>>n;
        rep1(i,n) cnt[i]=0;
        rep(i,n) cin>>a[i], cnt[a[i]]++;
        int g=0;
        vi fk;
        rep1(i,n) if (cnt[i]) g=__gcd(g,cnt[i]), fk.pb(cnt[i]);
        rep1(i,g) den[i]=num[i]=0;
        if (sz(fk)==1) {cout<<"1\n"; continue;}
        for (int j=1;j<=g;++j){
            if (g%j==0){
                den[j]=1;
                int sum=0;
                for (auto c:fk) den[j]=den[j]*rf[c/j]%mod, sum+=c/j;
                den[j]=den[j]*f[sum]%mod;
            }
        }
        for (int j=1;j<=g;++j){
            if (g%j==0){
                num[j]=0;
                int pd=1,sum=0;
                for (auto c:fk) pd=pd*rf[c/j]%mod, sum+=c/j;
                pd=pd*f[sum-2]%mod;
                for (auto c:fk) if (c/j>1) num[j]=(num[j]+pd*f[c/j]%mod*rf[c/j-2])%mod;
                num[j]=num[j]*n%mod;
            }
        }
        int A=0,B=0;
        for (int j=g;j>0;--j){
            for (int i=2;i*j<=g;++i){
                num[j]=(num[j]-num[i*j]+mod)%mod;
                den[j]=(den[j]-den[i*j]+mod)%mod;
            }
            // cerr<<j<<" "<<num[j]<<" "<<den[j]<<endl;
            A=(A+num[j]*j)%mod, B=(B+den[j]*j)%mod;
        }
        int ret=A*modpow(B,mod-2)%mod;
        ret=(n-ret+mod)%mod;
        cout<<ret<<"\n";
    }
    return 0;
}