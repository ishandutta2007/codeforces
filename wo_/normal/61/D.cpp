#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
	int to,cost;
	edge(){}
	edge(int a,int b):to(a),cost(b){}
};

vector<edge> G[100100];

long long dfs(int v,int p)
{
	long long res=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==p) continue;
		long long tmp=dfs(G[v][i].to,v);
		tmp+=G[v][i].cost;
		res=max(res,tmp);
	}
	return res;
}

int main()
{
	int N;
	scanf("%d",&N);
	long long ans=0;
	for(int i=0;i<N-1;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u--;v--;
		G[u].push_back(edge(v,c));
		G[v].push_back(edge(u,c));
		ans+=2*c;
	}
	//printf("%d\n",ans-dfs(0,-1));
	cout<<ans-dfs(0,-1)<<"\n";
	return 0;
}