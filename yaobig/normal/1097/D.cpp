#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 10000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll inv[105];

ll qp(ll a,int k)
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

ll f[105],g[105];

ll cal(ll p,int c,int k)
{
    rep(i,0,c+1) f[i]=0;
    f[c]=1;
    rep(r,1,k)
    {
        rep(i,0,c) g[i]=0;
        rep(i,0,c) g[i]=f[i]*inv[i+1]%mod;
        per(i,0,c) f[i]=(f[i+1]+g[i])%mod;
    }
    ll res=0,a=1;
    rep(i,0,c)
    {
        res=(res+a*f[i])%mod;
        a=a*p%mod;
    }
    return res;
}

int main()
{
    rep(i,1,100) inv[i]=qp(i,mod-2);

    ll n; int k; scanf("%I64d%d",&n,&k);
    ll ans=1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int c=0;
            while(n%i==0) c++,n/=i;
            ans=ans*cal(i,c,k)%mod;
        }
    }
    if(n>1) ans=ans*cal(n,1,k)%mod;
    printf("%I64d\n",ans);
    return 0;
}