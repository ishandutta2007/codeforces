#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,f[2005][2005],l1[1005],l2[1005];
struct Graph
{
	struct Edge
	{
		int to;
		int nxt;
	}e[4005];
	int n,edgenum,head[2005],pa[2005],anc[15][2005],dep[2005];
	void add(int u,int v)
	{
		e[++edgenum].to=v;
		e[edgenum].nxt=head[u];
		head[u]=edgenum;
	}
	void dfs(int node)
	{
		dep[node]=dep[pa[node]]+1;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(to==pa[node])continue;
			pa[to]=node;
			dfs(to);
		}
	}
	void pre()
	{
		for(int i=1;i<=n;i++)anc[0][i]=pa[i];
		for(int i=1;i<=14;i++)
		  for(int j=1;j<=n;j++)
		    anc[i][j]=anc[i-1][anc[i-1][j]];
	}
	int LCA(int u,int v)
	{
		if(dep[u]<dep[v])swap(u,v);
		for(int i=0;dep[u]-dep[v];i++)
		  if((1<<i)&(dep[u]-dep[v]))
		    u=anc[i][u];
		if(u==v)return u;
		for(int i=14;i>=0;i--)
		{
			if(anc[i][u]!=anc[i][v])
			{
				u=anc[i][u];
				v=anc[i][v];
			}
		}
		return anc[0][u];
	}
}G1,G2;
int main()
{
	scanf("%d",&n);
	scanf("%d",&G1.n);
	for(int i=2;i<=G1.n;i++)
	{
		int u;
		scanf("%d",&u);
		G1.add(i,u);
		G1.add(u,i);
	}
	for(int i=1;i<=n;i++)scanf("%d",&l1[i]);
	scanf("%d",&G2.n);
	for(int i=2;i<=G2.n;i++)
	{
		int u;
		scanf("%d",&u);
		G2.add(i,u);
		G2.add(u,i);
	}
	for(int i=1;i<=n;i++)scanf("%d",&l2[i]);
	G1.dfs(1);
	G2.dfs(1);
	G1.pre();
	G2.pre();
	memset(f,0x3f,sizeof(f));
	l1[0]=l2[0]=1;
	f[0][0]=f[0][n]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			f[i][i-1+n]=min(f[i][i-1+n],f[i-1][j]+G1.dep[l1[i]]-G1.dep[G1.LCA(l1[i],l1[j])]);
			f[i][j]=min(f[i][j],f[i-1][j]+G2.dep[l2[i]]-G2.dep[G2.LCA(l2[i-1],l2[i])]);
			f[i][i-1]=min(f[i][i-1],f[i-1][j+n]+G2.dep[l2[i]]-G2.dep[G2.LCA(l2[i],l2[j])]);
			f[i][j+n]=min(f[i][j+n],f[i-1][j+n]+G1.dep[l1[i]]-G1.dep[G1.LCA(l1[i-1],l1[i])]);
		}
	}
	int ans=2147483647;
	for(int i=0;i<2*n;i++)ans=min(ans,f[n][i]);
	printf("%d\n",G1.n+G2.n-ans-2);
	return 0;
}