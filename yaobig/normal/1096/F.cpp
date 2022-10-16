#include<bits/stdc++.h>
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

int t[maxn+5];
void add(int x)
{
    for(;x<=maxn;x+=x&-x) t[x]++;
}
int ask(int x)
{
    int ans=0;
    for(;x;x-=x&-x) ans+=t[x];
    return ans;
}

int a[maxn+5];
bool exi[maxn+5];

int main()
{
    int n,N=0; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) if(a[i]>0) exi[a[i]]=1;
    rep(i,1,n) if(!exi[i]) add(i),N++;
    ll ans=0,tot=0;
    rep(i,1,n)
    {
        if(a[i]>0) tot=(tot+ask(a[i]))%mod;
        else ans=(ans+tot)%mod;
    }
    tot=0;
    per(i,1,n)
    {
        if(a[i]>0) tot=(tot+N-ask(a[i]))%mod;
        else ans=(ans+tot)%mod;
    }
    ans=ans*qp(N,mod-2)%mod;
    ans=(ans+1ll*N*(N-1)%mod*qp(4,mod-2))%mod;
    memset(t,0,sizeof t);
    per(i,1,n) if(a[i]>0)
    {
        ans=(ans+ask(a[i]))%mod;
        add(a[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}