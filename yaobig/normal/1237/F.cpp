#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 3600
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void add(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

vi solve(vi &mark)
{
    int n=mark.size()-1,m=0; 
    mark[0]=1;
    rep(i,1,n) m+=mark[i]==0;
    m/=2;
    vector<vi> dp(3,vi(m+1,0));
    dp[0][0]=1;
    rep(i,1,n) rep(j,0,m) 
    {
        dp[i%3][j]=dp[(i-1)%3][j];
        if(j && mark[i]==0 && mark[i-1]==0) add(dp[i%3][j],dp[(i-2)%3][j-1]);
    }
    return dp[n%3];
}

ll inv[maxn+5],fac[maxn+5],ifac[maxn+5];

ll binom(int n,int m)
{
    if(n<m || m<0) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main()
{    
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int h,w,n; scanf("%d%d%d",&h,&w,&n);
    vi mark_r(h+1,0),mark_c(w+1,0);
    rep(i,1,n)
    {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        mark_r[a]=mark_r[c]=1;
        mark_c[b]=mark_c[d]=1;
    }
    auto dp_r=solve(mark_r);
    auto dp_c=solve(mark_c);
    int N=dp_r.size()-1,M=dp_c.size()-1;
    int H=0,W=0;
    rep(i,1,h) H+=mark_r[i]==0;
    rep(i,1,w) W+=mark_c[i]==0;
    ll ans=0;
    rep(a,0,N) rep(b,0,M) 
    {
        if(a*2+b>H || a+b*2>W) break;
        ll tmp=1ll*dp_r[a]*dp_c[b]%mod*binom(H-a*2,b)%mod*binom(W-b*2,a)%mod*fac[a]%mod*fac[b]%mod;
        ans=(ans+tmp)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}