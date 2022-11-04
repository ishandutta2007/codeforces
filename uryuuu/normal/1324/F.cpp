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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
 

int a[maxn];
vector<int>g[maxn];
int d[maxn];

void dfs1(int u,int fa)
{
    int v;
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        dfs1(v,u);
    }
    for(int i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(v==fa)
            continue;
        d[u]=max(d[u]+d[v],d[u]);
    }
    return;
}

 void dfs2(int u,int fa)
 {
     int v;
     if(d[u]<0)
     {
        d[u]=max(d[fa]-1,d[u]);
     }
     else
     {
        d[u]=max(d[fa],d[u]);
     }
     for(int i=0;i<g[u].size();i++)
     {
         v=g[u][i];
         if(v==fa)
             continue;
         dfs2(v,u);
     }
     return;
 }

int main()
{
    sync;
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
            d[i]=1;
        else
            d[i]=-1;
    }
    d[0]=-1;
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<' ';
    cout<<endl;
    return 0;
}