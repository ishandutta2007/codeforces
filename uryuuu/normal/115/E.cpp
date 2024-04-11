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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn<<2];
ll lazy[maxn<<2];
ll dp[maxn];

void pushup(int rt)
{
    a[rt]=max(a[lr],a[rr]);
}

void pushdown(int rt)//
{
    if(lazy[rt])
    {
        a[lr]+=lazy[rt];
        lazy[lr]+=lazy[rt];
        a[rr]+=lazy[rt];
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
        a[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    upd(lr,l,mid,L,R,val);
    upd(rr,mid+1,r,L,R,val);
    pushup(rt);
}


ll query(int rt,int l,int r,int L,int R)
{
    if(L>R)
        return 0;
    if(r<L||l>R)
        return -1e16;
    if(r<=R&&l>=L)
    {
        return a[rt];
    }
    pushdown(rt);
    int mid=(l+r)/2;
    return max(query(lr,l,mid,L,R),query(rr,mid+1,r,L,R));
}

ll cost[maxn];
vector<pii>g[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n+1;i++)
        cin>>cost[i];
    int l,r;
    ll val;
    for(int i=1;i<=m;i++)
    {
        cin>>l>>r>>val;
        l++;
        r++;
        g[r].push_back(mkp(l,val));
    }
    n++;
    for(int i=2;i<=n;i++)
    {
        upd(1,1,n,1,i-1,-cost[i]);
        for(auto f:g[i])
        {
            l=f.first;
            val=f.second;
            upd(1,1,n,1,l-1,val);
        }
        dp[i]=max(dp[i-1],query(1,1,n,1,i-1));
        upd(1,1,n,i,i,dp[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}