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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],p[maxn];

bool cmp(int u,int v)
{
    return a[u]<a[v];
}

int lazy[maxn<<2];
int mx[maxn<<2];
int mn[maxn<<2];

void pushup(int rt)
{
    mx[rt]=max(mx[lr],mx[rr]);
    mn[rt]=min(mn[lr],mn[rr]);
}

void build(int rt,int l,int r)
{
    lazy[rt]=0;
    if(l==r)
    {
        mx[rt]=mn[rt]=l;
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
    return;
}

void pushdown(int rt)
{
    mn[lr]+=lazy[rt];
    mx[lr]+=lazy[rt];
    mn[rr]+=lazy[rt];
    mx[rr]+=lazy[rt];
    lazy[lr]+=lazy[rt];
    lazy[rr]+=lazy[rt];
    lazy[rt]=0;
}

void upd(int rt,int l,int r,int pos,int val)
{
    if(r<pos)
        return;
    if(l>=pos)
    {
        mx[rt]+=val;
        mn[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,pos,val);
    upd(rr,mid+1,r,pos,val);
    pushup(rt);
    return;
}

int querymn(int rt,int l,int r,int L,int R)
{
    if(L>R)
        return 0;
    if(l>=L&&r<=R)
    {
        return mn[rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid<L)
        return querymn(rr,mid+1,r,L,R);
    else if(mid+1>R)
        return querymn(lr,l,mid,L,R);
    return min(querymn(rr,mid+1,r,L,R),querymn(lr,l,mid,L,R));
}

int querymx(int rt,int l,int r,int L,int R)
{
    if(L>R)
        return 0;
    if(l>=L&&r<=R)
        return mx[rt];
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid<L)
        return querymx(rr,mid+1,r,L,R);
    else if(mid+1>R)
        return querymx(lr,l,mid,L,R);
    return max(querymx(rr,mid+1,r,L,R),querymx(lr,l,mid,L,R));
}

vector<int>g[maxn];
int ans[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=i;
        g[a[i]].push_back(i);
        ans[i]=0;
    }
    
    sort(p+1,p+n+1,cmp);
    int w;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(a[p[i]]!=a[p[i-1]])
            for(int v:g[a[p[i]]])
            {
                upd(1,1,n,v,-2);
            }
        w=querymn(1,1,n,p[i],n)-max(0,querymx(1,1,n,1,p[i]-1));
        w=-w;
        ans[p[i]]=max(ans[p[i]],(w-1)/2);
        
    }
    
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(a[p[i]]!=a[p[i-1]])
            for(int v:g[a[p[i-1]]])
            {
                upd(1,1,n,v,-2);
            }
        w=querymx(1,1,n,p[i],n)-min(0,querymn(1,1,n,1,p[i]-1));
//        cout<<p[i]<<' '<<w<<' '<<querymx(1,1,n,p[i],n)<<' '<<querymn(1,1,n,1,p[i]-1)<<endl;
        ans[p[i]]=max(ans[p[i]],w/2);
    }
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    
    return 0;
}