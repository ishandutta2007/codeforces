#include <stdio.h>
#include <vector>
using namespace std;
int max(int a, int b){ return a>b?a:b;}
const int N=1050;
vector<int> E[N];
int cnt,all,Max,sol,t[N];
bool vis[N];
void DFS(int u)
{
	cnt++;all++;vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int main()
{
	int n,m,k,i,u,v;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=k;i++) scanf("%i",&t[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=k;i++)
	{
		cnt=0;DFS(t[i]);
		sol+=cnt*(cnt-1)/2;
		Max=max(Max,cnt);
	}
	sol-=Max*(Max-1)/2;
	Max+=n-all;
	sol+=Max*(Max-1)/2;
	sol-=m;
	printf("%i\n",sol);
	return 0;
}