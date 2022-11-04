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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
//const ll Mod=1000000007;
const ll Mod=998244353;

vector<int>g[maxn];
int dfn[maxn],dep[maxn],d[maxn];
int ed;
int vis[maxn],ans[maxn],fa[maxn];
int del[maxn];

void dfs(int u)
{
    for(int v:g[u])
    {
        dep[v]=dep[u]+1;
        dfs(v);
    }
}

int tot=0;

void dfs2(int u)
{
    dfn[++tot]=u;
    for(int v:g[u])
    {
        if(vis[v])
            continue;
        dfs2(v);
        dfn[++tot]=u;
    }
    for(int v:g[u])
    {
        if(vis[v]==0)
            continue;
        dfs2(v);
        dfn[++tot]=u;
    }
}


int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int u;
        for(int i=1;i<=n;i++)
        {
            d[i]=0;
            g[i].clear();
            vis[i]=0;
            del[i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            cin>>u;
            g[u].push_back(i);
            d[u]++;
            fa[i]=u;
        }
        dfs(1);
        int mx=-1;
        for(int i=1;i<=n;i++)
        {
            if(mx<dep[i])
            {
                ed=i;
                mx=dep[i];
            }
        }
        int cnt=0;
        u=ed;
        while(u)
        {
            ans[++cnt]=u;
            vis[u]=1;
            u=fa[u];
        }
        reverse(ans+1,ans+cnt+1);
        if(k<=cnt)
        {
            cout<<k-1<<endl;
            for(int i=1;i<=k;i++)
            {
                cout<<ans[i]<<' ';
            }
            cout<<endl;
            continue;
        }
        tot=0;
        dfs2(1);
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==0&&vis[i]==0)
            {
                q.push(i);
            }
        }
        
        int sum=n-k;
        
        while(q.size())
        {
            u=q.front();
            q.pop();
            if(sum<=0)
                break;
            del[u]=1;
            sum--;
            if(sum<=0)
                break;
            d[fa[u]]--;
            if(d[fa[u]]==0&&vis[fa[u]]==0)
            {
                q.push(fa[u]);
            }
        }
        
        int sz=0;
        
        for(int i=1;i<=tot;i++)
        {
            if(del[dfn[i]]||(i>=2&&del[dfn[i-1]]==1))
                continue;
            sz++;
            if(dfn[i]==ed)
                break;
        }
        cout<<sz-1<<endl;
        for(int i=1;i<=tot;i++)
        {
            if(del[dfn[i]]||(i>=2&&del[dfn[i-1]]==1))
                continue;
            cout<<dfn[i]<<' ';
            if(dfn[i]==ed)
                break;
        }
        
    }
    
    return 0;
}