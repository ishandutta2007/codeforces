#include <stdio.h>
#include <set>
using namespace std;
const int N=200050;
const int M=2*N;
#define mp make_pair
set<pair<int,int> > E[M];
int col[N];
void SolvePath(int u, int c)
{
	if(E[u].size()&1)
	{
		int v=E[u].begin()->first;
		int e=E[u].begin()->second;
		col[e]=c;
		E[u].erase(mp(v,e));
		E[v].erase(mp(u,e));
		SolvePath(v,c^1);
	}
}
void SolveCycle(int u, int c)
{
	if(E[u].size())
	{
		int v=E[u].begin()->first;
		int e=E[u].begin()->second;
		col[e]=c;
		E[u].erase(mp(v,e));
		E[v].erase(mp(u,e));
		SolveCycle(v,c^1);
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&u,&v),v+=N,E[u].insert(mp(v,i)),E[v].insert(mp(u,i));
	for(i=1;i<M;i++) SolvePath(i,1);
	for(i=1;i<M;i++) SolveCycle(i,1);
	for(i=1;i<=n;i++)
	{
		if(col[i]) printf("r");
		else printf("b");
	}
	printf("\n");
	return 0;
}