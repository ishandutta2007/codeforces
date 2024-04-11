#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,edgenum,head[10005],pa[10005],dep[10005],ans=100;
ll a[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	if(dep[node]>ans)
	{
		dep[node]=0;
		return;
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		if(!dep[to])
		{
			pa[to]=node;
			dfs(to);
			pa[to]=0;
		}
		else if(dep[to]<dep[node])ans=min(ans,dep[node]-dep[to]+1);
	}
	dep[node]=0;
}
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll x=1;x<=1e18;x<<=1)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		  if(a[i]&x)num++;
		if(num>=3)
		{
			printf("3\n");
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
	while(a[n]==0)n--;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    if(a[i]&a[j])add(i,j),add(j,i);
	for(int i=1;i<=n;i++)
	  dfs(i);
	if(ans==100)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}