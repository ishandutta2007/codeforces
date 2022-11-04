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
//const ll Mod=1000000007;
//const ll Mod=998244353;

vector<int>g[maxn];
int dep[maxn];
int d[maxn];
int pa[maxn];

void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    pa[u]=fa;
    for(int v:g[u])
    {
        if(v==fa||dep[v])
            continue;
        dfs(v,u);
    }
}

int c[maxn][2];
vector<int>ansL,ansR;

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>c[i][0]>>c[i][1];
        d[c[i][0]]^=1;
        d[c[i][1]]^=1;
    }
    for(int i=1;i<=n;i++)
    {
        ans+=d[i];
    }
    if(ans>0)
    {
        cout<<"NO"<<endl;
        cout<<ans/2<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=q;i++)
    {
        u=c[i][0];
        v=c[i][1];
        ansL.clear();
        ansR.clear();
        while(u!=v)
        {
            if(dep[u]>dep[v])
            {
                ansL.push_back(u);
                u=pa[u];
            }
            else
            {
                ansR.push_back(v);
                v=pa[v];
            }
        }
        ansL.push_back(u);
        ans=0;
        ans+=ansL.size();
        ans+=ansR.size();
        cout<<ans<<' ';
        reverse(ansR.begin(),ansR.end());
        for(int v:ansL)
            cout<<v<<' ';
        for(int v:ansR)
            cout<<v<<' ';
        cout<<endl;
    }
    return 0;
}