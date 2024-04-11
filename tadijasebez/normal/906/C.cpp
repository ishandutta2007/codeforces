#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=22;
const int inf=1e9;
int E[N],dp[1<<N],par[1<<N],taj[1<<N];
vector<int> sol;
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	if(n*(n-1)==m*2) return printf("0\n"),0;
	while(m--)
	{
		scanf("%i %i",&u,&v);
		u--;v--;
		E[u]|=1<<v;
		E[v]|=1<<u;
	}
	for(i=0;i<1<<n;i++) dp[i]=inf;
	for(i=0;i<n;i++) dp[1<<i]=0;
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!((i>>j)&1)) continue;
			if(dp[i]+1<dp[i|E[j]])
			{
				dp[i|E[j]]=dp[i]+1;
				par[i|E[j]]=i;
				taj[i|E[j]]=j;
			}
		}
	}
	printf("%i\n",dp[(1<<n)-1]);
	int c=(1<<n)-1;
	while(dp[c])
	{
		sol.push_back(taj[c]+1);
		c=par[c];
	}
	reverse(sol.begin(),sol.end());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	printf("\n");
	return 0;
}