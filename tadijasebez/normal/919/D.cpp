#include <stdio.h>
#include <vector>
using namespace std;
const int N=300050;
vector<int> E[N];
int col[N];
bool bad;
void FindCycle(int u)
{
	col[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!col[v]) FindCycle(v);
		else if(col[v]==1) bad=1;
	}
	col[u]=2;
}
char s[N];
int dp[N][26];
int max(int a, int b){ return a>b?a:b;}
bool was[N];
void DFS(int u)
{
	if(was[u]) return;
	was[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);
		for(int j=0;j<26;j++) dp[u][j]=max(dp[u][j],dp[v][j]);
	}
	dp[u][s[u]-'a']++;
}
int main()
{
	int n,m,i,j,u,v;
	scanf("%i %i",&n,&m);
	scanf("%s",s+1);
	while(m--) scanf("%i %i",&u,&v),E[u].push_back(v);
	for(i=1;i<=n;i++) if(!col[i]) FindCycle(i);
	if(bad) return printf("-1\n"),0;
	int sol=0;
	for(i=1;i<=n;i++)
	{
		DFS(i);
		for(j=0;j<26;j++) sol=max(sol,dp[i][j]);
	}
	printf("%i\n",sol);
	return 0;
}