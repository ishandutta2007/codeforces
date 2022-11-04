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
const ll Mod=998244353;
using namespace std;


vector<pii >g[maxn];

int n;
ll s=0;
int d0[maxn],d1[maxn],p1[maxn],p0[maxn];
void dfs(int u,int fa)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(v==fa)
            continue;
        dfs(v,u);
        if(w==1)
        {
            d1[u]+=d1[v]+1;
        }
        else
        {
            d0[u]+=d0[v]+1;
        }
    }
    
    
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(v==fa)
            continue;
        if(w==1)
        {
            s+=1ll*(d1[u]-d1[v]-1)*(d1[v]+1);
        }
        else
        {
            s+=1ll*(d0[u]-d0[v]-1)*(d0[v]+1);
        }
    }
    s+=1ll*(d0[u]+d1[u])*2;
    p0[u]=d0[u];
    p1[u]=d1[u];
}


void dfs2(int u,int fa)
{
    s+=1ll*p1[u]*p0[u];
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(v==fa)
            continue;
        if(w==1)
        {
            p1[v]=p1[u];
        }
        else
        {
            p0[v]=p0[u];
        }
        dfs2(v,u);
    }
}




int main()
{
    sync;
    cin>>n;
    int u,v,w;
    rep(i,2,n)
    {
        cin>>u>>v>>w;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }
    s=0;
    dfs(1,0);
    dfs2(1,0);
    cout<<s<<endl;
    return 0;
}