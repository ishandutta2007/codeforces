#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
bool vis[N];
int cnt;
void DFS(int u)
{
	vis[u]=1;
	cnt++;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v);
	}
}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	if(n!=m) return printf("NO\n"),0;
	while(m--) 
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1);
	if(cnt!=n) printf("NO\n");
	else printf("FHTAGN!\n");
	return 0;
}