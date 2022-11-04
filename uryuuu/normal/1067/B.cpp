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
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod = 998244353;
//#define int long long

vector<int>g[maxn];
int n,k;
int vis[maxn];
int dep1[maxn],dep2[maxn];
int p;
int mx=0;


void dfs1(int u,int fa)
{
    dep1[u]=dep1[fa]+1;
    if(dep1[u]>mx)
    {
        p=u;
        mx=dep1[u];
    }
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs1(v,u);
    }
}


void dfs2(int u,int fa)
{
    dep2[u]=dep2[fa]+1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs2(v,u);
    }
}

int f=0;

int dep[maxn];

void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    int sz=g[u].size();
    if(dep[u]==k&&sz!=1)
        f=1;
    if(fa==0)
        sz++;
    if(dep[u]<k&&sz<4)
        f=1;
    if(dep[u]>k)
        f=1;
    
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
    }
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
    if(n==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    int pos;
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1)
        {
            vis[i]=1;
            pos=i;
        }
    }
    mx=0;
    dep1[0]=-1;
    dep2[0]=-1;
    dfs1(pos,0);
    dfs2(p,0);
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        if(dep1[i]==k&&dep2[i]==k)
        {
            rt=i;
        }
    }
    if(rt==0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    f=0;
    dep[0]=-1;
    dfs(rt,0);
    if(f)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    
    return 0;
}