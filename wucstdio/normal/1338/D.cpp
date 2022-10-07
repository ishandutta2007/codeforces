#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],dep[100005],pa[100005],d[100005],ans;
int f[100005][2];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	f[node][0]=0,f[node][1]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		ans=max(ans,f[node][0]+f[to][0]+d[node]-2+d[to]-2);
		ans=max(ans,f[node][0]+f[to][1]+d[node]-2);
		ans=max(ans,f[node][1]+f[to][0]+d[to]-2);
		f[node][0]=max(f[node][0],f[to][1]);
		f[node][0]=max(f[node][0],f[to][0]+d[to]-2);
		f[node][1]=max(f[node][1],f[to][0]+d[to]-1);
	}
	ans=max(ans,f[node][1]);
	ans=max(ans,f[node][0]+d[node]-1);
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
		d[u]++,d[v]++;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}