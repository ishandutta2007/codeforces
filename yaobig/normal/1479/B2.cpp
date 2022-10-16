#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100010
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

struct segtree
{
    #define ls i*2
    #define rs i*2+1
    int a[maxn*4+5],lz[maxn*4+5];
    void push(int i,int x)
    {
        a[i]+=x; chmin(a[i],inf);
        lz[i]+=x;
    }
    void pu(int i) {a[i]=min(a[ls],a[rs]);}
    void pd(int i)
    {
        if(lz[i])
        {
            push(ls,lz[i]);
            push(rs,lz[i]);
            lz[i]=0;
        }
    }
    void build(int i,int l,int r)
    {
        if(l==r) a[i]=inf;
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void add(int i,int l,int r,int ql,int qr,int x)
    {
        if(ql<=l && r<=qr)
        {
            push(i,x);
            return;
        }
        if(r<ql || qr<l) return;
        pd(i);
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,x);
        add(rs,mid+1,r,ql,qr,x);
        pu(i);
    }
    int ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr) return a[i];
        if(r<ql || qr<l) return inf;
        pd(i);
        int mid=(l+r)>>1;
        return min(ask(ls,l,mid,ql,qr),ask(rs,mid+1,r,ql,qr));
    }
    void chg(int n,int p,int x)
    {
        int old=ask(1,0,n,p,p);
        add(1,0,n,p,p,x-old);
    }
}T;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    T.build(1,0,n);
    T.chg(n,0,1);
    rep(i,2,n)
    {
        int old=T.ask(1,0,n,a[i],a[i]);
        chmin(old,T.ask(1,0,n,0,a[i]-1)+1);
        chmin(old,T.ask(1,0,n,a[i]+1,n)+1);
        if(a[i]!=a[i-1]) T.add(1,0,n,0,n,1);
        int x=T.ask(1,0,n,a[i-1],a[i-1]);
        if(old<x) T.add(1,0,n,a[i-1],a[i-1],old-x);
    }
    printf("%d\n",T.ask(1,0,n,0,n));
    return 0;
}