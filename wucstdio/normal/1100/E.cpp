#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int from;
	int to;
	int next;
	int cost;
}e[200005];
int n,m,edgenum,head[200005],d[200005],dfn[200005];
int ans[200005],top;
bool flag[200005];
queue<int>q;
void add(int u,int v,int c)
{
	e[++edgenum].cost=c;
	e[edgenum].from=u;
	e[edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
int ind;
bool check(int c)
{
	ind=0;
	for(int i=1;i<=n;i++)
	  d[i]=0;
	for(int i=1;i<=m;i++)
	  if(e[i].cost>c)
	    d[e[i].to]++;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			flag[i]=1;
			q.push(i);
			dfn[i]=++ind;
		}
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].next)
		{
			int to=e[hd].to;
			if(e[hd].cost<=c)continue;
			d[to]--;
			if(d[to]==0)
			{
				q.push(to);
				flag[to]=1;
				dfn[to]=++ind;
			}
		}
	}
	for(int i=1;i<=n;i++)
	  if(flag[i]==0)
	    return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add(u,v,c);
	}
	int l=0,r=1000000000;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d ",l);
	check(l);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].from,v=e[i].to;
		if(dfn[u]>dfn[v])ans[++top]=i;
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
	  printf("%d ",ans[i]);
	printf("\n");
	return 0;
}