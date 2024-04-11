#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 50
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct mat
{
    int a[maxn+5][maxn+5],n;
    void Clear(){memset(a,0,sizeof a);}
    mat(){n=0; Clear();}
    mat(int x):n(x){Clear();}
    int* operator [](const int &i) const {return (int*)a[i];}

    mat operator *(const mat &B) const
    {
        mat C(n);
        rep(i,1,n) rep(k,1,n) rep(j,1,n) C[i][j]=(C[i][j]+1ll*a[i][k]*B[k][j])%mod;
        return C;
    }
};
mat qp(mat A,ll k)
{
    mat res(A.n); rep(i,1,res.n) res[i][i]=1;
    while(k)
    {
        if(k&1) res=res*A;
        A=A*A;
        k>>=1;
    }
    return res;
}

int N;
ll d[maxn+5],a[maxn+5];

ll cal(vector<ll> a)
{
    int n=a.size()-1;
    assert(n&1);
    a[0]=-1;
    vector<ll> vec;
    rep(i,1,n) 
    {
        if(i&1) 
        {
            vec.pb(a[i-1]+1);
            vec.pb(a[i]+1);
        }
        else
        {
            vec.pb(a[i-1]);
            vec.pb(a[i]);
        }
    }
    sort(vec.begin(),vec.end()); vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int N=vec.size();
    mat A(n); rep(i,1,n) A[i][i]=1;
    rep(id,0,N-2)
    {
        ll x=vec[id];
        mat B(n);
        rep(i,1,n)
        {
            if(i&1 && a[i-1]+1<=x && x<=a[i])
            {
                rep(j,1,i) B[i][j]=1;
            }
            if((i&1)==0 && a[i]<=x && x<=a[i-1]-1)
            {
                rep(j,1,i-1) B[i][j]=1;
            }
        }
        A=qp(B,vec[id+1]-x)*A;
    }
    ll ans=0;
    rep(i,1,n) ans=(ans+A[i][1])%mod;
    return ans;
}

int main()
{
    int n,x; scanf("%d%d",&n,&x);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        if(x!=0)
        {
            if((x>0 && d[N]>0) || (x<0 && d[N]<0)) d[N]+=x;
            else d[++N]=x;
        }
    }
    rep(i,0,N) a[i+1]=a[i]+d[i];
    n=N+1;
    ll MX=0;
    rep(i,1,n)
    {
        ll tmp=a[i];
        rep(j,i+1,n) tmp=max(tmp,a[j]);
        MX=max(MX,tmp-a[i]);
    }
    if(MX==0) return printf("1 %lld\n",(-a[n]+1)%mod),0;
    ll ans=0;
    rep(i,1,n)
    {
        int r=-1;
        rep(j,i+1,n) if(a[j]-a[i]==MX) r=j;
        if(r!=-1) 
        {
            vector<ll> b;
            rep(j,i,r) b.pb(a[j]-a[i]);
            ans=(ans+cal(b))%mod;    
            i=r;
        }
    }
    printf("%lld %lld\n",MX+1,ans);
    return 0;
}