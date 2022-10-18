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
int d[N];
pii srt[N];
int ans[N];

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
            g[i].clear();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
            d[i]=INF;
        d[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int to:g[v])
                if(d[to]==INF)
                {
                    d[to]=d[v]+1;
                    q.push(to);
                }
        }
        for(int i=1;i<=n;i++)
            srt[i]={d[i],i};
        sort(srt+1,srt+n+1,greater<>());
        for(int i=1;i<=n;i++)
        {
            int v=srt[i].y;
            ans[v]=d[v];
            for(int to:g[v])
                ans[v]=min(ans[v],d[to]);
            for(int to:g[v])
                if(d[to]>d[v])
                    ans[v]=min(ans[v],ans[to]);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
}