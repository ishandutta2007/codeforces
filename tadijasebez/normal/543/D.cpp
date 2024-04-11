#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=200050;
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int dp[N],sol[N];
vector<int> E[N];
void DFS(int u, int p)
{
	dp[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		DFS(v,u);
		dp[u]=(ll)dp[u]*(dp[v]+1)%mod;
	}
}
void Solve(int u, int p, int d)
{
	sol[u]=(ll)dp[u]*(d+1)%mod;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v==p) continue;
		int dd;
		if(dp[v]==mod-1)
		{
			dd=(d+1)%mod;
			for(int j=0;j<E[u].size();j++)
			{
				int h=E[u][j];
				if(j==i) continue;
				if(h==p) continue;
				dd=(ll)dd*(dp[h]+1)%mod;
			}
		}
		else dd=(ll)sol[u]*pow((dp[v]+1)%mod,mod-2)%mod;
		Solve(v,u,dd);
	}
}
int main()
{
	int n,u,i;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&u),E[u].push_back(i);
	DFS(1,0);
	Solve(1,0,0);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}