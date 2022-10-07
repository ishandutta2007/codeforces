#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	double len;
}e[400005];
int n,m,edgenum,w[200005],pos[200005],head[200005],pa[200005],size[200005],maxs[200005],cnt[200005],tmp[200005],top,root,ans;
double dis[200005],st[200005],sum[200005],tot;
bool flag[200005];
void add(int u,int v,double l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node,int n)
{
	size[node]=1;
	maxs[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||flag[to])continue;
		pa[to]=node;
		dfs1(to,n);
		size[node]+=size[to];
		maxs[node]=max(maxs[node],size[to]);
	}
	maxs[node]=max(maxs[node],n-size[node]);
	if(maxs[node]<maxs[root])root=node;
}
void dfs2(int node)
{
	st[++top]=dis[node];
	pos[top]=node;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dis[to]=dis[node]+e[hd].len;
		dfs2(to);
	}
}
void check(int r)
{
	pa[r]=0;
	dis[r]=0;
	top=0;
	dfs2(r);
	double sum=0;
	for(int i=1;i<=top;i++)
	  sum+=sqrt(st[i])*st[i]*w[pos[i]];
	if(sum<tot)tot=sum,ans=r;
}
void solve()
{
	pa[root]=0;
	dis[root]=0;
	flag[root]=1;
	int num=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		pa[to]=root;
		dis[to]=e[hd].len;
		top=0;
		dfs2(to);
		num++;
		sum[num]=0;
		for(int i=1;i<=top;i++)
		  sum[num]+=sqrt(st[i])*w[pos[i]];
		tmp[num]=to;
	}
	double s=0;
	int x=0;
	for(int i=1;i<=num;i++)s+=sum[i];
	for(int i=1;i<=num;i++)
	{
		if(sum[i]>s-sum[i])
		{
			x=tmp[i];
			break;
		}
	}
	if(!x)
	{
		check(root);
		return;
	}
	if(flag[x])
	{
		check(root);
		check(x);
		return;
	}
	root=0;
	dfs1(x,n);
	root=0;
	dfs1(x,size[x]);
	solve();
}
int main()
{
	tot=1e300;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		double l;
		scanf("%d%d%lf",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	maxs[0]=2147483647;
	dfs1(1,n);
	solve();
	printf("%d %.12lf\n",ans,tot);
	return 0;
}