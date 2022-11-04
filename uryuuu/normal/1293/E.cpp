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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=3005;
const ll Mod=1000000007;

vector<int>g[maxn];
int n,f[maxn][maxn];
ll ans,cnt[maxn][maxn],dp[maxn][maxn];

void dfs(int root,int u,int fa)
{
    cnt[root][u]++;
    f[root][u]=fa;
    {
        for(auto t:g[u])
        {
            if(t!=fa)
            {
                dfs(root,t,u);
                cnt[root][u]+=cnt[root][t];
            }
        }
    }
}

ll solve(int a,int b)
{
    if(a==b)
        return 0;
    if(dp[a][b]!=-1)
        return dp[a][b];
    return dp[a][b]=cnt[a][b]*cnt[b][a]+max(solve(f[a][b],a),solve(f[b][a],b));
}


int main()
{
    sync;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        dfs(i,i,-1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                ans=max(ans,solve(i,j));
        }
    cout<<ans<<endl;
    return 0;
}