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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=300005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn<<2];
int lazy[maxn<<2];
int len[maxn<<2];


void pushup(int rt)
{
    a[rt]=a[lr]+a[rr];
}

void build(int rt,int l,int r)//1,n,
{
    a[rt]=0;
    lazy[rt]=0;
    len[rt]=r-l+1;
    if(l==r)
    {
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
        a[lr]+=lazy[rt]*len[lr];
        lazy[lr]+=lazy[rt];
        a[rr]+=lazy[rt]*len[rr];
        lazy[rr]+=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L)
    {
        a[rt]+=val*len[rt];
        lazy[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}


int query(int rt,int l,int r,int L,int R)
{
    if(r<L||l>R)
        return 0;
    if(r<=R&&l>=L)
    {
        return a[rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    return query(lr,l,mid,L,R)+query(rr,mid+1,r,L,R);
}

int find0(int rt,int l,int r,int pos)
{
    if(l==r)
    {
        if(r<pos)
            return 0;
        if(a[rt]==0)
            return l;
        return 0;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid<pos||a[lr]==len[lr])
        return find0(rr,mid+1,r,pos);
    int ans=find0(lr,l,mid,pos);
    if(ans==0)
        ans=find0(rr,mid+1,r,pos);
    return ans;
}

int find1(int rt,int l,int r,int pos)
{
    if(l==r)
    {
        if(r<pos)
            return 0;
        if(a[rt]==1)
            return l;
        return 0;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mid<pos||a[lr]==0)
        return find1(rr,mid+1,r,pos);
    int ans=find1(lr,l,mid,pos);
    if(ans==0)
        ans=find1(rr,mid+1,r,pos);
    return ans;
}

int findans(int rt,int l,int r)
{
    if(l==r)
    {
        return l;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(a[rr])
        return findans(rr,mid+1,r);
    return findans(lr,l,mid);
}

int up=210000;

int b[maxn];
int pre[maxn];


int main()
{
//    sync;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        pre[b[i]]++;
    }
    
    build(1,1,up);

    for(int i=1;i<up;i++)
    {
        pre[i+1]+=pre[i]/2;
        pre[i]=pre[i]%2;
        if(pre[i])
        {
            upd(1,1,up,i,i,1);
        }
    }
    
    int id,x,pos;
    int l,r,mid;
    int sum;

    
    while(q--)
    {
        scanf("%d",&id);
        x=b[id];

        pos=find1(1,1,up,x);

        upd(1,1,up,pos,pos,-1);
        if(x<=pos-1)
            upd(1,1,up,x,pos-1,1);

        
        scanf("%d",&x);
        pos=find0(1,1,up,x);
        
        upd(1,1,up,pos,pos,1);
        if(x<=pos-1)
            upd(1,1,up,x,pos-1,-1);
        
        
        printf("%d\n",findans(1,1,up));
        b[id]=x;
    }
    
    
    return 0;
}