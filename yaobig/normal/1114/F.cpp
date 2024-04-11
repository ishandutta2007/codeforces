#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 400000
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ls i*2
#define rs i*2+1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef double db;

int p[305],num;
bool np[305];
int a[maxn+5];
ll inv[305];

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

struct SEGTREE
{
    ll s[maxn*4+5],mark[maxn*4+5];
    ll f[maxn*4+5],fm[maxn*4+5];
    ll S,F;
    void pu(int i)
    {
        s[i]=s[ls]*s[rs]%mod;
        f[i]=f[ls]|f[rs];
    }
    void pd(int i,int l,int r)
    {
        if(mark[i]!=1)
        {
            mark[ls]=mark[ls]*mark[i]%mod;
            mark[rs]=mark[rs]*mark[i]%mod;
            int mid=(l+r)>>1;
            s[ls]=s[ls]*qp(mark[i],mid-l+1)%mod;
            s[rs]=s[rs]*qp(mark[i],r-mid)%mod;
            mark[i]=1;
        }
        if(fm[i])
        {
            fm[ls]|=fm[i];
            fm[rs]|=fm[i];
            f[ls]|=fm[i];
            f[rs]|=fm[i];
            fm[i]=0;
        }
    }
    void build(int i,int l,int r)
    {
        mark[i]=1;
        if(l==r)
        {
            s[i]=a[l];
            rep(j,1,num) if(a[l]%p[j]==0) f[i]|=1ll<<j-1;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,int x,ll fl)
    {
        if(ql<=l && r<=qr)
        {
            s[i]=s[i]*qp(x,r-l+1)%mod;
            mark[i]=mark[i]*x%mod;
            f[i]|=fl;
            fm[i]|=fl;
            return;
        }
        if(qr<l || r<ql) return;
        pd(i,l,r);
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x,fl);
        add(rs,mid+1,r,ql,qr,x,fl);
        pu(i);
    }
    void ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)
        {
            S=S*s[i]%mod;
            F|=f[i];
            return;
        }
        if(qr<l || r<ql) return;
        pd(i,l,r);
        int mid=(l+r)>>1;
        ask(ls,l,mid,ql,qr);
        ask(rs,mid+1,r,ql,qr);
    }
}t;

int main()
{
    rep(i,2,300) if(np[i]==0)
    {
        p[++num]=i;
        for(int j=i*2;j<=300;j+=i) np[j]=1;
    }
    inv[1]=1;
    rep(i,2,300) inv[i]=inv[mod%i]*(mod-mod/i)%mod;

    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&a[i]);
    t.build(1,1,n);
    rep(i,1,q)
    {
        char s[15];
        int l,r;
        scanf("%s%d%d",s,&l,&r);
        if(s[0]=='M')
        {
            int x; scanf("%d",&x);
            ll f=0;
            rep(j,1,num) if(x%p[j]==0) f|=1ll<<j-1;
            t.add(1,1,n,l,r,x,f);
        }
        else
        {
            t.S=1;
            t.F=0;
            t.ask(1,1,n,l,r);
            ll ans=t.S;
            rep(j,1,num) if(t.F&(1ll<<j-1)) ans=ans*(1-inv[p[j]]+mod)%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}