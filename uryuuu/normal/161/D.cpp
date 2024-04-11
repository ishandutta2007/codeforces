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


int n,k;
vector<int>g[maxn];

bool vis[maxn];
int siz[maxn],dep[maxn];

int dfssize(int u,int pre)
{
    siz[u]=1;
    for(int v:g[u])
    {
        if(v==pre||vis[v])
            continue;
        siz[u]+=dfssize(v,u);
    }
    return siz[u];
}

int minn;

void getroot(int u,int pre,int totnum,int &root)
{
    int maxx=totnum-siz[u];
    for(int v:g[u])
    {
        if(v==pre||vis[v])
        continue;
        getroot(v,u,totnum,root);
        maxx=max(maxx,siz[v]);
    }
    if(maxx<minn)
    {
        minn=maxx;
        root=u;
    }
}

int cnt=0;
int b[maxn];

void dfs2(int u,int fa)
{
    dep[u]=dep[fa]+1;
    b[++cnt]=dep[u];
    for(int v:g[u])
    {
        if(v==fa||vis[v])
            continue;
        dfs2(v,u);
    }
}

ll c[maxn];

ll calc(int u,int d)
{
    cnt=0;
    dfs2(u,0);
    sort(b+1,b+cnt+1);
    for(int i=1;i<=cnt;i++)
        b[i]+=d;
    int L=1,R=cnt;
    ll res=0;
    for(int i=1;i<=cnt;i++)
    {
        L=lower_bound(b+1,b+cnt+1,k-b[i])-b;
        R=upper_bound(b+1,b+cnt+1,k-b[i])-b-1;
        L=max(L,i+1);
        if(L<=R)
            res+=1ll*(R-L+1);
    }
    return res;
}


ll solve(int u)
{
    int total=dfssize(u,-1);
    int rt;
    minn=inf;
    getroot(u,-1,total,rt);
    vis[rt]=1;
    u=rt;
    ll ans=0ll;
    ans+=calc(u,0);
    for(int v:g[u])
    {
        if(vis[v])
            continue;
//        cout<<v<<' '<<u<<endl;
        ans-=calc(v,1);
    }
    for(int v:g[u])
    {
        if(vis[v])
            continue;
        ans+=solve(v);
    }
    return ans;
}


int main()
{
    sync;
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[0]=-1;
    cout<<solve(1)<<endl;
    return 0;
}