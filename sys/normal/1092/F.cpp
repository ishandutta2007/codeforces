#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int a[Maxn],cnt,head[Maxn],n;
long long sum[Maxn],ans[Maxn],maxi;
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs1(int u,int fa)
{
	sum[u]=a[u];
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs1(to,u);
			sum[u]+=sum[to];
		}
	}
}
void dfs2(int u,int fa)
{
	ans[u]=ans[fa]-2*sum[u]+sum[1];
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
			dfs2(to,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]); 
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	for(int i=2;i<=n;i++)
		ans[1]+=sum[i];
	for(int i=head[1];i;i=edge[i].nxt)
		dfs2(edge[i].to,1);
	for(int i=1;i<=n;i++)
		maxi=max(maxi,ans[i]);
	printf("%lld",maxi);
	return 0;
}