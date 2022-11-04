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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1e9+7;

ll s[maxn];
ll a[maxn];
ll p[maxn];
ll pos[maxn];
ll t[maxn<<2];
ll lazy[maxn<<2];

void pushup(int rt)
{
    t[rt]=min(t[lr],t[rr]);
}

void pushdown(int rt)
{
    t[lr]+=lazy[rt];
    lazy[lr]+=lazy[rt];
    t[rr]+=lazy[rt];
    lazy[rr]+=lazy[rt];
    lazy[rt]=0;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        t[rt]=s[l];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
    return;
}

void update(int rt,int l,int r,int val,int L,int R)
{
    if(l>=L&&r<=R)
    {
        t[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    if(lazy[rt])
        pushdown(rt);
    int mid=(l+r)/2;
    if(mid>=L)
        update(lr,l,mid,val,L,R);
    if(mid+1<=R)
        update(rr,mid+1,r,val,L,R);
    pushup(rt);
    return;
}

int main()
{
    sync;
    int n;
    cin>>n;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        s[i]=p[i]+s[i-1];
    }
    build(1,1,n-1);
    ll zx=min(t[1],p[n]);
    ll x;
    for(int i=1;i<n;i++)
    {
        x=pos[i];
        if(x!=1)
        {
            update(1,1,n-1,p[x],1,x-1);
        }
        if(x!=n)
        {
            update(1,1,n-1,-p[x],x,n-1);
        }
        zx=min(zx,t[1]);
    }
    cout<<zx<<endl;
    return 0;
}