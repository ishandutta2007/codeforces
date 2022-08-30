#include <iostream>
#include <vector>
#include <algorithm>
#define uint long long int
#define N 100005
using namespace std;
vector<int> slo[N];
uint dp[N][2];
uint war[N];
int vis[N];
void dfs(int v)
{
    vis[v]=1;
    uint mplus=0, mmin=0;
    for(int i=0; i<slo[v].size(); i++)
    {
        int aktv=slo[v][i];
        if(vis[aktv]==0)
        {
            dfs(aktv);
            mplus=max(mplus, dp[aktv][0]);
            mmin=max(mmin, dp[aktv][1]);
        }
    }
    int zonk=war[v]+mplus-mmin;
    if(zonk>0)
    {
        dp[v][0]=mplus;
        dp[v][1]=mmin+zonk;
    }
    else
    {
        dp[v][0]=mplus-zonk;
        dp[v][1]=mmin;
    }
    return;
}
        
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>war[i];
    }
    dfs(1);
    cout<<dp[1][0]+dp[1][1]<<endl;
    return 0;
}