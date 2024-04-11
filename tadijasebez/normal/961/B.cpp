#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100050;
int a[N],b[N],t[N],dp[N][2];
int sum(int l, int r){ return b[r]-b[l-1];}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),b[i]=a[i]+b[i-1];
	for(i=1;i<=n;i++)
	{
		scanf("%i",&t[i]);
		dp[i][0]=dp[i-1][0]+t[i]*a[i];
	}
	for(i=n;i>=1;i--) dp[i][1]=dp[i+1][1]+t[i]*a[i];
	int sol=0;
	for(i=1;i<=n-k+1;i++)
	{
		sol=max(sol,dp[i-1][0]+dp[i+k][1]+sum(i,i+k-1));
	}
	printf("%i\n",sol);
	return 0;
}