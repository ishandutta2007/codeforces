#include<cstdio>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],f[100005][25],pa[100005],dep[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node,int depth)
{
	dep[node]=depth;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		if(e[hd].to==pa[node])continue;
		pa[e[hd].to]=f[e[hd].to][0]=node;
		dfs(e[hd].to,depth+1);
	}
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])return LCA(b,a);
	for(int i=0;(1<<i)<=dep[a]-dep[b];i++)
	  if((1<<i)&(dep[a]-dep[b]))
	    a=f[a][i];
	if(a==b)return a;
	for(int i=20;i>=0;i--)
	{
		if(f[a][i]!=f[b][i])
		{
			a=f[a][i];
			b=f[b][i];
		}
	}
	return pa[a];
}
int dis(int u,int v)
{
	int d=LCA(u,v);
	return dep[u]+dep[v]-2*dep[d];
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
	dfs(1,1);
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		  f[j][i]=f[f[j][i-1]][i-1];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int d1=dis(a,b),d2=dis(a,x)+dis(b,y)+1,d3=dis(a,y)+dis(b,x)+1;
		if(k>=d1&&(k-d1)%2==0)puts("YES");
		else if(k>=d2&&(k-d2)%2==0)puts("YES");
		else if(k>=d3&&(k-d3)%2==0)puts("YES");
		else puts("NO");
	}
	return 0;
}