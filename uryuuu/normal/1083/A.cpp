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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;
//#define int long long

vector<pii>g[maxn];
ll a[maxn];
ll dp[maxn];

void dfs(int u,int fa)
{
    int v;
    ll w;
    ll mx=0;
    dp[u]=a[u];
    for(auto f:g[u])
    {
        v=f.first;
        w=f.second;
        if(v==fa)
            continue;
        dfs(v,u);
        if(w<dp[v])
        {
            mx=max(mx,1ll*(dp[v]-w));
        }
    }
    dp[u]+=1ll*mx;
}

ll ans;

ll b[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

void dfs2(int u,int fa)
{
    int v;
    ll w;
    ll mx=0;
    int cnt=0;
    ans=max(ans,dp[u]);
    for(auto f:g[u])
    {
        v=f.first;
        w=f.second;
        if(v==fa)
            continue;
        if(w<dp[v])
        {
            b[++cnt]=1ll*(dp[v]-w);
        }
    }
    sort(b+1,b+cnt+1,cmp);
    if(cnt>=2)
    {
        ans=max(ans,dp[u]+b[2]);
    }
    for(auto f:g[u])
    {
        v=f.first;
        if(v==fa)
            continue;
        dfs2(v,u);
    }
}


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int u,v;
    ll w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(mkp(v,w));
        g[v].push_back(mkp(u,w));
    }
    dfs(1,0);
    ans=0;
    dfs2(1,0);
    cout<<ans<<endl;
    
    return 0;
}