#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf (1ll<<60)
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int P;

int a[maxn+5]; ll S[maxn+5];

struct segtree
{
    #define ls rt*2
    #define rs rt*2+1
    vector<ll> x[maxn*4+5];
    void build(int rt,int l,int r)
    {
        if(l==r) x[rt].pb(P-a[l]),x[rt].pb(inf);
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            int N=x[ls].size(),M=x[rs].size();
            ll suml=S[mid]-S[l-1];
            x[rt].resize(N+M-1);
            int j=0;
            rep(i,0,N-1)
            {
                ll y=suml+x[ls][i]-1ll*i*P;
                while(j<M-1 && y>x[rs][j])
                {
                    x[rt][i+j]=x[ls][i]-(y-x[rs][j]);
                    j++;
                }
                x[rt][i+j]=x[ls][i];
                if(j>0 && y-P<x[rs][j-1]) j--;
            }
            x[rt][N+M-2]=inf;
        }
        /*
        fprintf(stderr,"? %d %d: ",l,r);
        for(auto p: x[rt]) fprintf(stderr,"%lld ",p);
        fprintf(stderr,"\n");
        */
    }
    ll ask(int rt,int l,int r,int ql,int qr,ll val)
    {
        //fprintf(stderr,"! %d %d: %lld\n",l,r,val);
        if(ql<=l && r<=qr) return S[r]-S[l-1]+val-1ll*P*(upper_bound(x[rt].begin(),x[rt].end(),val)-x[rt].begin());
        if(qr<l || r<ql) return val;
        int mid=(l+r)>>1;;
        return ask(rs,mid+1,r,ql,qr,ask(ls,l,mid,ql,qr,val));
    }
}T;

int main()
{
    int n,q; scanf("%d%d%d",&n,&q,&P);
    rep(i,1,n) scanf("%d",&a[i]),S[i]=S[i-1]+a[i];
    T.build(1,1,n);
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        printf("%lld\n",T.ask(1,1,n,l,r,0));
    }
    return 0;
}