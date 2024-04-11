#include <stdio.h>
const int N=10000;
bool vis[N];
int r[N];
void DFS(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	for(int i=u+1;i<=r[u];i++) DFS(i);
}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		r[u]=max(r[u],v);
	}
	DFS(0);
	if(vis[m]) printf("YES\n");
	else printf("NO\n");
	return 0;
}