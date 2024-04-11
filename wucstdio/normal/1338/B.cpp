#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[200005],dep[200005],pa[200005],d[200005],ans;
bool pos[2];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	bool f=0,f2=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		f=1;
		pa[to]=node;
		if(!dfs(to))f2=1;
	}
	if(!f)pos[dep[node]&1]=1;
	if(f)ans++;
	if(f2)ans++;
	return f;
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
	int r=1;
	while(d[r]==1)r++;
	dfs(r);
	if(pos[0]^pos[1])printf("1 ");
	else printf("3 ");
	printf("%d\n",ans-1);
	return 0;
}