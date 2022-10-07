#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int next;
}e[400005];
ll n,m,edgenum,head[200005],f[200005][2],size[200005],pa[200005],dep[200005],ans,num;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	size[node]=1;
	f[node][0]=1;
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
		num+=f[node][0]*f[to][0]+f[node][1]*f[to][1];
		f[node][0]+=f[to][1];
		f[node][1]+=f[to][0];
	}
	ans+=size[node]*(n-size[node]);
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
	printf("%I64d\n",ans+num>>1);
	return 0;
}