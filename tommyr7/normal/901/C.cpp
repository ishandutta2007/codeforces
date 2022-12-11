#include <bits/stdc++.h>
#define Maxn 600007
using namespace std;
int n,m,q;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int ans[Maxn];
int f[Maxn],dep[Maxn];
long long val[Maxn];
void insert(int u,int v)
{
	other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void calc(int u,int v)
{
	if (dep[u]<dep[v]) return;
	int now_max=u,now_min=u;
	while (u!=v)
	{
		u=f[u];
		now_max=max(now_max,u);
		now_min=min(now_min,u);
	}
	ans[now_min]=min(ans[now_min],now_max-1);
}
void dfs(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for (int q=last[u];q;q=pre[q])
	{
		int v=other[q];
		if (v!=fa)
		{
			if (!dep[v]) dfs(v,u); else calc(u,v);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v),insert(v,u);
	}
	for (int i=1;i<=n;i++)
		ans[i]=n;
	for (int i=1;i<=n;i++)
		if (!dep[i]) dfs(i,0);
	for (int i=n-1;i;i--)
		ans[i]=min(ans[i],ans[i+1]);
	for (int i=1;i<=n;i++)
		val[i]=val[i-1]+ans[i]-i+1;
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int pos=upper_bound(ans+1,ans+n+1,r)-ans;
		pos=max(pos,l);
		long long res=val[pos-1]-val[l-1]+(1LL*(r-pos+1)*(r-pos+2))/2;
		printf("%lld\n",res);
	}
	return 0;
}