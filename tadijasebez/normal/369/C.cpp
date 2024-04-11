#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=100050;
vector<pair<int,int> > Tree[N];
vector<int> sol;
bool DFS(int cur, int prev, int edge)
{
	int i;
	bool ok=true;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int e=Tree[cur][i].second;
		if(v!=prev)
		{
			ok=DFS(v,cur,e) && ok;
		}
	}
	if(ok)
	{
		if(edge==2)
		{
			sol.push_back(cur+1);
			return false;
		}
	}
	return ok;
}
int main()
{
	int n,i,u,v,t;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&t);
		u--;
		v--;
		Tree[u].push_back(make_pair(v,t));
		Tree[v].push_back(make_pair(u,t));
	}
	DFS(0,0,1);
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}