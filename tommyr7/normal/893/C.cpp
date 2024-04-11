#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int rk[Maxn],fa[Maxn],a[Maxn],n,m;
bool vis[Maxn];
long long ans=0;
int find(int x)
{
	if (fa[x]==x) return x;
	return find(fa[x]);
}
void mdf(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	if (rk[x]<rk[y]) swap(x,y);
	rk[x]+=rk[y];
	a[x]=min(a[x],a[y]);
	fa[y]=x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		rk[i]=1;
		fa[i]=i;
		scanf("%d",&a[i]);
	}
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mdf(x,y);
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (!vis[find(i)])
		{
			vis[find(i)]=true;
			ans+=a[find(i)];
		}
	printf("%lld\n",ans);
	return 0;
}