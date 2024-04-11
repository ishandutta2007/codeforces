#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,q;
pair<int,int> a[Maxn];
int fa[Maxn],rk[Maxn];
bool vis[Maxn];
map<int,bool> mp;
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void mdf(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	if (rk[x]>rk[y]) swap(x,y);
	rk[y]+=rk[x];
	fa[x]=y;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	if (q==0)
	{
		printf("%d\n",n+m-1);
		return 0;
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		mp[a[i].first]=true;
	}
	sort(a+1,a+q+1);
	for (int i=1;i<=m;i++)
		fa[i]=i,rk[i]=1;
	for (int i=1;i<q;i++)
		if (a[i].first==a[i+1].first) mdf(a[i].second,a[i+1].second);
	int del=0;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=m;i++)
		if (!vis[find(i)])
		{
			++del;
			int pos=find(i);
			vis[pos]=true;
		}
	--del;
	for (int i=1;i<=n;i++)
		if (!mp[i]) ++del;
	printf("%d\n",del);
	return 0;
}