#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<ll, ll>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n,m;
vector<pii> edg[N];
bool vis[N];
ll dis[N];
void dij()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    priority_queue<pii>q;
    q.push({0,1});
    while(!q.empty())
    {
        int u=q.top().se;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto i:edg[u])
        {
            int v=i.fi,w=i.se;
            if(!vis[v]&&dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        for(int i=0;i<4;i++)
        {
            edg[i*n+u].push_back({i*n+v,w});
            edg[i*n+v].push_back({i*n+u,w});
        }
        edg[u].push_back({3*n+v,w});
        edg[v].push_back({3*n+u,w});
        edg[u].push_back({1*n+v,0});
        edg[v].push_back({1*n+u,0});
        edg[u].push_back({2*n+v,w*2});
        edg[v].push_back({2*n+u,w*2});

        edg[n+u].push_back({3*n+v,w*2});
        edg[n+v].push_back({3*n+u,w*2});

        edg[n*2+u].push_back({3*n+v,0});
        edg[n*2+v].push_back({3*n+u,0});
    }
    dij();
//    for(int i=1;i<=n;i++)
//        cout<<dis[i]<<' ';
//    cout<<endl;
    for(int i=n*3+2;i<=n*4;i++)
    {
        cout<<dis[i]<<' ';
    }
    return 0;
}