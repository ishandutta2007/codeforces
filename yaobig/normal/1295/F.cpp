#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100
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

int l[maxn+5],r[maxn+5];
int ways[maxn+5][maxn+5];
ll inv[maxn+5];

int binom(int n,int m)
{
    ll res=1;
    rep(i,1,m) res=res*(n-i+1)%mod;
    rep(i,1,m) res=res*inv[i]%mod;
    return res;
}

int main()
{
    inv[1]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;

    int n; scanf("%d",&n);
    per(i,1,n) scanf("%d%d",&l[i],&r[i]),r[i]++;
    vi vec;
    rep(i,1,n) vec.pb(l[i]),vec.pb(r[i]);
    sort(vec.begin(),vec.end()); vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int N=vec.size();
    vi dp(n+1,0);
    rep(i,1,N-1) rep(j,1,n) ways[i][j]=binom(vec[i]-vec[i-1]+j-1,j);
    dp[0]=1;
    rep(i,1,N-1)
    {
        per(j,0,n) if(dp[j])
        {
            rep(k,j+1,n)
            {
                if((l[k]<=vec[i-1] && vec[i]<=r[k])==0) break;
                add(dp[k],1ll*dp[j]*ways[i][k-j]%mod);
            }
        }
    }
    ll ans=dp[n];
    rep(i,1,n) ans=ans*qp(r[i]-l[i],mod-2)%mod;
    printf("%lld\n",ans);
    return 0;
}