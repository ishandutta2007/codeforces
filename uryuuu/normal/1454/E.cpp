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
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;

vector<int>g[maxn];
int st[maxn];
int vis[maxn];
int top=0;
int cnt=0;
int f[maxn];
int fl=0;
int lp[maxn];
int sz[maxn];

void dfs(int u,int fa)
{
    st[++top]=u;
    vis[u]=1;
    if(fl)
        return;
    for(int v:g[u])
    {
        if(fl)
            return;
        if(v==fa)
            continue;
        if(vis[v]==1)
        {
            fl=1;
//            cout<<u<<' '<<top<<endl;
            while(st[top]!=v)
            {
                lp[st[top]]=1;
                top--;
            }
            lp[v]=1;
            return;
        }
        dfs(v,u);
    }
    top--;
    return;
}

void dfs2(int u,int fa)
{
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        if(lp[v])
            continue;
        dfs2(v,u);
        sz[u]+=sz[v];
    }
    return;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int u,v;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
            lp[i]=0;
            sz[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        top=0;
        cnt=0;
        fl=0;
        dfs(1,0);
        ll ans=1ll*n*(n-1);
        for(int i=1;i<=n;i++)
        {
            if(lp[i])
            {
                dfs2(i,0);
                ans=1ll*ans-1ll*sz[i]*(sz[i]-1)/2;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}