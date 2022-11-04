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
int dp[maxn];
int ans;
int b[maxn];
void dfs(int u,int fa)
{
    dp[u]=0;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        dfs(v,u);
    }
    int cnt=0;
    if(u==1)
        return;
    for(int v:g[u])
    {
        if(v==fa)
            continue;
        b[++cnt]=dp[v];
    }
    sort(b+1,b+cnt+1);
    for(int i=2;i<=cnt;i++)
    {
        ans=max(b[i]+2,ans);
    }
    if(cnt>=1)
        dp[u]=b[1]+1;
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
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=0;
        dfs(1,0);
        int cnt=0;
        for(int v:g[1])
        {
            b[++cnt]=dp[v];
        }
        sort(b+1,b+cnt+1);
        if(cnt>=1)
            ans=max(b[cnt]+1,ans);
        if(cnt>=2)
        {
            ans=max(b[cnt-1]+2,ans);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}