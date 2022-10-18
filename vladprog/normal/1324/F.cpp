#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

int a[N];
vector<int> g[N];
map<int,int> dp[N];
multiset<int> s[N];

int dfs1(int v,int p)
{
    for(int to:g[v])
        if(to!=p)
            s[v].insert(dfs1(to,v));
    int res=a[v];
    for(int x:s[v])
        if(x>0)
            res+=x;
    return dp[v][p]=res;
}

void dfs2(int v,int p)
{
    int sum=a[v];
    for(int x:s[v])
        if(x>0)
            sum+=x;
    dp[v][-1]=sum;
    for(int to:g[v])
        if(to!=p)
        {
            int cur=sum;
            int sub=dp[to][v];
            if(sub>0)
                cur-=sub;
            dp[v][to]=cur;
            s[to].insert(cur);
            dfs2(to,v);
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        a[i]=(a[i]?1:-1);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++)
        cout<<dp[i][-1]<<" ";
}