#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn (1<<21)
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const int g=3;
ll wn[30][2];
ll a[maxn+5],f[maxn+5],tmp[maxn+5];

int r[maxn+5],n2,len;
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

void init()
{
    rep(i,0,21)
    {
        wn[i][0]=qp(g,(mod-1)/(1<<i));
        wn[i][1]=qp(wn[i][0],mod-2);
    }
}
void mul(ll c[],ll a[],ll b[])
{
    rep(i,0,n2-1) tmp[i]=a[i]*b[i]%mod;
    rep(i,0,n2-1) c[i]=tmp[i];
}

void NTT(ll a[],int opt)
{
    rep(i,1,n2-1) if(r[i]>i) swap(a[i],a[r[i]]);
    rep(t,0,len-1)
    {
    //printf("???%d\n",t);
        int step=1<<t,step2=1<<t+1;
        ll w=wn[t+1][opt];
        for(int i=0;i<n2;i+=step2)
        {
            ll wj=1;
            rep(j,0,step-1)
            {
                ll tmp=wj*a[i+j+step]%mod;
                a[i+j+step]=(a[i+j]-tmp+mod)%mod;
                a[i+j]=(a[i+j]+tmp)%mod;
                wj=wj*w%mod;
            }
        }
    }
    if(opt)
    {
        ll inv=qp(n2,mod-2);
        rep(i,0,n2-1) a[i]=a[i]*inv%mod;
    }
    return;
}

int main()
{
    init();
    len=21;
    n2=1<<len;
    rep(i,0,n2-1) r[i]=(r[i>>1]>>1)|((i&1)<<len-1);
    int n,k;
    scanf("%d%d",&n,&k);
    n/=2;
    rep(i,1,k)
    {
        int x; scanf("%d",&x);
        a[x]=1;
    }
    f[0]=1;
    NTT(a,0);
    NTT(f,0);
    while(n)
    {
        if(n&1) mul(f,f,a);
        mul(a,a,a);
        n>>=1;
    }
    NTT(f,1);
    ll ans=0;
    rep(i,0,(1<<20)-1) ans=(ans+f[i]*f[i])%mod;
    printf("%I64d\n",ans);
    return 0;
}