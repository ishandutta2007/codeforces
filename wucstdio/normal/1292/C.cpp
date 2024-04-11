#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[6005];
int n,m,edgenum,head[3005],dep[3005],pa[3005],dis[3005][3005],size[3005][3005];
ll f[3005][3005],ans;
vector<pair<int,int> >s[3005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node,int r)
{
	dep[node]=dep[pa[node]]+1;
	size[node][r]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to,r);
		size[node][r]+=size[to][r];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		pa[i]=0;
		dfs(i,i);
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=dep[j]-1;
			if(i<j)s[dis[i][j]].push_back(make_pair(i,j));
		}
	}
	for(int d=1;d<n;d++)
	{
		int x=(int)s[d].size();
		for(int k=0;k<x;k++)
		{
			int i=s[d][k].first,j=s[d][k].second;
			ans=max(ans,f[i][j]);
			for(int hd=head[i];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(dis[to][j]==dis[i][j]+1)
					f[to][j]=f[j][to]=max(f[to][j],f[i][j]+1ll*size[i][j]*size[j][i]);
			}
			for(int hd=head[j];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(dis[to][i]==dis[i][j]+1)
					f[to][i]=f[i][to]=max(f[to][i],f[i][j]+1ll*size[i][j]*size[j][i]);
			}
		}
	}
	printf("%lld\n",ans+1);
	return 0;
}