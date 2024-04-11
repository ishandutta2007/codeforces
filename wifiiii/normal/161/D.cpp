
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int dp[50005][505];
vector<int> g[55555];
ll ans=0;
int n,k;
void dfs(int u,int fa)
{
    dp[u][0] = 1;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        for(int i=0;i<k;++i) ans += 1ll * dp[u][i] * dp[v][k-1-i];
        for(int i=0;i<k;++i) dp[u][i+1] += dp[v][i];
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;
}