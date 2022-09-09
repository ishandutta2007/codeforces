#include <stdio.h>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
} Tree[10050];
int sol;
void DFS(int cur, int prev, int depth)
{
	if(depth==2) sol++;
	if(depth>1) return;
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1);
		}
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i",&u,&v);
		u--;
		v--;
		Tree[u].edges.push_back(v);
		Tree[v].edges.push_back(u);
	}
	for(i=0;i<n;i++) DFS(i,i,0);
	printf("%i\n",sol>>1);
	return 0;
}