#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 5100
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

void upd(int &x,int y) {x=x+y<mod?x+y:x+y-mod;}

int dp[100+5][maxn+5];

ll qp(ll a,int k)
{
    ll ans=1;
    while(k)
    {
        if(k&1) ans=ans*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ans;
}

ll fac[maxn+5],inv[maxn+5],ifac[maxn+5];
ll C(int n,int m)
{
    if(m<0 || m>n) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

ll cal(int n,int m)
{
    if(m==0) return n==0;
    return C(n-1,m-1);
}

ll f(int N,int S,int upp)
{
    ll ans=0;
    for(int p=0;p<=N && p*upp<=S;p++)
    {
        ans=(ans+(p&1?-1:1)*C(N,p)*cal(S-p*upp,N))%mod;
    }
    return (ans+mod)%mod;
}

int main()
{
    fac[0]=ifac[0]=1;
    inv[1]=1;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int p,s,r;
    scanf("%d%d%d",&p,&s,&r);
    int ans=0;
    rep(i,r,s)
    {
        for(int num=0;num<=p-1 && num*i<=s-i;num++)
        {
            ll tmp=f(p-1-num,s-i-num*i+p-1-num,i)*qp(num+1,mod-2)%mod;
            tmp=tmp*C(p-1,num)%mod;
            upd(ans,tmp);
        }
    }
    ans=ans*qp(C(s-r+p-1,p-1),mod-2)%mod;
    printf("%d\n",ans);
    return 0;
}