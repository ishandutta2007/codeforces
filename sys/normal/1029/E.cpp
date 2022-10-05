#include <bits/stdc++.h>
using namespace std;
int n,dis[200005],ans,head[200005],cnt; 
struct edg
{
	int nxt,to;
}edge[400005];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
			dfs(to,u);
	}
}
void cal(int u,int fa)
{
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dis[to]=min(dis[to],dis[u]+1);
			cal(to,u);
			dis[u]=min(dis[u],dis[to]+1);
		}
	}
	if(dis[u]>2)
	{
		dis[fa]=1;
		dis[u]=2;
		ans++; 
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dis[0]=-1;
	dfs(1,0);
	cal(1,0);
	printf("%d",ans);
	return 0;
}