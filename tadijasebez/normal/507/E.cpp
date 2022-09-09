#include <stdio.h>
#include <vector>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int N=100050;
#define mp make_pair
#define pb push_back
vector<pair<int,int> > E[N];
int dp[N],dist[N],n,go[N],mark[N];
queue<int> q;
int max(int a, int b){ return a>b?a:b;}
void BFS()
{
	int i;
	for(i=1;i<=n;i++) dist[i]=N,dp[i]=0;
	dist[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i].first;
			int z=E[u][i].second;
			if(dist[v]>dist[u]+1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
			if(dist[v]==dist[u]+1)
			{
				dp[v]=max(dp[v],dp[u]+z);
				if(dp[v]==dp[u]+z) go[v]=u,mark[v]=z;
			}
		}
	}
}
vector<pair<pair<int,int> ,int> > sol;
set<pair<pair<int,int> ,int> > edges;
set<pair<pair<int,int> ,int> >::iterator it;
int main()
{
	int m,i,u,v,z,c=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u,&v,&z);
		E[u].pb(mp(v,z));
		E[v].pb(mp(u,z));
		c+=z;
		edges.insert(mp(mp(u,v),z));
	}
	BFS();
	//printf("%i %i\n",dist[n],dp[n]);
	for(i=n;i!=1;i=go[i])
	{
		u=i;
		v=go[i];
		z=mark[i];
		//printf("->%i %i %i<-\n",u,v,z);
		if(!mark[i])
		{
			
			if(edges.count(mp(mp(u,v),z)))
			{
				sol.pb(mp(mp(u,v),1));
			}
			else
			{
				sol.pb(mp(mp(v,u),1));
			}
		}
		if(edges.count(mp(mp(u,v),z)))
		{
			edges.erase(mp(mp(u,v),z));
		}
		else
		{
			edges.erase(mp(mp(v,u),z));
		}
	}
	for(it=edges.begin();it!=edges.end();it++)
	{
		if(it->second==1) sol.pb(mp(it->first,0));
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++)
	{
		printf("%i %i %i\n",sol[i].first.first,sol[i].first.second,sol[i].second);
	}
	return 0;
}