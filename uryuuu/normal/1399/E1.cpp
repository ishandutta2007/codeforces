#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int, ll> pii;
//const double pi=acos(-1);
const int maxn = 200010;
//const ll Mod=1000000007;
const ll Mod = 998244353;

vector<pii>g[maxn];
int siz[maxn];
struct node
{
    ll w,k;
}a[maxn];
int m=0;

void dfs(int u,int fa)
{
    siz[u]=0;
    int f=0;
    for(int i=0,sz=g[u].size();i<sz;i++)
    {
        int v=g[u][i].first;
        ll w=g[u][i].second;
        if(v==fa)
            continue;
        dfs(v,u);
        a[++m].w=w;
        a[m].k=siz[v];
        siz[u]+=siz[v];
        f++;
    }
    if(f==0)
        siz[u]=1;
}

ll t[maxn<<2];

void pushup(int rt)
{
    t[rt]=max(t[lr],t[rr]);
}

void build(int rt,int l,int r)
{
    t[rt]=0;
    if(l==r)
    {
        t[rt]=1ll*(a[l].w-a[l].w/2ll)*a[l].k;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
    return;
}

void upd(int rt,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        t[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(mid>=pos)
        upd(lr,l,mid,pos,val);
    else
        upd(rr,mid+1,r,pos,val);
    pushup(rt);
    return;
}

int query(int rt,int l,int r)
{
    if(l==r)
        return l;
    int mid=(l+r)/2;
    if(t[lr]>t[rr])
        return query(lr,l,mid);
    return query(rr,mid+1,r);
}



int main()
{
    int T;
    int n;
    ll S;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&S);
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        m=0;
        int u,v;
        ll w;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%lld",&u,&v,&w);
            g[u].push_back(mkp(v,w));
            g[v].push_back(mkp(u,w));
        }
        dfs(1,0);
        ll sum=0;
        for(int i=1;i<=m;i++)
        {
            sum=1ll*sum+1ll*a[i].w*a[i].k;
        }
//        cout<<sum<<endl;
        build(1,1,m);
        int round=0,pos;
//        for(int i=1;i<=m;i++)
//        {
//            cout<<a[i].w<<"*"<<a[i].k<<' ';
//        }
//        cout<<"="<<sum<<endl;
//        cout<<endl;
        while(sum>S)
        {
            pos=query(1,1,m);
            sum=1ll*sum-1ll*a[pos].w*a[pos].k;
            a[pos].w=1ll*a[pos].w/2ll;
            sum=1ll*sum+1ll*a[pos].w*a[pos].k;
            upd(1,1,m,pos,1ll*(a[pos].w-a[pos].w/2ll)*a[pos].k);
            round++;
//            for(int i=1;i<=m;i++)
//            {
//                cout<<a[i].w<<"*"<<a[i].k<<' ';
//            }
//            cout<<"="<<sum<<endl;
//            cout<<endl;
//            cout<<endl;
        }
        printf("%d\n",round);
    }
    
    return 0;
}