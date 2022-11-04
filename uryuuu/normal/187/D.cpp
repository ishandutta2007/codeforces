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
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll l[maxn],pre[maxn],b[maxn],dp[maxn];
ll d[maxn];
ll mn[maxn];

void pushup(int rt)
{
    mn[rt]=min(mn[lr],mn[rr]);
}

void build(int rt,int l,int r)
{
    mn[rt]=1e9;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
}

void upd(int rt,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        mn[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        upd(lr,l,mid,pos,val);
    else
        upd(rr,mid+1,r,pos,val);
    pushup(rt);
}

ll qry(int rt,int l,int r,int L,int R)
{
    if(l>R||r<L)
        return 1e9;
    if(L<=l&&r<=R)
        return mn[rt];
    int mid=(l+r)/2;
    return min(qry(lr,l,mid,L,R),qry(rr,mid+1,r,L,R));
}

ll t,tr,tg;
int n;

ll gt(ll L,ll R)
{
    ll x=lower_bound(b+1,b+n+1,L)-b;
    ll y=lower_bound(b+1,b+n+1,R)-b;
    if(b[y]>R)
        y--;
    if(y==n+1)
        y--;
    if(x>y)
        return 1e9;
    return qry(1,1,n,x,y);
}


ll fnd(ll x)
{
    ll res=1e9,L,R;
    if(x==0)
        x=t;
    if(x<=tg)
    {
        L=tg-x;
        R=t-x-1;
        res=min(res,gt(L,R));
    }
    else
    {
        L=0;R=t-x-1;
        res=min(res,gt(L,R));
        L=tg-x+t;R=t-1;
        res=min(res,gt(L,R));
    }
    return res;
}


int main()
{
    sync;
    cin>>n>>tg>>tr;
    t=tr+tg;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
        pre[i]=pre[i-1]+l[i];
        b[i]=pre[i]%t;
    }
    cin>>l[n+1];
    pre[n+1]=pre[n]+l[n+1];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        d[i]=lower_bound(b+1,b+n+1,pre[i]%t)-b;
    }
    build(1,1,n);
    dp[n]=l[n+1];
    upd(1,1,n,d[n],n);
    ll x,h;
    for(int i=n-1;i>=1;i--)
    {
        x=fnd(t-b[d[i]]);
        if(x==1e9)
            dp[i]=pre[n+1]-pre[i];
        else
        {
            h=(pre[x]-pre[i]-1)/t+1;
            dp[i]=dp[x]+h*t;
        }
        upd(1,1,n,d[i],i);
    }
    int q;
    cin>>q;
    ll y,ans;
    while(q--)
    {
        cin>>x;
        y=fnd(x%t);
        if(y==1e9)
            ans=x+pre[n+1];
        else
        {
            h=(pre[y]+x-1)/t+1;
            ans=dp[y]+h*t;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}