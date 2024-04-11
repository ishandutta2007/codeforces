#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
int NodeSize[N];
int CenDepth[N];
bool visited[N];
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
void Decompose(int src, int depth)
{
	src=GetCen(src);
	visited[src]=true;
	CenDepth[src]=depth;
	int i;
	for(i=0;i<Tree[src].size();i++)
	{
		int v=Tree[src][i];
		if(!visited[v])
		{
			Decompose(v,depth+1);
		}
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	Decompose(1,0);
	for(i=1;i<=n;i++) printf("%c ",'A'+CenDepth[i]);
	printf("\n");
	return 0;
}