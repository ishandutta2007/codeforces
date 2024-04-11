#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<int> g[N];
bool used[N];

pii dfs(int i)
{
    if(used[i])
        return {0,0};
    used[i]=true;
    int v=1,e=0;
    for(int to:g[i])
    {
        auto[v1,e1]=dfs(to);
        v+=v1;
        e+=e1+1;
    }
    return {v,e};
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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            g[i].clear(),
            used[i]=false;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!used[i])
            {
                auto[v,e]=dfs(i);
                e/=2;
                if(v==1&&e==1)
                    ans+=0;
                else if(v==e)
                    ans+=e+1;
                else
                    ans+=e;
            }
        cout<<ans<<"\n";
    }
}