#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=3005;
short par[N][50];
vector<int> Graph[N];
void DFS(int cur, int prev, int k)
{
	int i;
	for(i=0;i<Graph[cur].size();i++)
	{
		int v=Graph[cur][i];
		if(v!=k && (!par[v][0] || par[v][0]>cur))
		{
			par[v][0]=cur;
			DFS(v,cur,k);
		}
	}
}
int n;
void Build(int k)
{
	int i,j;
	for(i=1;i<=n;i++) for(j=0;j<50;j++) par[i][j]=0;
	DFS(k,k,k);
	for(j=1;j<50;j++) for(i=1;i<=n;i++) par[i][j]=par[par[i][j-1]][0];
}
struct Data
{
	int u,v,k,i;
	inline bool operator < (const Data &b) const 
	{
		return v<b.v;
	}
} Query[400050];
int ans[400050];
int main()
{
	int m,q,i,u,v,k;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		Graph[v].push_back(u);
	}
	for(i=1;i<=q;i++) scanf("%i %i %i",&Query[i].u,&Query[i].v,&Query[i].k),Query[i].i=i;
	sort(Query+1,Query+1+q);
	for(i=1;i<=q;i++)
	{
		if(Query[i].v!=Query[i-1].v) Build(Query[i].v);
		v=Query[i].v;
		u=Query[i].u;
		k=Query[i].k;
		int t=n+1,p=u;
		while(t>50)
		{
			p=par[p][49];
			t-=50;
		}
		while(t)
		{
			p=par[p][0];
			t--;
		}
		if(!par[u][0] || p)
		{
			ans[Query[i].i]=-1;
			continue;
		}
		k--;
		while(k>50)
		{
			u=par[u][49];
			k-=50;
		}
		while(k)
		{
			u=par[u][0];
			k--;
		}
		if(!u) ans[Query[i].i]=-1;
		else ans[Query[i].i]=u;
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}