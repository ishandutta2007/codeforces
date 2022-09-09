#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=300050;
vector< pair<int,int> > Tree[N];
queue<int> q;
bool visited[N];
int dist[N];
vector<int> ans;
vector<int> tmp;
int main()
{
	int n,k,d,i,u,v,j;
	scanf("%i %i %i",&n,&k,&d);
	for(i=0;i<k;i++)
	{
		scanf("%i",&u);
		if(!visited[u]) q.push(u);
		visited[u]=true;
	}
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		Tree[u].push_back(make_pair(v,i));
		Tree[v].push_back(make_pair(u,i));
	}
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<Tree[u].size();i++)
		{
			v=Tree[u][i].first;
			if(!visited[v])
			{
				visited[v]=true;
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		tmp.clear();
		for(j=0;j<Tree[i].size();j++)
		{
			v=Tree[i][j].first;
			if(dist[v]==dist[i]) ans.push_back(Tree[i][j].second);
			if(dist[v]<dist[i]) tmp.push_back(Tree[i][j].second);
		}
		for(j=1;j<tmp.size();j++) ans.push_back(tmp[j]);
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++) printf("%i ",ans[i]);
	printf("\n");
	return 0;
}