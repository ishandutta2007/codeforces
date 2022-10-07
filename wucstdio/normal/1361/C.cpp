#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[2000005];
int n,edgenum=1,v[1000005],d[2000005],head[2000005],pa[2000005],sze[2000005];
bool flag[1000005];
int vis[2000005],a[2000005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	if(sze[x]<sze[y])swap(x,y);
	pa[y]=x;
	sze[x]+=sze[y];
}
bool check(int k)
{
	for(int i=0;i<(1<<k);i++)d[i]=0,pa[i]=i,sze[i]=1;
	for(int i=1;i<=n;i++)
	{
		int x=v[2*i-1]&((1<<k)-1);
		int y=v[2*i]&((1<<k)-1);
		merge(x,y);
		d[x]++,d[y]++;
	}
	int x=0;
	while(!d[x])x++;
	x=find(x);
	for(int i=0;i<(1<<k);i++)
	{
		if(d[i]&1)return 0;
		if(d[i]&&find(i)!=x)return 0;
	}
	return 1;
}
int ind;
void dfs(int node,int from)
{
	vis[node]=1;
	for(int&hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[hd>>1])continue;
		flag[hd>>1]=1;
		dfs(to,hd);
	}
	a[++ind]=from;
}
void solve(int k)
{
	for(int i=0;i<(1<<k);i++)d[i]=0,pa[i]=i,sze[i]=1;
	for(int i=1;i<=n;i++)
	{
		int x=v[2*i-1]&((1<<k)-1);
		int y=v[2*i]&((1<<k)-1);
		add(x,y);
		add(y,x);
		d[x]++,d[y]++;
	}
	int x=0;
	while(!d[x])x++;
	dfs(x,0);
	ind--;
	for(int i=1;i<=ind;i++)
	{
		if(a[i]&1)printf("%d %d ",a[i]-2,a[i]-1);
		else printf("%d %d ",a[i],a[i]-1);
	}
	printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",&v[i]);
	int k=0;
	while(k<=20&&check(k))k++;
	k--;
	printf("%d\n",k);
	solve(k);
	return 0;
}