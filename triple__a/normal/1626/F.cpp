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
const int maxn=1000007;
const double EPS=1e-9;
const int M=720720, M1=10920*2, M2=27720;
int n,k,a,x,y,m;
int f[20];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>a>>x>>y>>k>>m;
    f[0]=1;
    rep(i,k) f[i+1]=f[i]*n%mod;
    int ans=0;
    vi prob(M,0), prob1(M2,0), tprob(M,0);
    rep(i,n){
        prob[a%M]++;
        ans=(ans+f[k-1]*a%mod*k)%mod;
        a=(x*a+y)%m;  
    }
    rep(i,M) prob1[i%M2]+=prob[i];
    rep(i,M2){
        vector<vi> dp(13,vi(120,0));
        dp[0][0]=1;
        int sum=0;
        rep1(j,min(k,12ll)){
            int tsum=0;
            rep(s,sum+1){
                dp[j][s] = (dp[j][s] + (n-1) * dp[j-1][s])%mod;
                dp[j][s+((i-s)%j+j)%j] = (dp[j][s+((i-s)%j+j)%j] + dp[j-1][s])%mod;
                tsum=max(tsum,s+((i-s)%j+j)%j);
            }
            sum=tsum;
            if (k>j) rep(s,sum+1){
                ans = (ans - dp[j][s]*f[k-j-1]%mod*prob1[i]%mod*s%mod*(j==12?k-j:1)%mod + mod)%mod;
            }
        }
        for (int w=i;w<M;w+=M2) rep(s,sum+1) tprob[(w-s+M)%M] = (tprob[(w-s+M)%M] + prob[w] * dp[min(k,12ll)][s])%mod;
    }
    if (k<=12){
        cout<<ans;
        return 0;
    }
    prob=tprob;
    vi prob2(M1,0);
    rep(i,M) prob2[i%M1]=(prob2[i%M1]+prob[i])%mod;
    rep(i,M1){
        vector<vi> dp(13,vi(120,0));
        dp[0][0]=1;
        int sum=0;
        for (int j=13;j<k;++j){
            int tsum=0;
            rep(s,sum+1){
                dp[j-12][s] = (dp[j-12][s] + (n-1) * dp[j-13][s])%mod;
                dp[j-12][s+((i-s)%j+j)%j] = (dp[j-12][s+((i-s)%j+j)%j] + dp[j-13][s])%mod;
                tsum=max(tsum,s+((i-s)%j+j)%j);
            }
            sum=tsum;
            rep(s,sum+1){
                ans = (ans-dp[j-12][s]%mod*f[k-j-1]%mod*prob2[i]%mod*s%mod + mod)%mod;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

/*
5 3 
3 0 2 3 
3 3 0 1
4 0 1 3 4

2 0 3 1 4

1 0 3 4 

8

7
1 1
1 2
2 1
1 0
0 1
0 1
1 0

7
1 1
1 2
2 1
1 0
0 1
0 1
1 0

4
1 1
1 1
1 0
1 0
4
1 0
2 1
1 1
1 0
1
0 0
2
0 1
0 1
2
1 0
0 1
3
2 0
0 1
0 1
*/