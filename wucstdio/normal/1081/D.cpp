#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int from;
	int to;
	int len;
}e[200005];
int n,m,edgenum,k,x[100005],head[100005];
int pa[100005],maxx[100005];
bool flag[100005];
bool cmp(Edge a,Edge b)
{
	return a.len<b.len;
}
int find_max(int x)
{
	if(x==pa[x])return maxx[x];
	return maxx[x]=max(maxx[x],find_max(pa[x]));
}
int find_pa(int x){return x==pa[x]?x:pa[x]=find_pa(pa[x]);}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x[i]);
		flag[x[i]]=1;
	}
	for(int i=1;i<=n;i++)
	  pa[i]=i,maxx[i]=0;
	for(int i=1;i<=m;i++)
	  scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].len);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].from;
		int v=e[i].to;
		find_max(u);
		find_max(v);
		u=find_pa(u);
		v=find_pa(v);
		if(u==v)continue;
		pa[u]=v;
		if(flag[v]&&flag[u])maxx[v]=max(max(maxx[u],maxx[v]),e[i].len);
		if(flag[u])flag[v]=1;
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d ",find_max(x[i]));
		find_pa(x[i]);
	}
	printf("\n");
	return 0;
}