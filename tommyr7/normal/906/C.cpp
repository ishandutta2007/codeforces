#include <bits/stdc++.h>
#define Maxn 23
using namespace std;
int n,m,ans=107;
int f[Maxn],r[Maxn],now[Maxn];
void dfs(int cnt,int pos)
{
	if (cnt>=ans) return;
	int g[Maxn];
	for (int i=1;i<=n;i++)
		g[i]=f[i];
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (f[i]!=(1<<n)-1)
		{
			flag=false;
			break;
		}
	if (flag)
	{
		if (cnt<ans)
		{
			ans=cnt;
			for (int i=1;i<=cnt;i++)
				r[i]=now[i];
		}
	} else
	{
		for (int i=pos+1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				if (f[j]&(1<<(i-1))) f[j]|=f[i];
			now[cnt+1]=i;
			dfs(cnt+1,i);
			for (int j=1;j<=n;j++)
				f[j]=g[j];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		f[u]|=(1<<(v-1));
		f[v]|=(1<<(u-1));
	}
	for (int i=1;i<=n;i++)
		f[i]|=(1<<(i-1));
	memset(now,0,sizeof(now));
	memset(r,0,sizeof(r));
	dfs(0,0);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		printf("%d ",r[i]);
	printf("\n");
	return 0;
}