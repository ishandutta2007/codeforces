#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
//int max(int a, int b){ return a>b?a:b;}
ll max(ll a, ll b){ return a>b?a:b;}
int dp[N][2];
vector<int> E[N];
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(j=0;j<E[i].size();j++)
		{
			v=E[i][j];
			if(v<i) dp[i][0]=max(dp[i][0],dp[v][0]+1);
		}
	}
	for(i=n;i>=1;i--)
	{
		dp[i][1]=1;
		for(j=0;j<E[i].size();j++)
		{
			v=E[i][j];
			if(v>i) dp[i][1]=max(dp[i][1],dp[v][1]+1);
		}
	}
	ll sol=0;
	for(i=1;i<=n;i++) sol=max(sol,(ll)dp[i][0]*(signed)E[i].size());
	printf("%lld\n",sol);
	return 0;
}