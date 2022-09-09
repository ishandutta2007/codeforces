#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1005;
char maps[N][12][12];
int n,m,k,w;
int Compare(int u, int v)
{
	int i,j,ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(maps[u][i][j]!=maps[v][i][j]) ans++;
	return ans*w;
}
struct Edge
{
	int u,v,w;
	Edge(){}
	Edge(int a, int b, int c){ u=a,v=b,w=c;}
	inline bool operator < (const Edge &b) const
	{
		return w<b.w;
	}
};
vector<Edge> edges;
vector<int> Tree[N];
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x)
		p[x]=Find(p[x]);
	return p[x];
}
void Union(int u, int v)
{
	int x=Find(u);
	int y=Find(v);
	if(r[x]>r[y]) p[y]=x;
	if(r[x]<r[y]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
int sol;
bool vis[N];
void DFS(int cur, int prev)
{
	printf("%i %i\n",cur,prev);
	vis[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur);
		}
	}
}
int main()
{
	scanf("%i %i %i %i",&n,&m,&k,&w);
	int i,j,l;
	for(i=1;i<=k;i++)
		for(j=0;j<n;j++)
			scanf("%s",&maps[i][j]);
	for(i=1;i<=k;i++)
	{
		for(j=1;j<i;j++)
		{
			int tmp=Compare(i,j);
			if(tmp<=n*m) edges.push_back(Edge(i,j,tmp));
		}
	}
	for(i=1;i<=k;i++) p[i]=i;
	sort(edges.begin(),edges.end());
	int p=edges.size();
	for(i=0,j=0;i<p && j<k-1;i++)
	{
		int u=edges[i].u;
		int v=edges[i].v;
		int w=edges[i].w;
		int x=Find(u);
		int y=Find(v);
		if(x!=y)
		{
			Union(x,y);
			sol+=w;
			Tree[u].push_back(v);
			Tree[v].push_back(u);
			j++;
		}
	}
	sol+=(k-j)*n*m;
	printf("%i\n",sol);
	for(i=1;i<=k;i++)
		if(!vis[i]) DFS(i,0);
	return 0;
}