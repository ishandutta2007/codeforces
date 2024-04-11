#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int CenParent[N];
int CenDepth[N];
int NodeSize[N];
bool visited[N];
bool mark[N];
int min(int a, int b){ return a>b?b:a;}
void DFS(int cur, int prev, int &n)
{
	n++;
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			DFS(v,cur,n);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int GetCen(int cur, int prev, int n)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			if(NodeSize[v]>n/2) return GetCen(v,cur,n);
		}
	}
	return cur;
}
int GetCen(int src)
{
	int n=0;
	DFS(src,src,n);
	return GetCen(src,src,n);
}
int Depth[N][20];
vector<int> DP[2][N];
int SubTree[N][20];
void Solve(int cur, int prev, int path, int depth, int cen)
{
	Depth[cur][depth]=path;
	SubTree[cur][depth]=DP[0][cen].size();
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev && !visited[v])
		{
			Solve(v,cur,path+1,depth,cen);
		}
	}
}
const int inf=1000000;
int Decompose(int src, int depth)
{
	src=GetCen(src);
	visited[src]=true;
	CenDepth[src]=depth;
	int i;
	DP[0][src].push_back(inf);
	DP[1][src].push_back(inf);
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			Solve(v,src,1,depth,src);
			DP[0][src].push_back(inf);
			DP[1][src].push_back(inf);
		}
	}
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			v=Decompose(v,depth+1);
			CenParent[v]=src;
		}
	}
	return src;
}
void Update(int cen, int sub, int val)
{
	int index=sub;
	for(index;index<DP[0][cen].size();index+=index&-index)
		DP[0][cen][index]=min(DP[0][cen][index],val);
	index=sub;
	for(index;index>0;index-=index&-index)
		DP[1][cen][index]=min(DP[1][cen][index],val);
}
int Get(int cen, int sub)
{
	int ret=inf;
	int index=sub-1;
	for(index;index>0;index-=index&-index)
		ret=min(ret,DP[0][cen][index]);
	index=sub+1;
	for(index;index<DP[1][cen].size();index+=index&-index)
		ret=min(ret,DP[1][cen][index]);
	return ret;
}
void Set(int v)
{
	mark[v]=true;
	int cen=CenParent[v];
	int depth=CenDepth[cen];
	while(cen>0)
	{
		Update(cen,SubTree[v][depth],Depth[v][depth]);
		cen=CenParent[cen];
		depth=CenDepth[cen];
	}
}
int Query(int v)
{
	int cen=v;
	int depth=CenDepth[cen];
	int sol=inf;
	while(cen>0)
	{
		if(mark[cen]) sol=min(sol,Depth[v][depth]);
		else
		{
			sol=min(sol,Get(cen,SubTree[v][depth])+Depth[v][depth]);
		}
		cen=CenParent[cen];
		depth=CenDepth[cen];
	}
	return sol;
}
int main()
{
	int n,q,i,u,v,t;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	Decompose(1,0);
	Set(1);
	while(q--)
	{
		scanf("%i %i",&t,&v);
		if(t==2)
		{
			printf("%i\n",Query(v));
		}
		else Set(v);
	}
	return 0;
}