#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N=2050;
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x)
		p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	x=Find(x);
	y=Find(y);
	if(r[x]<r[y]) p[x]=y;
	if(r[x]>r[y]) p[y]=x;
	if(r[x]==r[y]) r[x]++,p[y]=x;
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
vector<Edge> E;
int Matrix[N][N];
int Dist[N][N];
vector< pair<int,int> > Tree[N];
void DFS(int cur, int prev, int depth, int j)
{
	Dist[j][cur]=depth;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev) DFS(v,cur,depth+w,j);
	}
}
bool Check(int n)
{
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(Matrix[i][j]!=Dist[i][j] || (Matrix[i][j]==0 && i!=j)) return false;
	return true;
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%i",&Matrix[i][j]);
			E.push_back(Edge(i,j,Matrix[i][j]));
		}
	}
	sort(E.begin(),E.end());
	for(i=0;i<E.size();i++)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		int x=Find(u),y=Find(v);
		if(x!=y)
		{
			Tree[u].push_back(make_pair(v,w));
			Tree[v].push_back(make_pair(u,w));
			Union(x,y);
		}
	}
	for(i=1;i<=n;i++) DFS(i,0,0,i);
	if(Check(n)) printf("YES\n");
	else printf("NO\n");
	return 0;
}