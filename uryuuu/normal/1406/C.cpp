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
//const ll Mod=1000000007;
const ll Mod=998244353;


int b[10];
int siz[maxn],a[maxn];
vector<int>g[maxn];
int mn,n;

void dfs(int u,int fa)
{
    siz[u]=1;
    int s=0;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
        siz[u]+=siz[v];
        s=max(s,siz[v]);
    }
    s=max(s,n-siz[u]);
    a[u]=s;
    mn=min(mn,s);
}

int main()
{
    sync;
    
    int t;
    cin>>t;
    while(t--)
    {
        int u,v;
        cin>>n;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        mn=1e9;
        dfs(1,0);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==mn)
            {
                b[++cnt]=i;
            }
        }
        if(cnt==1)
        {
            cout<<1<<' '<<g[1][0]<<endl;
            cout<<1<<' '<<g[1][0]<<endl;
            continue;
        }
        u=b[1];v=b[2];
        if(g[u].size()<g[v].size())
            swap(u,v);
        
        int x,mx=0;
        for(int i=0;i<g[u].size();i++)
        {
            if(g[u][i]!=v)
            {
                x=g[u][i];
                break;
            }
        }
        cout<<u<<' '<<x<<endl;
        cout<<v<<' '<<x<<endl;
    }
    
    return 0;
}