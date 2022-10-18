#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510,V=N*N,K=11,INF=1e18;

vector<pii> g[V];

int code(int i,int j)
{
    return i*N+j;
}

pair<int,int> pos(int c)
{
    return {c/N,c%N};
}

int dp[V][K];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    if(k%2)
    {
        for(int i=1;i<=n;i++,cout<<"\n")
            for(int j=1;j<=m;j++)
                cout<<-1<<" ";
        exit(0);
    }
    k/=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++)
        {
            int w;
            cin>>w;
            int u=code(i,j);
            int v=code(i,j+1);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
        {
            int w;
            cin>>w;
            int u=code(i,j);
            int v=code(i+1,j);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    for(int i=1;i<=k;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=m;y++)
            {
                int v=code(x,y);
                dp[v][i]=INF;
                for(auto[to,w]:g[v])
                    dp[v][i]=min(dp[v][i],dp[to][i-1]+w);
            }
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=m;j++)
            cout<<dp[code(i,j)][k]*2<<" ";
}