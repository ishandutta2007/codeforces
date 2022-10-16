#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],b[maxn+5];
vi va,vb;

void quchong(vi &v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
int getaid(int x) {return lower_bound(va.begin(),va.end(),x)-va.begin()+1;}
int getbid(int x) {return lower_bound(vb.begin(),vb.end(),x)-vb.begin()+1;}

int fa[maxn+5],sz[maxn+5];
bool mark[maxn+5];

int getfa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}

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

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
    rep(i,1,n) va.pb(a[i]);
    rep(i,1,n) vb.pb(b[i]);
    quchong(va);
    quchong(vb);
    int N=va.size(),M=vb.size();
    rep(i,1,N+M) fa[i]=i;
    rep(i,1,N+M) sz[i]=1;
    rep(i,1,n)
    {
        int x=getaid(a[i]);
        int y=N+getbid(b[i]);
        int fx=getfa(x),fy=getfa(y);
        if(fx==fy) mark[fx]=1;
        else
        {
            sz[fx]+=sz[fy];
            mark[fx]|=mark[fy];
            fa[fy]=fx;
        }
    }
    ll ans=1;
    rep(i,1,N+M) if(i==getfa(i)) ans=ans*(qp(2,sz[i])-(mark[i]==0))%mod;
    printf("%I64d\n",ans);
    return 0;
}