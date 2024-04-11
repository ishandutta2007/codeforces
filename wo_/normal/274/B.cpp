#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long plu[100100],minu[100100];
bool visited[100100];
bool leaf[100100];

vector<int> G[100100];
int par[100100];
int a[100100];

void rec(int v)
{
	if(visited[v]) return;
	visited[v]=true;
	if(leaf[v])
	{
		plu[v]=0;minu[v]=0;
		if(a[v]>0) minu[v]=a[v];
		if(a[v]<0) plu[v]=-a[v];
		return;
	}
	for(int i=0;i<G[v].size();i++) rec(G[v][i]);
	long long pM=0,mM=0;
	for(int i=0;i<G[v].size();i++)
	{
		pM=max(pM,plu[G[v][i]]);
		mM=max(mM,minu[G[v][i]]);
	}
	long long tmp=a[v]+pM-mM;
	plu[v]=pM,minu[v]=mM;
	if(tmp>0) minu[v]+=tmp;
	else plu[v]+=(-tmp);
}

void dfs(int v,int p)
{
	par[v]=p;
	leaf[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
		leaf[v]=false;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	dfs(0,-1);
	rec(0);
	cout<<plu[0]+minu[0]<<"\n";
	return 0;
}