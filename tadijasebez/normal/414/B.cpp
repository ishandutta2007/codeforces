#include <stdio.h>
#include <vector>
using namespace std;
const int N=2050;
const int mod=1e9+7;
vector<int> Divisors[N];
int dp[N][N];
int Recur(int n, int k)
{
	if(k==0) return 1;
	if(dp[n][k]>0) return dp[n][k];
	int i;
	for(i=0;i<Divisors[n].size();i++)
	{
		int d=Divisors[n][i];
		dp[n][k]=(1ll*dp[n][k]+Recur(d,k-1))%mod;
	}
	return dp[n][k];
}
int sol;
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				Divisors[i].push_back(j);
				if(i!=j*j) Divisors[i].push_back(i/j);
			}
		}
	}
	for(i=1;i<=n;i++) sol=(1ll*sol+Recur(i,k-1))%mod;
	printf("%i\n",sol);
	return 0;
}