#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 20000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> pool[maxn+5];
int ans[maxn+5];

struct segtree
{
    #define ls i*2
    #define rs i*2+1

    vector<pii> item[maxn*4+5]; 
    void ins(int i,int l,int r,int ql,int qr,pii x)
    {
        if(ql<=l && r<=qr) 
        {
            item[i].pb(x); return;
        }
        if(r<ql || qr<l) return;
        int mid=(l+r)>>1;
        ins(ls,l,mid,ql,qr,x);
        ins(rs,mid+1,r,ql,qr,x);
    }
    void dfs(int i,int l,int r,vi A)
    {
        for(auto it: item[i])
        {
            int w=it.FI,v=it.SE;
            per(j,w,4000) if(A[j]<A[j-w]+v) A[j]=A[j-w]+v;
        }
        if(l==r)
        {
            for(auto it: pool[l]) ans[it.SE]=A[it.FI];
            return;
        }
        int mid=(l+r)>>1;
        dfs(ls,l,mid,A);
        dfs(rs,mid+1,r,A);
    }
}T;

int main()
{
    int n,p; scanf("%d%d",&n,&p);
    rep(i,1,n)
    {
        int w,v,t; scanf("%d%d%d",&w,&v,&t);
        T.ins(1,1,maxn,t,t+p-1,{w,v});
    }
    int Q; scanf("%d",&Q);
    rep(q,1,Q)
    {
        int a,b; scanf("%d%d",&a,&b);
        pool[a].pb({b,q});
    }
    T.dfs(1,1,maxn,vi(4001,0));
    rep(q,1,Q) printf("%d\n",ans[q]);
    return 0;
}