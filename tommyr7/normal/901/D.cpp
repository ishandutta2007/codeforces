#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,nowx,nowy,now;
int dep[Maxn];
long long ans[Maxn],c[Maxn],s1=0,s2=0;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0,pos[Maxn];
bool vis[Maxn];
void insert(int u,int v,int id)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt,pos[cnt]=id;
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			if (!dep[v]) dfs(v,u); else
			if ((dep[v]-dep[u])%2==0)
			{
				nowx=u,nowy=v,now=pos[q];
			}
		}
	}
}
void tryit(int u,int fa)
{
	vis[u]=true;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa&&!vis[v])
		{
			tryit(v,u);
			ans[pos[q]]=c[v];
			c[u]-=ans[pos[q]];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v,i),insert(v,u,i);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		if (dep[i]%2==1) s1+=c[i]; else s2+=c[i];
	if (s1!=s2&&now==0) printf("NO\n");
	else
	{
		printf("YES\n");
		if (dep[nowx]%2==1) ans[now]=(s1-s2)/2; else ans[now]=(s2-s1)/2;
		c[nowx]-=ans[now],c[nowy]-=ans[now];
		memset(vis,false,sizeof(vis));
		tryit(1,0);
		for (int i=1;i<=m;i++)
			printf("%lld\n",ans[i]);
	}
	return 0;
}