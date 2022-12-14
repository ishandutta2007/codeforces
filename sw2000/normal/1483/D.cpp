#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 600 + 10;
const int mod = 1e9 + 7;

int n,m,q;
ll dis[N][N],ma[N][N];
struct tri{int u,v,w;}edg[N*N],que[N*N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=0;i<m;i++)
    {
        cin>>edg[i].u>>edg[i].v>>edg[i].w;
        dis[edg[i].u][edg[i].v]=dis[edg[i].v][edg[i].u]=edg[i].w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    int q;cin>>q;
    while(q--)
    {
        int u,v,w;cin>>u>>v>>w;
        for(int i=1;i<=n;i++)
        {
            ma[i][u]=ma[u][i]=max(ma[i][u],w-dis[v][i]);
            ma[i][v]=ma[v][i]=max(ma[i][v],w-dis[u][i]);
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(edg[i].w+dis[edg[i].u][j]<=ma[edg[i].v][j]){ans++;break;}
            if(edg[i].w+dis[edg[i].v][j]<=ma[edg[i].u][j]){ans++;break;}
        }
    }
    cout<<ans;
	return 0;
}