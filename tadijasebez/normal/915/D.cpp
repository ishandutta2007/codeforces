#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <vector>
using namespace std;
const int N=505;
vector<int> E[N];
int mark[N];
int cnt;
void DFS(int u)
{
	mark[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!mark[v]) DFS(v);
		else if(mark[v]==1) cnt++;
	}
	mark[u]=2;
}
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
	}
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(j=1;j<=n;j++) mark[j]=0;
		DFS(i);
		for(j=1;j<=n;j++) if(!mark[j]) DFS(j);
		if(cnt<=1) return printf("YES\n"),0;
	}
	printf("NO\n");
	return 0;
}