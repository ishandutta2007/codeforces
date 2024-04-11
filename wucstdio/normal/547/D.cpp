#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[800005];
int n,m,edgenum=1,head[400005],d[400005],a[400005],ans[200005];
bool flag[400005],vis[400005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void dfs(int node,int from)
{
	vis[node]=1;
	for(int&hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[hd>>1])continue;
		flag[hd>>1]=1;
		dfs(to,hd>>1);
	}
	a[++ind]=from;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v+200000);
		add(v+200000,u);
		d[u]++;
		d[v+200000]++;
	}
	for(int i=1;i<=200000;i++)
	{
		if(d[i]&1)
		{
			add(i,400001);
			add(400001,i);
			d[i]++,d[400001]++;
		}
	}
	for(int i=200001;i<=400000;i++)
	{
		if(d[i]&1)
		{
			add(i,0);
			add(0,i);
			d[i]++,d[0]++;
		}
	}
	if(d[0]&1)
	{
		add(0,400001);
		add(400001,0);
		d[0]++,d[400001]++;
	}
	for(int i=1;i<=400000;i++)
	  if(d[i]&&!vis[i])
		dfs(i,0);
	for(int i=1;i<=ind;i++)
	  if(a[i]<=n)
		ans[a[i]]=(i&1);
	for(int i=1;i<=n;i++)
	  putchar(ans[i]?'r':'b');
	putchar('\n');
	return 0;
}