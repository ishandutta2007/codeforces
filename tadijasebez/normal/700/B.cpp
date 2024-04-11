#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
vector<int> Tree[N];
int NodeSize[N],Depth[N];
bool mark[N];
int n,k;
void DFS(int cur, int prev)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int GetCen(int cur, int prev)
{
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			if(NodeSize[v]>k) return GetCen(v,cur);
		}
	}
	return cur;
}
vector<int> nodes;
void Travel(int cur, int prev, int depth)
{
	Depth[cur]=depth;
	if(mark[cur]) nodes.push_back(cur);
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			Travel(v,cur,depth+1);
		}
	}
}
long long sol;
int main()
{
	int i,u,v;
	scanf("%i %i",&n,&k);
	for(i=1;i<=k*2;i++) scanf("%i",&u),NodeSize[u]++,mark[u]=1;
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}
	DFS(1,0);
	Travel(GetCen(1,0),0,0);
	for(i=0;i<nodes.size();i++)
	{
		sol+=Depth[nodes[i]];
	}
	printf("%lld\n",sol);
	return 0;
}