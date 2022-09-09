#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=5050;
const ll inf=1e15;
ll min(ll a, ll b){ return a>b?b:a;}
vector< pair<int,int> > E[N];
ll dp[N][N];
int n;
bool vis[N];
void DFS(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	int i,j;
	for(i=1;i<=n;i++) dp[u][i]=inf;
	if(u==n) dp[u][1]=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		DFS(v);
		for(j=1;j<n;j++) dp[u][j+1]=min(dp[u][j+1],dp[v][j]+w);
	}
}
void Print(int u, int t)
{
	printf("%i ",u);
	if(t==1) return;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		if(dp[u][t]==dp[v][t-1]+w){ Print(v,t-1);return;}
	}
}
int main()
{
	int m,t,u,v,w,i;
	scanf("%i %i %i",&n,&m,&t);
	while(m--)
	{
		scanf("%i %i %i",&u,&v,&w);
		E[u].push_back(make_pair(v,w));
	}
	DFS(1);
	int sol=0;
	for(i=1;i<=n;i++) if(dp[1][i]<=t) sol=i;
	printf("%i\n",sol);
	Print(1,sol);
	return 0;
}