#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[400005];
int n,m,edgenum,head[200005],dep[200005],ans[200005];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dep[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dep[to])continue;
			dep[to]=dep[node]+1;
			q.push(to);
		}
	}
	for(int i=1;i<=n;i++)dep[i]&=1;
	for(int i=1;i<=m;i++)
	{
		if(dep[e[i*2-1].to]==dep[e[i*2].to])
		{
			printf("NO\n");
			return 0;
		}
		ans[i]=dep[e[i*2-1].to]>dep[e[i*2].to];
	}
	printf("YES\n");
	for(int i=1;i<=m;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}