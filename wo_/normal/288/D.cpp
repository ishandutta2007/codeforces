#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[80800];

long long sz[80800],double_sum[80800];

int par[80800];

int dfs(int v,int p)
{
	par[v]=p;
	int c=1;
	long long dc=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		int tmp=dfs(G[v][i],v);
		c+=tmp;
		dc+=(long long)tmp*tmp;
	}
	sz[v]=c;
	double_sum[v]=dc;
	return c;
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
	dfs(0,-1);
	long long ans=0;
	for(int v=1;v<N;v++)
	{
		long long num1=(long long)sz[v]*(sz[v]-1)/2;
		long long num2=N-sz[v]-1;
		int p=par[v];
		long long a=N-sz[p];
		num2+=a*(N-a-1-sz[v]);
		num2+=((sz[p]-1)*(sz[p]-1)-double_sum[p])/2;
		num2-=(sz[v]*(sz[p]-1-sz[v]));
		ans+=num1*num2;
		a=N-sz[v];
		num1=a*(a-1)/2;
		num2=((sz[v]-1)*(sz[v]-1)-double_sum[v])/2;
		num2+=(sz[v]-1);
		ans+=num1*num2;
	}
	cout<<ans<<"\n";
	return 0;
}