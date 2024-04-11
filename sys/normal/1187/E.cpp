#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,siz[Maxn],head[Maxn],cnt;
long long ans,sum;
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs(int u,int fa)
{
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs(to,u);
			siz[u]+=siz[to];
		}
	}
	sum+=siz[u];
}
void work(int u,int fa)
{
	ans=max(ans,sum);
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			sum+=2*n-2*siz[to]-siz[u];
			siz[u]=n-siz[to];
			siz[to]=n;
			work(to,u);
			siz[to]=n-siz[u];
			siz[u]=n;
			sum-=2*n-2*siz[to]-siz[u];
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	work(1,0);
	printf("%lld",ans);
	return 0;
}