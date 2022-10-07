#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[300005];
int n,m,edgenum,head[300005],f[300005],pa[300005],size[300005],type[300005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(!head[node])
	{
		size[node]=1;
		f[node]=0;
		return;
	}
	if(type[node]==1)f[node]=1000000;
	else f[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs(to);
		if(type[node]==1)f[node]=min(f[node],f[to]);
		else f[node]+=f[to]+1;
		size[node]+=size[to];
	}
	if(type[node]==0)f[node]--;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&type[i]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&pa[i]);
		add(pa[i],i);
	}
	dfs(1);
	printf("%d\n",size[1]-f[1]);
	return 0;
}