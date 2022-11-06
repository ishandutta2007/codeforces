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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
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
const ll Mod=998244353;
   

struct node
{
    int u,v,f;
    ll w;
}e[maxn];

int fa[maxn];

int findx(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findx(fa[x]);
}

int vis[maxn];
int n,m;
vector<int>now;
set<int>all,g[maxn];

int cnt=0;

void init()
{
    queue<int>q;
    int u;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        q.push(i);
        vis[i]=1;
        all.erase(i);
        while(q.size())
        {
            u=q.front();
            q.pop();
            now.clear();
            for(auto v:all)
            {
                if(vis[v]||g[u].count(v))
                    continue;
                q.push(v);
                now.push_back(v);
                vis[v]=1;
                fa[v]=u;
                cnt++;
            }
            for(int v:now)
                all.erase(v);
        }
    }
}

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int main()
{
    sync;
    cin>>n>>m;
    ll w;
    ll sum=0;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        sum^=e[i].w;
        g[e[i].u].insert(e[i].v);
        g[e[i].v].insert(e[i].u);
    }
    
    for(int i=1;i<=n;i++)
    {
        all.insert(i);
        fa[i]=i;
    }
    init();
    sort(e+1,e+m+1,cmp);
    int u,v,fu,fv;
    ll ans=0ll;
    for(int i=1;i<=m;i++)
    {
        fu=findx(e[i].u);
        fv=findx(e[i].v);
        if(fu==fv)
            continue;
        fa[fu]=fv;
        ans+=e[i].w;
        e[i].f=1;
    }
    
    if(cnt+m<1ll*n*(n-1)/2)
    {
        cout<<ans<<endl;
        return 0;
    }
    
    for(int i=1;i<=n;i++)
        fa[i]=i;
    ll mn=sum;
    for(int i=1;i<=m;i++)
    {
        fu=findx(e[i].u);
        fv=findx(e[i].v);
        if(fu==fv)
            continue;
        fa[fu]=fv;
        if(e[i].f)
            continue;
        mn=min(mn,e[i].w);
        break;
    }
    ans+=mn;
    cout<<ans<<endl;
    
    return 0;
}