#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2000005];
int n,m,edgenum=1,a[1000005],b[1000005],c[1000005],d[1000005],head[1000005];
int val[1000005],pa[1000005];
struct Data
{
	int v;
	bool borc;
	int pos;
}data[2000005];
bool cmp(Data a,Data b)
{
	return a.v<b.v;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool flag[2000005];
void dfs(int node)
{
	for(int&hd=head[node];hd;hd=e[hd].nxt)
	{
		if(flag[hd])continue;
		flag[hd]=flag[hd^1]=1;
		dfs(e[hd].to);
	}
	printf("%d ",val[node]);
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
bool check()
{
	int num=0;
	for(int i=1;i<=m;i++)num+=d[i];
	if(num!=0&&num!=2)return 0;
	for(int i=1;i<=m;i++)pa[i]=i;
	for(int i=2;i<=edgenum;i+=2)
	{
		int u=find(e[i].to),v=find(e[i+1].to);
		if(u!=v)pa[u]=v;
	}
	for(int i=2;i<=m;i++)
	  if(find(i)!=find(1))return 0;
	memset(flag,0,sizeof(flag));
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
		data[++m].v=b[i];
		data[m].borc=0;
		data[m].pos=i;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d",&c[i]);
		data[++m].v=c[i];
		data[m].borc=1;
		data[m].pos=i;
	}
	sort(data+1,data+m+1,cmp);
	m=0;
	for(int i=1;i<=n*2-2;i++)
	{
		if(data[i].v!=data[i-1].v)m++;
		val[m]=data[i].v;
		if(data[i].borc)c[data[i].pos]=m;
		else b[data[i].pos]=m;
	}
	for(int i=1;i<n;i++)
	{
		if(c[i]<b[i])
		{
			printf("-1\n");
			return 0;
		}
		add(b[i],c[i]);
		add(c[i],b[i]);
		d[b[i]]^=1,d[c[i]]^=1;
	}
	if(!check())
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(d[i])
		{
			dfs(i);
			printf("\n");
			return 0;
		}
	}
	dfs(1);
	printf("\n");
	return 0;
}