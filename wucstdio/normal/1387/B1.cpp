#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,edgenum,head[100005],pa[100005],match[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		if(!match[to]&&!match[node])
		{
			match[to]=node;
			match[node]=to;
		}
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
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(match[i])
		{
			ans++;
			continue;
		}
		int j=e[head[i]].to;
		match[i]=match[j];
		match[j]=i;
		ans+=2;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",match[i]);
	printf("\n");
	return 0;
}