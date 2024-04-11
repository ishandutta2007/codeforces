#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

namespace merge_segtree 
{
   struct node
    {
        ll a,tag;
        node *ls,*rs;
        node() {a=tag=0; ls=rs=NULL;}
    };
    void push(node *t,ll x)
    {
        t->a+=x; t->tag+=x;
    }
    void pu(node *t)
    {
        t->a=min(t->ls?t->ls->a:1ll<<60,t->rs?t->rs->a:1ll<<60);
    }
    void pd(node *t)
    {
        if(t->tag)
        {
            if(t->ls) push(t->ls,t->tag);
            if(t->rs) push(t->rs,t->tag);
            t->tag=0;
        }
    }
    void chg(node* &t,int l,int r,int p,ll x)
    {
        if(t==NULL) t=new node;
        if(l==r)
        {
            t->a=x;
            return;
        }
        pd(t);
        int mid=(l+r)>>1;
        if(p<=mid) chg(t->ls,l,mid,p,x);
        else chg(t->rs,mid+1,r,p,x);
        pu(t);
    }
    ll ask(node *t,int l,int r,int p)
    {
        if(l==r || t==NULL) return t?t->a:1ll<<60;
        pd(t);
        int mid=(l+r)>>1;
        if(p<=mid) return ask(t->ls,l,mid,p);
        else return ask(t->rs,mid+1,r,p);
    }
    node* merge(node* t1,node*t2)
    {
        if(t1==NULL) return t2; 
        if(t2==NULL) return t1; 
        pd(t1);
        pd(t2);
        t1->a=min(t1->a,t2->a);
        t1->ls=merge(t1->ls,t2->ls);
        t1->rs=merge(t1->rs,t2->rs);
        delete(t2);
        return t1;
    }
}
using namespace merge_segtree;

node* solve(int x,ll v,int s)
{
    node *rt=NULL;
    chg(rt,0,maxn,x,v);
    char op[10];
    while(~scanf("%s",op))
    {
        if(op[0]=='s')
        {
            int y,v; scanf("%d%d",&y,&v);
            ll mn=y==s?1ll<<60:rt->a;
            push(rt,v);
            chg(rt,0,maxn,y,mn);
        }
        else if(op[0]=='i')
        {
            int y; scanf("%d",&y);
            node* t1=solve(y,ask(rt,0,maxn,y),s);
            chg(rt,0,maxn,y,1ll<<60);
            rt=merge(rt,t1);
        }
        else if(op[0]=='e') return rt;
        else assert(0);
    }
    return rt;
}

int main()
{
    int n,s; scanf("%d%d",&n,&s);
    node* rt=solve(0,0,s);
    printf("%lld\n",rt->a);
    return 0;
}