#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200010
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ls i*2
#define rs i*2+1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef double db;

vl V;
int getid(ll x) {return lower_bound(V.begin(),V.end(),x)-V.begin();}
int qtype[maxn+5];
ll quel[maxn+5],quer[maxn+5];

struct SEGtree
{
    int b[maxn*4+5],w[maxn*4+5],mark[maxn*4+5];
    void pu(int i)
    {
        b[i]=min(b[ls],b[rs]);
        w[i]=min(w[ls],w[rs]);
    }
    void push(int i,int l,int r,int type)
    {
        if(type==1) b[i]=l,w[i]=inf,mark[i]=1;
        if(type==2) b[i]=inf,w[i]=l,mark[i]=2;
        if(type==3) swap(b[i],w[i]),mark[i]=3-mark[i];
    }
    void pd(int i,int l,int r)
    {
        if(mark[i])
        {
            int mid=(l+r)>>1;
            push(ls,l,mid,mark[i]);
            push(rs,mid+1,r,mark[i]);
            mark[i]=0;
        }
    }
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            b[i]=inf;
            w[i]=l;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void change(int i,int l,int r,int ql,int qr,int type)
    {
        if(ql<=l && r<=qr)
        {
            push(i,l,r,type);
            return;
        }
        if(r<ql || qr<l) return;
        pd(i,l,r);
        int mid=(l+r)>>1;
        change(ls,l,mid,ql,qr,type);
        change(rs,mid+1,r,ql,qr,type);
        pu(i);
    }
}t;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%I64d%I64d",&qtype[i],&quel[i],&quer[i]);
    V.pb(0);
    V.pb(1);
    rep(i,1,n)
    {
        V.pb(quel[i]);
        V.pb(quer[i]+1);
    }
    sort(V.begin(),V.end());V.erase(unique(V.begin(),V.end()),V.end());
    int N=V.size()-1;
    t.build(1,1,N);
    rep(i,1,n)
    {
        int l=getid(quel[i]);
        int r=getid(quer[i]+1)-1;
        t.change(1,1,N,l,r,qtype[i]);
        printf("%I64d\n",V[t.w[1]]);
    }
    return 0;
}