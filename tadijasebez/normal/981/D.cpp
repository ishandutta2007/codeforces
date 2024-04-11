#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=55;
ll a[N];
int n,k;
bool dp[N][N];
bool Check(ll val)
{
	int i,j,l;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j]=0;
	dp[0][0]=1;
	for(i=1;i<=k;i++)
	{
		for(j=i;j<=n;j++)
		{
			ll sum=0;
			for(l=j-1;l>=0;l--)
			{
				sum+=a[l+1];
				if((sum&val)==val && dp[i-1][l]){ dp[i][j]=1;break;}
			}
		}
	}
	return dp[k][n];
}
int main()
{
	int i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll sol=0;
	for(i=62;~i;i--)
	{
		if(Check(sol^((ll)1<<i))) sol^=(ll)1<<i;
	}
	printf("%lld\n",sol);
	return 0;
}