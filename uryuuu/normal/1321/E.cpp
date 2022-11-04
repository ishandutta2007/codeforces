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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


struct node
{
    int w,cost;
}a[maxn],b[maxn];

struct nod
{
    int a,b,w;
}c[maxn];

bool cmp(node a,node b)
{
    return a.cost<b.cost;
}

bool cmp2(nod u,nod v)
{
    return u.a<v.a;
}


ll mx[maxn<<2],lazy[maxn<<2];

void pushup(int rt)
{
    mx[rt]=max(mx[lr],mx[rr]);
}

void build(int rt,int l,int r)//1,n,
{
    lazy[rt]=0;
    if(l==r)
    {
        mx[rt]=-b[l].cost;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}

void pushdown(int rt)//
{
    if(lazy[rt])
    {
        mx[lr]+=lazy[rt];
        lazy[lr]+=lazy[rt];
        mx[rr]+=lazy[rt];
        lazy[rr]+=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(L>R)
        return;
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        mx[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}


bool cmp3(node a,node b)
{
    if(a.w==b.w)
        return a.cost<b.cost;
    return a.w<b.w;
}

int bb[maxn];

int main()
{
    sync;
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].cost;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].w>>b[i].cost;
        bb[i]=b[i].w;
    }
    
    for(int i=1;i<=p;i++)
        cin>>c[i].a>>c[i].b>>c[i].w;
    
    
    sort(a+1,a+n+1,cmp);
    sort(c+1,c+p+1,cmp2);
    sort(b+1,b+m+1,cmp3);
    sort(bb+1,bb+m+1);
    
    build(1,1,m);
    
    int pos;
    int L=1;
    ll ans=-2e18;
    for(int i=1;i<=n;i++)
    {
        while(L<=p&&c[L].a<a[i].w)
        {
            pos=upper_bound(bb+1,bb+m+1,c[L].b)-bb;
            upd(1,1,m,pos,m,c[L].w);
            L++;
        }
        ans=max(ans,mx[1]-a[i].cost);
    }
    cout<<ans<<endl;
    
    
    return 0;
}