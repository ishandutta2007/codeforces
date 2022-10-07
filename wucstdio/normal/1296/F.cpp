#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int val;
}e[200005];
struct Query
{
	int u,v;
	int len;
}a[200005];
int n,m,edgenum=1,head[100005],from[100005],pa[100005];
bool flag;
bool cmp(Query a,Query b)
{
	return a.len>b.len;
}
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
		from[to]=hd;
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
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].len);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		pa[a[i].u]=0;
		dfs(a[i].u);
		int node=a[i].v;
		bool flag=0;
		while(node!=a[i].u)
		{
			if(!e[from[node]].val)
			{
				flag=1;
				e[from[node]].val=e[from[node]^1].val=a[i].len;
			}
			if(e[from[node]].val==a[i].len)flag=1;
			node=e[from[node]^1].to;
		}
		if(!flag)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=2;i<edgenum;i+=2)
	{
		if(e[i].val)printf("%d ",e[i].val);
		else printf("1 ");
	}
	printf("\n");
	return 0;
}