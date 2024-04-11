#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],pa[100005],d[100005],ans[1000005][2],top,maxd;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node,int t)
{
	ans[++top][0]=node;
	ans[top][1]=t;
	int l=t,r=t;
	while(r-l<d[node]&&l>0)l--;
	while(r-l<d[node])r++;
	if(t==r)
	{
		ans[++top][0]=node;
		ans[top][1]=t=l;
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to,++t);
		ans[++top][0]=node;
		ans[top][1]=t;
		if(t==r&&node!=1)
		{
			ans[++top][0]=node;
			ans[top][1]=t=l;
		}
	}
}
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n1 0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=2;i<=n;i++)maxd=max(maxd,d[i]);
	maxd=max(maxd,d[1]);
	dfs(1,0);
	printf("%d\n",top);
	for(int i=1;i<=top;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}