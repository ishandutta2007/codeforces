#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int n,k,a[5][MAXN],dp[MAXN],mx;
vector<int> pos[MAXN],g[MAXN];
bool vis[MAXN];
void dfs(int i)
{
    vis[i]=true;
    for(int j=0;j<g[i].size();j++)
    {
        if(!vis[g[i][j]]) dfs(g[i][j]);
        dp[i]=max(dp[i],dp[g[i][j]]+1);
    }
    dp[i]=max(dp[i],1);
    mx=max(mx,dp[i]);
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            pos[a[i][j]].push_back(j);
        }
    }
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=n;y++)
        {
            bool ok=true;
            for(int i=0;i<k;i++) if(pos[x][i]>=pos[y][i]) ok=false;
            if(ok) g[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    cout<<mx;
    return 0;
}