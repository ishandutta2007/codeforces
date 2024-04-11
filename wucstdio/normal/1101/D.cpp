#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[400005];
int n,m,edgenum,head[200005],a[200005],pa[200005],ans;
map<int,int>f[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	if(a[node]!=1)
	{
		f[node][a[node]]=1;
		ans=max(ans,1);
	}
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		for(map<int,int>::iterator i=f[node].begin();i!=f[node].end();i++)
		  for(map<int,int>::iterator j=f[to].begin();j!=f[to].end();j++)
		    if(__gcd((*i).first,(*j).first)!=1)
		      ans=max(ans,(*i).second+(*j).second);
		for(map<int,int>::iterator i=f[to].begin();i!=f[to].end();i++)
		{
			int v=__gcd(a[node],(*i).first);
			if(v==1)continue;
			f[node][v]=max(f[node][v],(*i).second+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}