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
//#include <chrono>
//#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

struct node
{
    int u,v;
}e[100005];

vector<int>g[maxn];
string s[100005];

int dfn[maxn],low[maxn],vis[maxn],st[maxn],scc[maxn];
int cnt,tot,L,p;

void dfs(int u)
{
    dfn[u]=low[u]=++tot;
    vis[u]=1;
    st[L++]=u;
    for(int v:g[u])
    {
        if(vis[v]==0)
        {
            dfs(v);
            low[u]=min(low[v],low[u]);
        }
        else if(vis[v]==1)
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        int v;
        cnt++;;
        do
        {
            v=st[L-1];
            L--;
            scc[v]=cnt;
            vis[v]=2;
        }while(u!=v);
    }
}

int tarjan()
{
    L=tot=cnt=0;
    mm(vis);
    dfs(0);
    return cnt;
}


int dfs2(int u)
{
    if(dfn[u]!=-1)
        return dfn[u];
    dfn[u]=0;
    for(int v:g[u])
        dfn[u]=max(dfn[u],dfs2(v));
    dfn[u]+=low[u];
    return dfn[u];
}

unordered_map<int,int>mp;

int main()
{
    sync;
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=0;i<m;i++)
    {
        cin>>e[i].u>>e[i].v;
    }
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int u,v;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<d;j++)
        {
            u=(e[i].u-1)*d+j;
            v=(e[i].v-1)*d+(j+1)%d;
            g[u].push_back(v);
        }
    }
    p=tarjan();
    for(int i=0;i<n*d;i++)
    {
        g[i].clear();
        g[i].shrink_to_fit();
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<d;j++)
        {
            u=(e[i].u-1)*d+j;
            v=(e[i].v-1)*d+(j+1)%d;
            if(scc[u]==0||scc[v]==0)
                continue;
            if(scc[u]==scc[v])
                continue;
            g[scc[u]].push_back(scc[v]);
        }
    }
    mm(low);
    memset(dfn,-1,sizeof(dfn));
    int c;
    for(int i=0;i<n;i++)
    {
        mp.clear();
        for(int j=0;j<d;j++)
        {
            if(s[i][j]=='0')
                continue;
            c=scc[i*d+j];
            if(c==0)
                continue;
            mp[c]++;
        }
        for(auto f:mp)
        {
            low[f.first]++;
        }
    }
    mm(vis);
    cout<<dfs2(scc[0])<<endl;
    
    return 0;
}