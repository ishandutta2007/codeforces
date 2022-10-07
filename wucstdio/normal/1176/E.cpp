#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int t,n,m,edgenum,pa[200005],head[200005],num1,num2,c[200005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(c[node]==0)num1++;
	else num2++;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		c[to]=c[node]^1;
		dfs(to);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		edgenum=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)pa[i]=i,head[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(find(u)==find(v))continue;
			add(u,v);
			add(v,u);
			pa[find(u)]=find(v);
		}
		pa[1]=0;
		num1=num2=0;
		c[1]=0;
		dfs(1);
		printf("%d\n",min(num1,num2));
		if(num1<num2)
		{
			for(int i=1;i<=n;i++)
			  if(c[i]==0)printf("%d ",i);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=n;i++)
			  if(c[i]==1)printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}