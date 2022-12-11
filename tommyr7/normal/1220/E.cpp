#include <bits/stdc++.h>
using namespace std;
#define Maxn 400007
int n,m,s;
long long val[Maxn];
bool vis[Maxn];
long long ans=0LL,mx=0LL;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
long long tmp[Maxn];
int que[Maxn],lx=0,rx=0;
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
int d[Maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v),insert(v,u);
		++d[u],++d[v];
	}
	scanf("%d",&s);
	if (n==1)
	{
		printf("%lld\n",val[1]);
		return 0;
	}
	memset(vis,true,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (i!=s&&d[i]==1) 
		{
			que[++rx]=i;
			vis[i]=false;
		}
	while (lx<rx)
	{
		int u=que[++lx];
		for (int q=last[u];q;q=pre[q])
		{
			int v=other[q];
			if (vis[v])
			{
				--d[v];
				tmp[v]=max(tmp[v],tmp[u]+val[u]);
				if (d[v]==1&&v!=s) 
				{
					que[++rx]=v;
					vis[v]=false;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
		if (vis[i]) ans+=val[i]; else mx=max(mx,tmp[i]+val[i]);
	ans+=mx;
	printf("%lld\n",ans);
	return 0;
}