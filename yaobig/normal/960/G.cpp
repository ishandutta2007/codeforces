#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

const int g=3;

int wn[30][2];
vi r;
int n2,len;
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
void init()
{
    rep(i,0,20)
    {
        wn[i][0]=qp(g,(mod-1)/(1<<i));
        wn[i][1]=qp(wn[i][0],mod-2);
    }
}

void NTT(vi &a,int opt)
{
    rep(i,1,n2-1) if(r[i]>i) swap(a[i],a[r[i]]);
    rep(t,0,len-1)
    {
        int step=1<<t,step2=1<<(t+1);
        int w=wn[t+1][opt];
        for(int i=0;i<n2;i+=step2)
        {
            ll wj=1;
            rep(j,0,step-1)
            {
                int tmp=wj*a[i+j+step]%mod;
                a[i+j+step]=a[i+j]-tmp+mod; if(a[i+j+step]>=mod) a[i+j+step]-=mod;
                a[i+j]=a[i+j]+tmp; if(a[i+j]>=mod) a[i+j]-=mod;
                wj=wj*w%mod;
            }
        }
    }
    if(opt==1) 
    {
        ll inv=qp(n2,mod-2);
        rep(i,0,n2-1) a[i]=a[i]*inv%mod;
    }
}

vi conv(vi A,vi B)
{
    int n=A.size()+B.size()-1;
	
    len=0;
    for(n2=1;n2<n;n2<<=1) len++;
    r.resize(n2);
    rep(i,1,n2-1) r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
	
    A.resize(n2,0);
    B.resize(n2,0);
    NTT(A,0);
    NTT(B,0);
    rep(i,0,n2-1) A[i]=1ll*A[i]*B[i]%mod;
    NTT(A,1);
    A.resize(n);
	return A;
}

ll inv[maxn+5],fac[maxn+5],ifac[maxn+5];

vi solve(int l,int r)
{
    if(l==r) return vi{l,1};
    int mid=(l+r)>>1;
    vi A=solve(l,mid),B=solve(mid+1,r);
    return conv(A,B);
}

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

    int n,a,b; scanf("%d%d%d",&n,&a,&b);
    if(n-1<a+b-2 || a==0 || b==0) return puts("0"),0;
    if(n==1) return puts("1"),0;
    init();
    auto A=solve(0,n-2);
    ll ans=A[a+b-2]*binom(a+b-2,a-1)%mod;
    printf("%lld\n",ans);
    return 0;
}