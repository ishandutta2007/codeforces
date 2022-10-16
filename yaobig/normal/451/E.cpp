#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 20
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

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
ll f[maxn+5];
ll inv;
int n;
ll C(ll k)
{
    if(k<0) return 0;
    ll res=1;
    rep(i,1,n-1) res=res*((i+k)%mod)%mod;
    return res*inv%mod;
}
int cnt[(1<<20)+5];

int main()
{

    ll s;
    scanf("%d%I64d",&n,&s);
    rep(i,1,(1<<n)-1) cnt[i]=cnt[i>>1]+(i&1);

    rep(i,1,n) scanf("%I64d",&f[i]),f[i]++;
    inv=1;
    rep(i,1,n-1) inv=inv*i%mod;
    inv=qp(inv,mod-2);
    ll ans=0;
    rep(i,0,(1<<n)-1)
    {
        ll exp=s;
        rep(b,1,n) if(i&(1<<(b-1))) exp-=f[b];
        ans=(ans+((cnt[i]&1)?-1:1)*C(exp)+mod)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}