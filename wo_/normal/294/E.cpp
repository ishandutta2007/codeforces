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

vector<edge> G[5050];

int u[5050],v[5050],cost[5050];

int sz[5050];

int N;

int dfs(int v,int p)
{
	int c=1;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==p) continue;
		c+=dfs(G[v][i].to,v);
	}
	sz[v]=c;
	return c;
}

long long rec(int v,int p,int t)
{
	long long best=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==p) continue;
		long long tmp=rec(G[v][i].to,v,t);
		int x=sz[G[v][i].to];
		int a=x*(N-x);
		int b=(x+t)*(N-x-t);
		tmp+=(long long)(a-b)*G[v][i].cost;
		best=max(best,tmp);
	}
	return best;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		scanf("%d%d%d",u+i,v+i,cost+i);
		u[i]--;v[i]--;
		G[u[i]].push_back(edge(v[i],cost[i]));
		G[v[i]].push_back(edge(u[i],cost[i]));
	}
	long long total=0;
	dfs(0,-1);
	for(int i=0;i<N-1;i++)
	{
		int x=min(sz[u[i]],sz[v[i]]);
		total+=(long long)cost[i]*(x*(N-x));
	}
	long long dec=0;
	for(int i=0;i<N-1;i++)
	{
		int uu=u[i],vv=v[i],c=cost[i];
		dfs(uu,vv);
		dfs(vv,uu);
		dec=max(dec,rec(uu,vv,sz[vv])+rec(vv,uu,sz[uu]));
	}
	cout<<total-dec<<"\n";
	return 0;
}