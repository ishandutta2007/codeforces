#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ls i*2
#define rs i*2+1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

struct SEGTREE
{
    int next[maxn*4+5][60];
    int t;
    void pu(int i)
    {
        rep(s,0,59) next[i][s]=next[ls][s]+next[rs][(s+next[ls][s])%60];
    }
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            rep(s,0,59) next[i][s]=1+(s%a[l]==0);
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(i);
        }
    }
    void change(int i,int l,int r,int pos,int x)
    {
        if(pos<=l && r<=pos)
        {
            rep(s,0,59) next[i][s]=1+(s%x==0);
            return;
        }
        if(r<pos || pos<l) return;
        int mid=(l+r)>>1;
        change(ls,l,mid,pos,x);
        change(rs,mid+1,r,pos,x);
        pu(i);
    }
    void ask(int i,int l,int r,int ql,int qr)
    {
        if(ql<=l && r<=qr)
        {
            t+=next[i][t%60];
            return;
        }
        if(qr<l || r<ql) return;
        int mid=(l+r)>>1;
        ask(ls,l,mid,ql,qr);
        ask(rs,mid+1,r,ql,qr);
    }
}t;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    t.build(1,1,n);
    int q; scanf("%d",&q);
    while(q--)
    {
        char opt[5];
        int x,y;
        scanf("%s%d%d",opt,&x,&y);
        if(opt[0]=='C') t.change(1,1,n,x,y);
        else
        {
            t.t=0;
            t.ask(1,1,n,x,y-1);
            printf("%d\n",t.t);
        }
    }
    return 0;
}