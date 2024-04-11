#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[6005];
int n,m,edgenum,head[3005],size[3005],pa[3005];
ll v[3005],f[3005][3005][2],g[3005][3005],f2[3005][2],g2[3005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node][0][0]=0,g[node][0]=v[node];
	f[node][1][1]=(v[node]>0),g[node][1]=v[node];
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		for(int i=0;i<=size[node]+size[to];i++)f2[i][0]=f2[i][1]=-1,g2[i]=-1e18;
		for(int i=size[node];i>=0;i--)
		for(int j=size[to];j>=0;j--)
		{
			if(f2[i+j][0]<f[node][i][0]+f[to][j][0])
			{
				f2[i+j][0]=f[node][i][0]+f[to][j][0];
				g2[i+j]=g[node][i]+g[to][j];
			}
			else if(f2[i+j][0]==f[node][i][0]+f[to][j][0]&&g2[i+j]<g[node][i]+g[to][j])
			{
				g2[i+j]=g[node][i]+g[to][j];
			}
			if(f2[i+j][0]<f[node][i][0]+f[to][j][1])
			{
				f2[i+j][0]=f[node][i][0]+f[to][j][1];
				g2[i+j]=g[node][i];
			}
			else if(f2[i+j][0]==f[node][i][0]+f[to][j][1]&&g2[i+j]<g[node][i])
			{
				g2[i+j]=g[node][i];
			}
			if(f2[i+j][1]<f[node][i][1]+f[to][j][1])
			{
				f2[i+j][1]=f[node][i][1]+f[to][j][1];
			}
			if(f2[i+j+1][1]<f[node][i][1]+f[to][j][0]+(g[to][j]>0))
			{
				f2[i+j+1][1]=f[node][i][1]+f[to][j][0]+(g[to][j]>0);
			}
			if(f2[i+j+1][1]<f[node][i][0]+f[to][j][0]+(g[node][i]+g[to][j]>0))
			{
				f2[i+j+1][1]=f[node][i][0]+f[to][j][0]+(g[node][i]+g[to][j]>0);
			}
		}
		size[node]+=size[to];
		for(int i=0;i<=size[node];i++)
		  f[node][i][0]=f2[i][0],f[node][i][1]=f2[i][1],g[node][i]=g2[i];
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
		for(int i=1;i<=n;i++)
		{
			ll x;
			scanf("%lld",&x);
			v[i]=x-v[i];
			head[i]=0;
			for(int j=0;j<=n;j++)f[i][j][0]=f[i][j][1]=-1,g[i][j]=-1e18;
		}
		edgenum=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		printf("%lld\n",f[1][m][1]);
	}
	return 0;
}