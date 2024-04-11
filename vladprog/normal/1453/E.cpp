#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e9;

vector<int> g[N];
int ans;

int dfs(int v,int p)
{
    int mn=INF;
    int mx=0;
    for(int to:g[v])
        if(to!=p)
        {
            int cur=dfs(to,v)+1;
            mn=min(mn,cur);
            if(p==-1)
            {
                ans=max(ans,min(cur,mx)+1);
                mx=max(cur,mx);
            }
            else
                ans=max(ans,cur+1);
        }
    if(mn==INF)
        mn=0;
    return mn;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=1;
        dfs(1,-1);
        cout<<ans<<"\n";
    }
}