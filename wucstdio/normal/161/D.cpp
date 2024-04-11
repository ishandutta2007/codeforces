#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[100005];
int n,m,k,edgenum,head[50005],dep[50005],pa[50005],size[50005];
int maxx[50005],f[50005],top,num[50005],root;
ll ans;
bool flag[50005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void getroot(int node,int n)
{
	size[node]=1;
	maxx[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||flag[to])continue;
		pa[to]=node;
		getroot(to,n);
		maxx[node]=max(maxx[node],size[to]);
		size[node]+=size[to];
	}
	maxx[node]=max(maxx[node],n-size[node]);
	if(maxx[node]<maxx[root]||!root)root=node;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	if(dep[node]<=k)
	{
		ans+=num[k-dep[node]];
		f[++top]=dep[node];
	}
	size[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(flag[to])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
	}
}
void solve()
{
	int maxd=0;
	num[0]=1;
	dep[root]=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[to])continue;
		pa[to]=root;
		top=0;
		dfs(to);
		for(int i=1;i<=top;i++)
		{
			num[f[i]]++;
			maxd=max(maxd,f[i]);
		}
	}
	for(int i=1;i<=maxd;i++)num[i]=0;
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(flag[to])continue;
		root=0;
		getroot(to,size[to]);
		flag[root]=1;
		solve();
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	maxx[0]=2147483647;
	getroot(1,n);
	flag[root]=1;
	solve();
	printf("%I64d\n",ans);
	return 0;
}