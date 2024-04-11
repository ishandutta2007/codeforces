#include <stdio.h>
const int N=300050;
int dp[N][2],sol,pos,a[N];
int main()
{
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1],dp[i][a[i]]++;
	j=1;
	for(i=1;i<=n;i++)
	{
		for(;j<=n && dp[j][0]-dp[i-1][0]<=k;j++);
		j--;
		if(j-i+1>=sol) sol=j-i+1,pos=i;
	}
	printf("%i\n",sol);
	for(i=pos;i<=n && k;i++) if(!a[i]) a[i]=1,k--;
	for(i=1;i<=n;i++) printf("%i ",a[i]);printf("\n");
	return 0;
}