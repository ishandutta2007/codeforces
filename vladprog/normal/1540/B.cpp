#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=210,MOD=1e9+7;

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
const int inv2=ppow(2,MOD-2);

vector<int> g[N];
int dist[N][N];

void dfs(int v,int p,int s,int d)
{
    dist[s][v]=d;
    for(int to:g[v])
        if(to!=p)
            dfs(to,v,s,d+1);
}

int dp[N][N],add[N];

bool on_path[N];

int calc(int v,int p)
{
    int res=1;
    for(int to:g[v])
        if(to!=p&&!on_path[to])
            res+=calc(to,v);
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        dfs(i,-1,i,0);
    for(int j=1;j<=n;j++)
        dp[0][j]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])*inv2%MOD;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            vector<int> path;
            for(int k=1;k<=n;k++)
                if(dist[i][k]+dist[k][j]==dist[i][j])
                    path.push_back(k);
            for(int k=1;k<=n;k++)
                on_path[k]=false;
            for(int k:path)
                on_path[k]=true;
            for(int k:path)
                ans=(ans+calc(k,-1)*dp[dist[j][k]][dist[i][k]])%MOD;
        }
    cout<<ans*ppow(n,MOD-2)%MOD;
}