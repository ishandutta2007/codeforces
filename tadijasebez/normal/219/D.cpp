#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
vector< pair<int,int> > Tree[N];
int DP[N];
void DFS(int cur, int prev)
{
	DP[cur]=0;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(v!=prev)
		{
			DP[cur]+=w;
			DFS(v,cur);
			DP[cur]+=DP[v];
		}
	}
}
int sol=N<<4;
vector<int> ans;
void Solve(int cur, int prev, int depth)
{
	int k=DP[1]-depth;
	if(k<sol)
	{
		ans.clear();
		sol=k;
		ans.push_back(cur);
	}
	else if(k==sol)
	{
		ans.push_back(cur);
	}
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i].first;
		int w=Tree[cur][i].second;
		if(w==0) w=-1;
		if(v!=prev)
		{
			Solve(v,cur,depth+w);
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
		Tree[u].push_back(make_pair(v,0));
		Tree[v].push_back(make_pair(u,1));
	}
	DFS(1,0);
	Solve(1,0,0);
	printf("%i\n",sol);
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++) printf("%i ",ans[i]);
	return 0;
}