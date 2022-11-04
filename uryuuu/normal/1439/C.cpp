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
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn<<2],lazy[maxn<<2],mn[maxn<<2],mx[maxn<<2];
ll zuo[maxn<<2],you[maxn<<2];

void pushup(int rt)
{
    a[rt]=a[lr]+a[rr];
    mn[rt]=min(mn[lr],mn[rr]);
    mx[rt]=max(mx[lr],mx[rr]);
}

void build(int rt,int l,int r)//1,n,
{
    lazy[rt]=0;
    zuo[rt]=l;
    you[rt]=r;
    if(l==r)
    {
        ll x;
        scanf("%lld",&x);
        a[rt]=x;
        mn[rt]=x;
        mx[rt]=x;
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
        mn[lr]=lazy[rt];
        mn[rr]=lazy[rt];
        mx[lr]=lazy[rt];
        mx[rr]=lazy[rt];
        a[lr]=1ll*(you[lr]-zuo[lr]+1ll)*lazy[rt];
        lazy[lr]=lazy[rt];
        a[rr]=1ll*(you[rr]-zuo[rr]+1ll)*lazy[rt];
        lazy[rr]=lazy[rt];
        lazy[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,ll val)
{
    if(r<L||l>R)
        return;
    if(r<=R&&l>=L&&mx[rt]<val)
    {
        mn[rt]=val;
        mx[rt]=val;
        a[rt]=1ll*(you[rt]-zuo[rt]+1ll)*val;
        lazy[rt]=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    if(mn[lr]<val)
        upd(lr,l,mid,L,R,val);
    if(mn[rr]<val)
        upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}

int n;

ll lv;
int sum;

void query(int rt,int l,int r,int L,int R)
{
    if(r<L)
        return;
    if(l>R)
        return;
    if(L<=l&&r<=R&&a[rt]<=lv)
    {
        sum+=(you[rt]-zuo[rt]+1);
        lv-=a[rt];
        return;
    }
    if(l==r)
        return;
    int mid=(l+r)/2;
    pushdown(rt);
    if(mn[lr]<=lv)
        query(lr,l,mid,L,R);
    if(mn[rr]<=lv)
        query(rr,mid+1,r,L,R);
    pushup(rt);
}

int main()
{
//    sync;
    int q;
    scanf("%d%d",&n,&q);
    build(1,1,n);
    int op,x;
    ll y;
    while(q--)
    {
        scanf("%d%d%lld",&op,&x,&y);
        if(op==1)
        {
            upd(1,1,n,1,x,y);
        }
        else
        {
            lv=y;
            sum=0;
            query(1,1,n,x,n);
            printf("%d\n",sum);
        }
    }
    
    return 0;
}