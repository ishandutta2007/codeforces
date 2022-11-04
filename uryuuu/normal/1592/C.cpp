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


ll a[maxn];
vector<int>g[maxn];
ll dp[maxn],f[maxn];
ll x;

void dfs(int u,int fa)
{
    dp[u]=a[u];
    f[u]=0;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
        if(f[v]==0)
            dp[u]=(dp[u]^dp[v]);
    }
    if(dp[u]==x)
    {
        f[u]=1;
    }
}

int main()
{
//    sync;
    int t;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        x=0ll;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            x=(x^a[i]);
        }
        
        int u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(x==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(k==2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        dfs(1,0);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=f[i];
        }
        if(sum>1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    return 0;
}