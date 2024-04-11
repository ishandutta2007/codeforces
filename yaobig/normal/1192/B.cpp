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

vi to[maxn+5];
pii e[maxn+5]; 
int lowson[maxn+5];
ll w[maxn+5],dis[maxn+5];

int tin[maxn+5],tout[maxn+5],p[maxn+5],tot;

void dfs(int now,int fa)
{
    tin[now]=++tot;
    p[tot]=now;
    for(auto i: to[now])
    {
        int v=now^e[i].FI^e[i].SE;
        if(v==fa) continue;
        dis[v]=dis[now]+w[i];
        dfs(v,now);
        lowson[i]=v;
        p[++tot]=now;
    }
    tout[now]=tot;
}

struct segtree
{
    #define ls rt*2
    #define rs rt*2+1
    ll a[maxn*4+5],x[maxn*4+5],ax[maxn*4+5],xa[maxn*4+5],axa[maxn*4+5];
    ll lz[maxn*4+5];
    void pu(int rt)
    {
        a[rt]=max(a[ls],a[rs]);
        x[rt]=max(x[ls],x[rs]);
        ax[rt]=max(ax[rs],max(ax[ls],a[ls]+x[rs]));
        xa[rt]=max(xa[ls],max(xa[rs],x[ls]+a[rs]));
        axa[rt]=max(max(axa[ls],axa[rs]),max(ax[ls]+a[rs],a[ls]+xa[rs]));
    }
    void push(int rt,ll val)
    {
        lz[rt]+=val;
        a[rt]+=val;
        x[rt]-=2*val;
        ax[rt]-=val;
        xa[rt]-=val;
    }
    void pd(int rt)
    {
        if(lz[rt])
        {
            push(ls,lz[rt]); push(rs,lz[rt]);
            lz[rt]=0;
        }
    }
    void build(int rt,int l,int r)
    {
        if(l==r)
        {
            int now=p[l];
            a[rt]=dis[now];
            x[rt]=-2*dis[now];
            ax[rt]=xa[rt]=-dis[now];
        }
        else
        {
            int mid=(l+r)>>1;
            build(ls,l,mid);
            build(rs,mid+1,r);
            pu(rt);
        }        
    }
    void add(int rt,int l,int r,int ql,int qr,ll val)
    {
        if(ql<=l && r<=qr) 
        {
            push(rt,val);
            return;
        }
        if(r<ql || qr<l) return;
        pd(rt);
        int mid=(l+r)>>1;
        add(ls,l,mid,ql,qr,val);
        add(rs,mid+1,r,ql,qr,val);
        pu(rt);
    }
}T;

int main()
{
    int n,q; ll W; scanf("%d%d%lld",&n,&q,&W);
    rep(i,0,n-2)
    {
        int x,y; scanf("%d%d%lld",&x,&y,&w[i]);
        e[i]={x,y}; 
        to[x].pb(i);
        to[y].pb(i);
    }
    dfs(1,0);
    T.build(1,1,tot);
    ll lastans=0;
    while(q--)
    {
        int id; ll nw; scanf("%d%lld",&id,&nw);
        id=(id+lastans)%(n-1);
        nw=(nw+lastans)%W;
        int now=lowson[id];
        //printf("? %d: %d %d %lld\n",now,tin[now],tout[now],nw-w[id]);
        T.add(1,1,tot,tin[now],tout[now],nw-w[id]);
        w[id]=nw;
        printf("%lld\n",T.axa[1]);
        lastans=T.axa[1];
    }
    return 0;
}