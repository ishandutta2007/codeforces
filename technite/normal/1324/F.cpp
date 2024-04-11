#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
vector<int> ans;
void dfs(int x,int p,vvi&adj,vl&dp,vi&col)
{
    dp[x]=col[x];
    for(auto node:adj[x])
    {
        if(node==p) continue;
        dfs(node,x,adj,dp,col);
        dp[x]+=max(0ll,dp[node]);
    }
}
void dfs1(int x,int p,vvi&adj,vl&dp,vi&col)
{
    ans[x]=dp[x];
    for(auto node:adj[x])
    {
        if(node==p) continue;
        dp[x]-=max(dp[node],0ll);
        dp[node]+=max(dp[x],0ll);
        dfs1(node,x,adj,dp,col);
        dp[node]-=max(dp[x],0ll);
        dp[x]+=max(dp[node],0ll);
    }
}
int main()
{
    int n;
    cin>>n;
    vi col(n);
    for(int i=0;i<n;i++)
    {
        cin>>col[i];
        if(col[i]==0) col[i]--;
    }
    vvi adj(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vl dp(n,0);
    ans=vector<int>(n,0);
    dfs(0,-1,adj,dp,col);
    dfs1(0,-1,adj,dp,col);
    for(auto x:ans) cout<<x<<" ";


}