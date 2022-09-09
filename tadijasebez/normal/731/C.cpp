#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
vector<int> E[N],Back;
int c[N],cnt,Max,C[N],sol;
int max(int a, int b){ return a>b?a:b;}
bool vis[N];
void DFS(int u)
{
	vis[u]=1;
	C[c[u]]++;
	Max=max(Max,C[c[u]]);
	Back.push_back(c[u]);
	cnt++;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int main()
{
	int n,m,k,i,u,v,j;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt=0;Max=0;
			for(j=0;j<Back.size();j++) C[Back[j]]=0;
			Back.clear();
			DFS(i);
			sol+=cnt-Max;
		}
		//printf("%i\n",sol);
	}
	printf("%i\n",sol);
	return 0;
}