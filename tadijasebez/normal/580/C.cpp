#include <stdio.h>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
	int cat;
} Tree[100050];
int m,sol;
void DFS(int cur, int prev, int cat)
{
	cat*=Tree[cur].cat;
	cat+=Tree[cur].cat;
	if(cat>m) return;
	int j=0,i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i];
		if(v!=prev)
		{
			j++;
			DFS(v,cur,cat);
		}
	}
	if(j==0) sol++;
}
int main()
{
	int n,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&Tree[i].cat);
	for(i=0;i<n-1;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].edges.push_back(v);
		Tree[v].edges.push_back(u);
	}
	DFS(1,0,0);
	printf("%i\n",sol);
	return 0;
}