#include <stdio.h>
const int N=100050;
const int inf=1000000007;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int a[N],dp[N];
int sol=-inf;
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	dp[n]=a[n];
	for(i=n-1;i;i--) dp[i]=min(dp[i+1],a[i]);
	if(k==1) return printf("%i\n",dp[1]),0;
	if(k==2)
	{
		int tmp=a[1];
		for(i=2;i<=n;i++)
		{
			sol=max(sol,max(tmp,dp[i]));
			tmp=min(tmp,a[i]);
		}
	}
	else for(i=1;i<=n;i++) sol=max(sol,a[i]);
	printf("%i\n",sol);
	return 0;
}