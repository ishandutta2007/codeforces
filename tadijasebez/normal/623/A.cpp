#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const int N=505;
vector<int> E[N],vec[2];
bool go[N][N],vis[N];
char sol[N];
int dep[N],cnt;
void DFS(int u, int d)
{
	cnt++;
	vis[u]=1;
	vec[d].push_back(u);
	dep[u]=d;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) DFS(v,d^1);
		else if(dep[u]==dep[v])
		{
			printf("No\n");
			exit(0);
		}
	}
}
int main()
{
	int n,m,v,u,i,g;
	scanf("%i %i",&n,&m);
	g=n*(n-1)/2-m;
	while(m--) scanf("%i %i",&u,&v),go[u][v]=go[v][u]=1;
	for(u=1;u<=n;u++) for(v=1;v<=n;v++) if(v!=u && !go[u][v]) E[u].push_back(v);
	for(i=1;i<=n;i++) sol[i]='b';
	for(i=1;i<=n;i++) if(!vis[i])
	{
		cnt=0;
		DFS(i,0);
		if(cnt==1) vec[0].pop_back();
	}
	for(i=0;i<vec[0].size();i++) sol[vec[0][i]]='a';
	for(i=0;i<vec[1].size();i++) sol[vec[1][i]]='c';
	if(g!=vec[0].size()*vec[1].size()) return printf("No\n"),0;
	printf("Yes\n");
	for(i=1;i<=n;i++) printf("%c",sol[i]);printf("\n");
	return 0;
}