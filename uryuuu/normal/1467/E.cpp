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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

vector<int>g[maxn];
map<int,int>mp,vis;
int a[maxn];
int dfn[maxn];
int out[maxn];
int d[maxn];
int tot;

void dfs(int u,int fa)
{
    dfn[u]=++tot;
    int now=vis[a[u]];
    vis[a[u]]++;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        int now2=vis[a[u]];
        dfs(v,u);
        if(vis[a[u]]>now2)
        {
            d[1]++;
            d[dfn[v]]--;
            d[out[v]+1]++;
        }
    }
    out[u]=tot;
    if(vis[a[u]]-now<mp[a[u]])
    {
        d[dfn[u]]++;
        d[out[u]+1]--;
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
        mp[a[i]]++;
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tot=0;
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=tot;i++)
    {
        d[i]=d[i-1]+d[i];
        if(d[i]==0)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}