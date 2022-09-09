#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
bool visited[N];
int x[N];
vector<pair<int,int> > Graph[N];
vector<int> pl,dl;
void DFS(int cur)
{
	visited[cur]=true;
	int i;
	for(i=0;i<Graph[cur].size();i++)
	{
		int v=Graph[cur][i].first;
		int w=Graph[cur][i].second;
		if(!visited[v])
		{
			x[v]=x[cur]^w;
			DFS(v);
		}
		else
		{
			pl.push_back(x[v]^x[cur]^w);
		}
	}
}
int main()
{
	int n,m,i,j,u,v,w;
	scanf("%i %i",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%i%i%i",&u,&v,&w);
		Graph[u].push_back(make_pair(v,w));
		Graph[v].push_back(make_pair(u,w));
	}
	DFS(1);
	for(j=30;j>-1;j--)
	{
		bool ok=false;
		int tmp;
		for(i=0;i<pl.size();i++)
			if(pl[i]&(1<<j))
			{
				dl.push_back(pl[i]);
				tmp=pl[i];
				pl.erase(pl.begin()+i);
				ok=true;
				break;
			}
		if(ok)
		{
			for(i=0;i<pl.size();i++)
				if(pl[i]&(1<<j)) pl[i]^=tmp;
		}
	}
	for(i=0;i<dl.size();i++)
		if((x[n]^dl[i])<x[n]) x[n]^=dl[i];
	printf("%i\n",x[n]);
	return 0;
}