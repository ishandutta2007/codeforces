#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[200005];
int n,m,edgenum,head[100005],pa[100005],size[100005];
int a[100005],b[100005],suma[100005],sumb[100005];
double ans;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	size[node]=1;
	suma[node]=a[node];
	sumb[node]=b[node];
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
        dfs(to);
		size[node]+=size[to];
		suma[node]+=suma[to];
		sumb[node]+=sumb[to];
		ans+=b[node]*1.0/b[0]*suma[to]*1.0/a[0]*(n-size[to]);
	}
	ans+=b[node]*1.0/b[0]*(a[0]-suma[node])/a[0]*size[node];
	ans+=b[node]*1.0/b[0]*a[node]/a[0]*n;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[0]+=a[i],b[0]+=b[i];
	}
	dfs(1);
	printf("%.10lf\n",n-ans);
	return 0;
}