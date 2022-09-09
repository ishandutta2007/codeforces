#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1005;
const int MAX_W=1005;
int dp[MAX_N][MAX_W];
int w[MAX_N],b[MAX_N];
vector<int> group[MAX_N];
int group_cnt;
vector<int> E[MAX_N];
bool visited[MAX_N];
void DFS(int u)
{
	visited[u]=1;
	group[group_cnt].push_back(u);
	for(int v:E[u])
	{
		if(!visited[v])
		{
			DFS(v);
		}
	}
}
int main()
{
	int n,m,W;
	scanf("%i %i %i",&n,&m,&W);
	for(int i=1;i<=n;i++)
	{
		scanf("%i",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%i",&b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
    for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			group_cnt++;
			DFS(i);
		}
	}
	for(int i=0;i<=W;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=group_cnt;i++)
	{
		int sum_w=0,sum_b=0;
		for(int id:group[i])
		{
			sum_w+=w[id];
			sum_b+=b[id];
		}
		for(int j=0;j<=W;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(int id:group[i])
			{
				if(j>=w[id])
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-w[id]]+b[id]);
				}
			}
			if(j>=sum_w)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-sum_w]+sum_b);
			}
		}
	}
	printf("%i\n",dp[group_cnt][W]);
	return 0;
}