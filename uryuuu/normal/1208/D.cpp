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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

ll a[maxn],b[maxn];
struct node
{
    ll zx,lazy;
    int l,r;
}t[maxn<<2];

void pushup(int rt)
{
    t[rt].zx=min(t[lr].zx,t[rr].zx);
}

void pushdown(int rt)
{
    ll x=t[rt].lazy;
    t[lr].lazy+=x;
    t[rr].lazy+=x;
    t[lr].zx+=x;
    t[rr].zx+=x;
    t[rt].lazy=0;
}

int query(int rt)
{
    if(t[rt].l==t[rt].r)
        return t[rt].l;
    if(t[rt].lazy)
        pushdown(rt);
    if(t[rr].zx==0)
        return query(rr);
    return query(lr);
}

void update(int rt,int L,int R,ll val)
{
    if(t[rt].l>=L&&t[rt].r<=R)
    {
        t[rt].lazy+=val;
        t[rt].zx+=val;
        return;
    }
    if(t[rt].lazy)
        pushdown(rt);
    int mid=(t[rt].l+t[rt].r)/2;
    if(mid>=L)
        update(lr,L,R,val);
    if(mid+1<=R)
        update(rr,L,R,val);
    pushup(rt);
    return;
}

void build(int rt,int l,int r)
{
    t[rt].l=l;
    t[rt].r=r;
    if(l==r)
    {
        t[rt].zx=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int pos=query(1);
        b[pos]=i;
        if(pos<n)
            update(1,pos+1,n,-i);
        update(1,pos,pos,2e15);
    }
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}