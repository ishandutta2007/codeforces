#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
#define ll long long
struct miku
{
	int to,next,val;
}e[600010];
int a[300010];
int head[300010];
int cnt;
int n;
ll ans;
ll f[300010];
void add(int x,int y,int z)
{
	e[cnt]=(miku){y,head[x],z};
	head[x]=cnt++;
}
void dfs(int x,int from)
{
	f[x]=a[x];
	ans=max(ans,(ll)a[x]);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
			ans=max(ans,f[x]+f[to1]-e[i].val);
			f[x]=max(f[x],f[to1]+a[x]-e[i].val);
		}
	}
}
int main()
{
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1,x,y,z;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	printf("%lld\n",ans);
}