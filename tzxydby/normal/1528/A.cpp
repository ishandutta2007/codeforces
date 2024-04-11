#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N][2];
vector<int>e[N];
long long dp[N][2];
void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0]+abs(a[u][0]-a[v][0]),dp[v][1]+abs(a[u][0]-a[v][1]));
		dp[u][1]+=max(dp[v][0]+abs(a[u][1]-a[v][0]),dp[v][1]+abs(a[u][1]-a[v][1]));
	}	
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		dp[i][0]=dp[i][1]=0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}