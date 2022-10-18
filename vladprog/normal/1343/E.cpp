#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int p[3*N];
vector<int> g[N];
int dista[N],distb[N],distc[N];

void dijkstra(int n,int v,int*dist)
{
    for(int i=1;i<=n;i++)
        dist[i]=1e18;
    dist[v]=0;
    set<pii> s{pii(0,v)};
    while(!s.empty())
    {
        v=s.begin()->y;
        int d=s.begin()->x;
        s.erase(s.begin());
        for(int to:g[v])
            if(dist[to]>d+1)
                s.erase({dist[to],to}),
                dist[to]=d+1,
                s.insert({dist[to],to});
    }
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
        int n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=m;i++)
            cin>>p[i];
        sort(p+1,p+m+1);
        for(int i=m+1;i<=3*n;i++)
            p[i]=1.1e9;
        sort(p+1,p+3*n+1);
        for(int i=1;i<=3*n;i++)
            p[i]+=p[i-1];
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dijkstra(n,a,dista);
        dijkstra(n,b,distb);
        dijkstra(n,c,distc);
        int ans=1e18;
        for(int v=1;v<=n;v++)
        {
            int cnt1=dista[v]+distc[v];
            int cnt2=distb[v];
            int cur=2*p[cnt2]+p[cnt1+cnt2]-p[cnt2];
            ans=min(ans,cur);
        }
        cout<<ans<<"\n";
    }
}