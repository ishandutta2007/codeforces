#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

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
ll f[maxn+5][maxn+5];

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);

    f[0][0]=1;
    rep(i,1,k) rep(a,1,k) f[i][a]=(f[i-1][a]*a+f[i-1][a-1]*(n-a+1))%mod;

    ll ans=0,inv_m=qp(m,mod-2),inv_m_pw=1;
    rep(a,1,k)
    {
        inv_m_pw=inv_m_pw*inv_m%mod;
        ans=(ans+inv_m_pw*f[k][a])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}