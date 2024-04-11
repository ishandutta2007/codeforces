#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2
//#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int mod;

struct mat
{
    int a[maxn][maxn];
    void clear() {memset(a,0,sizeof a);}
    mat() {clear();}
    mat operator *(const mat &A) const
    {
        mat res;
        rep(i,0,maxn-1) rep(k,0,maxn-1) rep(j,0,maxn-1) res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*A.a[k][j])%mod;
        return res;
    }
};

mat qp(mat a,ll k)
{
    mat res;
    rep(i,0,maxn-1) res.a[i][i]=1;
    while(k)
    {
        if(k&1) res=res*a;
        a=a*a;
        k>>=1;
    }
    return res;
}

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
    ll n,k;
    int l;
    scanf("%I64d%I64d%d%d",&n,&k,&l,&mod);
    mat a;
    a.a[0][0]=a.a[0][1]=a.a[1][0]=1;
    mat b=qp(a,n-1);
    ll zero=((ll)b.a[0][0]+b.a[0][1]+b.a[1][0]+b.a[1][1])%mod;
    ll one=(qp(2,n)-zero+mod)%mod;
    //printf("%I64d %I64d\n",one,zero);
    ll ans=1%mod;
    while(l--)
    {
        ans=ans*(k&1?one:zero)%mod;
        k>>=1;
    }
    if(k) ans=0;
    printf("%I64d\n",ans);
    return 0;
}