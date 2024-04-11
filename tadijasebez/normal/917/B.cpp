#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=107;
vector<int> E[N][26];
int dp[N][N][26];
int Recur(int u, int v, int w)
{
	//printf("%i %i %i\n",u,v,w);
	if(dp[u][v][w]!=-1) return dp[u][v][w];
	int i;
	for(i=0;i<E[u][w].size();i++)
	{
		int nx=E[u][w][i];
		if(!Recur(v,nx,w)) return dp[u][v][w]=1;
	}
	if(w<25) if(Recur(u,v,w+1)) return dp[u][v][w]=1;
	return dp[u][v][w]=0;
}
int main()
{
	int n,m,i,j,k,u,v;
	char w;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %c",&u,&v,&w);
		w-='a';
		E[u][w].push_back(v);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) for(k=0;k<26;k++) dp[i][j][k]=-1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(Recur(i,j,0)) printf("A");
			else printf("B");
		}
		printf("\n");
	}
	return 0;
}