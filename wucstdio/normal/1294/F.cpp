#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],pa[200005],dep[200005];
bool flag[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(flag[node])dep[node]=1;
	else dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
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
	int a=0,b=0,c=0;
	for(int i=1;i<=n;i++)
		if(dep[a]<dep[i])a=i;
	pa[a]=0;
	dfs(a);
	for(int i=1;i<=n;i++)
		if(dep[b]<dep[i]&&a!=i)b=i;
	int x=b,ans=0;
	while(x)
	{
		flag[x]=1;
		x=pa[x];
		ans++;
	}
	dfs(a);
	for(int i=1;i<=n;i++)
		if(dep[c]<dep[i]&&a!=i&&b!=i)c=i;
	x=c;
	while(!flag[x])
	{
		flag[x]=1;
		x=pa[x];
		ans++;
	}
	printf("%d\n%d %d %d\n",ans-1,a,b,c);
	return 0;
}