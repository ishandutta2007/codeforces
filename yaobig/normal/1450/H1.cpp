#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char s[maxn+5];
ll fac[maxn+5],inv[maxn+5],ifac[maxn+5];
ll C(int n,int m)
{
    if(m<0 || n-m<0) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int main()
{
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int n,m; scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int X[2]={},F[2]={};
    assert(F[0]==0 && F[1]==0);
    rep(i,1,n) 
    {
        if(s[i]=='b') X[i&1]++;
        if(s[i]=='?') F[i&1]++;
    }
    int x=X[1]-X[0];
    ll ans=0;
    rep(i,-F[0],F[1]) if((x-i)%2==0) ans=(ans+1ll*abs(x+i)*C(F[1]+F[0],F[0]+i))%mod;
    rep(i,1,F[1]+F[0]) ans=ans*inv[2]%mod;
    printf("%lld\n",ans);
    return 0;
}