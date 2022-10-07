#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int from;
	int to;
	int len;
}e[200005];
int n,m,pa[200005];
ll now,ans[200005],size[200005];
int find(int x)
{
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
bool cmp(Edge a,Edge b)
{
	return a.len<b.len;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)pa[i]=i,size[i]=1;
	for(int i=1;i<n;i++)scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].len);
	sort(e+1,e+n,cmp);
	int x=0;
	for(int i=1;i<n;i++)
	{
		while(x<e[i].len)ans[x++]=now;
		int u=find(e[i].from);
		int v=find(e[i].to);
		if(u!=v)
		{
			if(size[u]>size[v])swap(u,v);
			now-=size[u]*(size[u]-1)/2;
			now-=size[v]*(size[v]-1)/2;
			pa[u]=v;
			size[v]+=size[u];
			now+=size[v]*(size[v]-1)/2;
		}
	}
	while(x<=200000)ans[x++]=now;
	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld ",ans[x]);
	}
	printf("\n");
	return 0;
}