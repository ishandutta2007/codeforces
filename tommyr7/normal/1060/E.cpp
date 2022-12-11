#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n;
int last[Maxn],other[Maxn],pre[Maxn],size[Maxn],cnt=0;
bool flag[Maxn];
long long ans=0;
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
	size[u]=1;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			flag[v]=flag[u]^1;
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void dfs1(int u,int fa)
{
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			dfs1(v,u);
			ans+=1LL*size[v]*(n-size[v]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v),insert(v,u);
	}
	flag[1]=true;
	dfs(1,-1);
	int cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)
		if (flag[i]) ++cnt1; else ++cnt2;
	ans=1LL*cnt1*cnt2;
	dfs1(1,-1);
	ans/=2;
	printf("%lld\n",ans);
	return 0;
}