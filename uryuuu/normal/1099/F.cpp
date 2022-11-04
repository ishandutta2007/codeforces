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
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1000010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int p[maxn];
ll lv[maxn];
ll t[maxn];
ll dp[maxn];
ll s[maxn];
ll T;
ll m;
ll b[maxn];

vector<int>g[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

ll a[maxn<<2],c[maxn<<2];

void pushup(int rt)   //
{
    a[rt]=1ll*a[lr]+a[rr];
    c[rt]=1ll*c[lr]+c[rr];
}

void build(int rt,int l,int r)// 1n
{
    if(l==r)
    {
        a[rt]=0ll;
        c[rt]=0ll;
        return ;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}

ll query(int rt,ll l,ll r,ll st)
{
    if(st>=a[rt])
    {
        return c[rt];
    }
    if(l==r)
    {
        return 1ll*min(c[rt],1ll*st/l);
    }
    ll mid=(l+r)/2;
    if(a[lr]<st)
    {
        st-=a[lr];
        return 1ll*c[lr]+query(rr,mid+1,r,st);
    }
    return 1ll*query(lr,l,mid,st);
}

void update(int rt,ll l,ll r,ll pos,ll val)//,,lazy pushdown
{
    if(l==r)
    {
        a[rt]=1ll*a[rt]+1ll*val*l;
        c[rt]=1ll*c[rt]+1ll*val;
        return;
    }
    ll mid=(l+r)/2;
    if(pos<=mid)
        update(lr,l,mid,pos,val);
    else
        update(rr,mid+1,r,pos,val);
    pushup(rt); //
    return;
}


void dfs(int u,int fa,ll st)
{
    int v;
    update(1,1ll,m,t[u],s[u]);
    dp[u]=query(1,1ll,m,st);
    int cnt=0;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        dfs(v,u,st-lv[v]);
    }
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        b[cnt++]=dp[v];
    }
    b[cnt++]=0ll;
    b[cnt++]=0ll;
    sort(b,b+cnt,cmp);
    if(u==1)
    {
        dp[u]=max(dp[u],b[0]);
    }
    else
    {
        dp[u]=max(dp[u],b[1]);
    }
    update(1,1ll,m,t[u],-s[u]);
    return;
}


int main()
{
    sync;
    int n;
    cin>>n>>T;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        g[p[i]].push_back(i);
        cin>>lv[i];
        lv[i]=2ll*lv[i];
    }
    
    m=1ll*1e6+5;
    build(1,1,m);
    dfs(1,0,T);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<dp[i]<<' ';
//    }
//    cout<<endl;
    cout<<dp[1]<<endl;
    return 0;
}