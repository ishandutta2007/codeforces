#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 250
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll inv[maxn+5],fac[maxn+5],ifac[maxn+5];

ll C(int n,int m) {return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}

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

int main()
{
    inv[1]=fac[0]=ifac[0]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int n,k; scanf("%d%d",&n,&k);
    ll ans=0;
    rep(i,0,n) rep(j,0,n)
    {
        ll tmp=C(n,i)*C(n,j)%mod*qp(k-1,n*(i+j)-i*j)%mod*qp(k,(n-i)*(n-j))%mod;
        if((i+j)&1) tmp=-tmp+mod;
        ans=(ans+tmp)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}