#include <stdio.h>
#include <vector>
using namespace std;
struct Node
{
	vector<int> edges;
} Tree[2050];
int sol=0;
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
void DFS(int cur, int prev, int depth)
{
	sol=max(sol,depth);
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
vector<int> Head;
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x==-1) Head.push_back(i);
		else Tree[x].edges.push_back(i);
	}
	for(i=0;i<Head.size();i++)
		DFS(Head[i],0,1);
	printf("%i\n",sol);
	return 0;
}