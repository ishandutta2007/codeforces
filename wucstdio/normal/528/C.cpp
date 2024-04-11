#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[500005];
int n,m,tot,edgenum=1,head[100005],a[500005],d[100005];
bool flag[250005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	for(int&hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[hd>>1])continue;
		flag[hd>>1]=1;
		dfs(to);
		a[++tot]=node;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]^=1,d[v]^=1;
	}
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(!d[i])continue;
		if(last)add(last,i),add(i,last),m++,last=0;
		else last=i;
	}
	if(m&1)add(1,1),m++;
	dfs(1);
	a[++tot]=a[1];
	printf("%d\n",m);
	for(int i=1;i<tot;i+=2)
	{
		printf("%d %d\n",a[i],a[i+1]);
		printf("%d %d\n",a[i+2],a[i+1]);
	}
	return 0;
}