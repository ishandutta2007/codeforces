#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<ll, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 6e6 + 10;
const int M = 3e7 + 10;
struct tri
{
    int a,b,c;
};
tri e[M];
int head[N], e_cnt;
void add(int a, int b, int c)
{
    e[e_cnt] = {b, c, head[a]};
    head[a] = e_cnt++;
}
int n, m, s=1;
ll dis[N];
bool vis[N];
void dij()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pii>q;
    q.push({0, s});
    while(!q.empty())
    {
        int u = q.top().se; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(int i = head[u]; ~i; i = e[i].c)
        {
            int v = e[i].a, w = e[i].b;
            if(!vis[v] && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    memset(head, -1, sizeof(head));
	cin>>n>>m;
	for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v+n*w,0);
        add(v,u+n*w,0);
        for(int j=1;j<=50;j++)
        {
            add(u+j*n,v,(j+w)*(j+w));
            add(v+j*n,u,(j+w)*(j+w));
        }
    }
    dij();
    for(int i=1;i<=n;i++)
    {
        cout<<(dis[i]==linf?-1:dis[i])<<' ';
    }
	return 0;
}