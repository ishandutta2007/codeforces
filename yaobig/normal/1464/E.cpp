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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll qp(ll a,ll k)
{
    ll r=1;
    while(k)
    {
        if(k&1) r=r*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return r;
}

vi e[maxn+5];
int sg[maxn+5];

int dfs(int now)
{
    if(sg[now]!=-1) return sg[now];
    set<int> a;
    for(auto v: e[now]) a.insert(dfs(v));
    rep(i,0,maxn) if(a.find(i)==a.end()) return sg[now]=i; 
    assert(0);
    return 0;
}

void fwt(vector<ll> &a,int opt)
{
    int N=a.size();
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            rep(k,0,i-1)
            {
                ll X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%mod;
                a[i+j+k]=(X+mod-Y)%mod;
            }
    if(opt==-1)
    {
        ll inv=qp(N,mod-2); 
        rep(i,0,N-1) a[i]=a[i]*inv%mod;
    }
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int u,v; scanf("%d%d",&u,&v);
        e[u].pb(v);
    }
    rep(i,1,n) sg[i]=-1;
    rep(i,1,n) if(sg[i]==-1) dfs(i);

    int N=1; while(N<n) N*=2;
    vector<ll> A(N,0);
    ll inv=qp(n+1,mod-2);
    rep(i,1,n) A[sg[i]]=(A[sg[i]]+inv)%mod;
    vector<ll> I(N,0),B(N,0);
    I[0]=1;
    rep(i,0,N-1) B[i]=(I[i]-A[i]+mod)%mod;
    fwt(B,1);
    fwt(I,1);
    rep(i,0,N-1) B[i]=I[i]*qp(B[i],mod-2)%mod;
    fwt(B,-1);
    printf("%lld\n",(1-B[0]*inv%mod+mod)%mod);
    return 0;
}