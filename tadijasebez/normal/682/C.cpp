#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector< pair<int,int> > Tree[N];
int val[N];
int NodeSize[N];
void CalcSize(int cur, int prev)
{
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		if(v!=prev)
		{
			CalcSize(v,cur);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int sol;
void DFS(int cur, int prev, long long depth)
{
	if(depth>val[cur])
	{
		sol+=NodeSize[cur];
		return;
	}
	if(depth<0) depth=0;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev)
		{
			DFS(v,cur,depth+w);
		}
	}
}
int main()
{
	int n,i,v,w;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&val[i]);
	for(i=2;i<=n;i++)
	{
		scanf("%i %i",&v,&w);
		Tree[i].push_back(make_pair(v,w));
		Tree[v].push_back(make_pair(i,w));
	}
	CalcSize(1,0);
	DFS(1,0,0);
	printf("%i\n",sol);
	return 0;
}