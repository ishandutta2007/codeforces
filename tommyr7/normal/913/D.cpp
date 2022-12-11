#include <bits/stdc++.h>
#define Maxn 400007
using namespace std;
int n,T,ans,cnt;
int a[Maxn],t[Maxn];
pair<int,int> r[Maxn];
bool vis[Maxn];
bool tryit(int x)
{
	cnt=0;
	for (int i=1;i<=n;i++)
		if (a[i]>=x) r[++cnt]=make_pair(t[i],i);
	sort(r+1,r+cnt+1);
	if (cnt<x) return false;
	memset(vis,false,sizeof(vis));
	int now=0;
	for (int i=1;i<=x;i++)
	{
		vis[r[i].second]=true;
		now+=r[i].first;
	}
	if (now<=T) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&t[i]);
	int lx=0,rx=n;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (tryit(mid)) lx=mid; else rx=mid;
	}
	if (tryit(rx)) ans=rx; else
	{
		tryit(lx);
		ans=lx;
	}
	printf("%d\n",ans);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
		if (vis[i]) printf("%d ",i);
	printf("\n");
	return 0;
}