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

int c[maxn];
vector<int>g[maxn];
ll ans[maxn];
int sz[maxn];
int cnt[maxn];
ll sum[maxn];

void dfs(int u,int fa)
{
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}

int top,Son;

void add(int u,int fa,int x)
{
    sum[cnt[c[u]]]-=1ll*c[u];
    cnt[c[u]]+=x;
    sum[cnt[c[u]]]+=1ll*c[u];
    if(sum[top+1])
        top++;
    if(sum[top]==0)
        top--;
    for(int v:g[u])
    {
        if(v==fa||v==Son)
            continue;
        add(v,u,x);
    }
}

void dfs2(int u,int fa,int keep)
{
    int son=-1,mx=-1;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        if(sz[v]>mx)
        {
            mx=sz[v];
            son=v;
        }
    }
    for(int v:g[u])
    {
        if(v==fa||v==son)
            continue;
        dfs2(v,u,0);
    }
    if(son!=-1)
    {
        dfs2(son,u,1);
    }
    Son=son;
    add(u,fa,1);
    ans[u]=sum[top];
    Son=-1;
    if(keep==0)
    {
        add(u,fa,-1);
    }
}

int main()
{
    sync;
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sum[0]=1e15;
    top=0;
    dfs(1,0);
    dfs2(1,0,1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}