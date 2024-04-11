#include<bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=2e5+100;

vector<int> g[N];
bool used[N];

void init(int n)
{
    for(int i=1;i<=n;i++)
        used[i]=false;
}

int dfs(int v)
{
    if(used[v])
        return 0;
    used[v]=true;
    int ans=1;
    for(int to:g[v])
        ans+=dfs(to);
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        for(int i=1;i<=n;i++)
            g[i].clear();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        init(n);
        used[a]=true;
        int x=n-dfs(b)-1;
        init(n);
        used[b]=true;
        int y=n-dfs(a)-1;
        cout<<x*y<<"\n";
    }
}