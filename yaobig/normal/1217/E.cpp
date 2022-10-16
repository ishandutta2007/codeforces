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
#define ls i*2
#define rs i*2+1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+10],x[maxn+5];
pii operator +(pii a,pii b)
{
    if(a.FI>b.FI) swap(a,b);
    return mp(a.FI,min(a.SE,b.FI));
}
struct segtree
{
    pii mx[maxn*4+5];
    segtree(){}
    void pu(int i) {mx[i]=mx[ls]+mx[rs];}
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            if(x[l]%10) mx[i]=mp(a[l],inf);
            else mx[i]=mp(inf,inf);
            x[l]/=10;
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void chg(int i,int l,int r,int pos)
    {
        if(pos<=l && r<=pos)
        {
            if(x[l]%10) mx[i]=mp(a[l],inf);
            else mx[i]=mp(inf,inf);
            x[l]/=10;
            return;
        }
        if(r<pos || pos<l) return;
        int mid=(l+r)>>1;
        chg(ls,l,mid,pos);
        chg(rs,mid+1,r,pos);
        pu(i);
    }
    pii ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return mx[i];
        if(r<ql || qr<l) return mp(inf,inf);
        int mid=(l+r)>>1;
        return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
    }
}t[9];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]),x[i]=a[i];
    rep(i,0,8) t[i].build(1,1,n);

    while(m--)
    {
        int op; scanf("%d",&op);
        if(op==1)
        {
            int id,v; scanf("%d%d",&id,&v);
            a[id]=x[id]=v;
            rep(i,0,8) t[i].chg(1,1,n,id);
        }
        else
        {
            int l,r; scanf("%d%d",&l,&r);
            int ans=inf*2;
            rep(i,0,8)
            {
                pii res=t[i].ask(1,1,n,l,r);
                if(res.SE!=inf) ans=min(ans,res.FI+res.SE);
            }
            if(ans==inf*2) ans=-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}