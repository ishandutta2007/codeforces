#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,head[Maxn],cnt,siz[Maxn];
long long ans[Maxn],sum[Maxn],k,mod[Maxn][7],sum_mod[Maxn][7];
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
	mod[u][0]=1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs(to,u);
			ans[u]+=sum[u]*siz[to]+siz[u]*(siz[to]+sum[to])+ans[to];
			siz[u]+=siz[to];
			sum[u]+=sum[to]+siz[to];
			for(int i=0;i<k;i++)
				for(int j=0;j<k;j++)
					sum_mod[u][(i+j)%k]+=mod[to][(i-1+k)%k]*mod[u][j];
			for(int i=0;i<k;i++)
				mod[u][i]+=mod[to][(i-1+k)%k];
		}
	}
//	for(int i=0;i<k;i++)
//		sum_mod[u][i]+=mod[u][i];
}
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	long long all=0;
	for(int j=1;j<=n;j++)
		for(int i=1;i<k;i++)
			all+=sum_mod[j][i]*(k-i);
	printf("%lld",(ans[1]+all)/k);
	return 0;
}