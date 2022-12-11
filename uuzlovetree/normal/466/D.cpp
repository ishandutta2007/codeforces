#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;
const ll mod = 1000000007;
int n,h;
int a[maxn];
ll dp[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]=h-a[i];
	for(int i=1;i<=n;++i)if(a[i]<0)
	{
		puts("0");exit(0);
	}
	a[0]=0;
	dp[0][0]=1;
	for(int i=0;i<=n;++i)
	{
		dp[i+1][a[i+1]]=(dp[i+1][a[i+1]]+dp[i][a[i+1]])%mod;
		dp[i+1][a[i+1]-1]=(dp[i+1][a[i+1]-1]+dp[i][a[i+1]-1]*a[i+1])%mod;
		dp[i+1][a[i+1]]=(dp[i+1][a[i+1]]+dp[i][a[i+1]-1])%mod;
		dp[i+1][a[i+1]-1]=(dp[i+1][a[i+1]-1]+dp[i][a[i+1]]*a[i+1])%mod;
	}
	printf("%I64d\n",dp[n+1][0]);
	return 0;
}