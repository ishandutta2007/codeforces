#include <stdio.h>
const long long inf=10000000000000ll;
long long dp[5050][5];
int pa[5050][5];
long long b[5050];
int a[5050];
long long sum(int l, int r)
{
	r--;
	l--;
	if(l==-1) return b[r];
	return b[r]-b[l];
}
int main()
{
	int n,i,j;
	long long tr;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	b[0]=a[0];
	for(i=1;i<n;i++) b[i]=b[i-1]+a[i];
	for(i=0;i<=n;i++)
	{
		dp[i][0]=-inf;
		for(j=0;j<=i;j++)
		{
			tr=sum(0,j)-sum(j,i);
			if(tr>dp[i][0])
			{
				dp[i][0]=tr;
				pa[i][0]=j;
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		dp[i][1]=-inf;
		for(j=0;j<=i;j++)
		{
			tr=dp[j][0]+sum(j,i)-sum(i,n);
			if(tr>dp[i][1])
			{
				dp[i][1]=tr;
				pa[i][1]=j;
			}
		}
	}
	long long sol=-inf;
	int taj;
	for(i=0;i<=n;i++)
	{
		if(dp[i][1]>sol)
		{
			sol=dp[i][1];
			taj=i;
		}
	}
	printf("%i %i %i\n",pa[pa[taj][1]][0],pa[taj][1],taj);
	return 0;
}