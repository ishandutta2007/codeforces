#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
using ll = long long;
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 1<<14;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

ll qp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

int a[14],e[14][14];
int pr[maxn][14];
int dp[maxn];

int main()
{
	int n; scanf("%d",&n);
    rep(i,0,n-1) scanf("%d",&a[i]);
    rep(i,0,n-1) rep(j,0,n-1) e[i][j]=1ll*a[i]*qp(a[i]+a[j],mod-2)%mod;
    int N=1<<n;
    rep(msk,0,N-1)
    {
        rep(i,0,n-1) if((msk>>i&1)==0)
        {
            pr[msk][i]=1;
            rep(j,0,n-1) if(msk>>j&1) pr[msk][i]=1ll*pr[msk][i]*e[j][i]%mod;
        }
    }
    dp[0]=1;
    rep(S,1,N-1)
    {
        dp[S]=1;
        for(int T=S;T;T=(T-1)&S) if(T!=S) 
        {
            ll tmp=1;
            rep(i,0,n-1) if(S>>i&1 && (T>>i&1)==0) tmp=tmp*pr[T][i]%mod;
            dp[S]=(dp[S]+mod-tmp*dp[T]%mod)%mod;
        }
    }
    int ans=0;
    rep(S,1,N-1)
    {
        ll tmp=1;
        rep(i,0,n-1) if((S>>i&1)==0) tmp=tmp*pr[S][i]%mod;
        ans=(ans+tmp*dp[S]%mod*__builtin_popcount(S))%mod;
    }
    printf("%d\n",ans);
	return 0;
}