#include <stdio.h>
const int N=3050;
const int inf=1e9+7;
int s[N],c[N],dp[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&s[i]);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	int sol=inf;
	for(i=1;i<=n;i++)
	{
		dp[i]=inf;
		for(j=1;j<i;j++)
		{
			if(s[i]>s[j])
			{
				dp[i]=min(dp[i],c[i]+c[j]);
				sol=min(sol,dp[j]+c[i]);
			}
		}
		//printf("%i ",dp[i]);
	}
	if(sol>=inf) printf("-1\n");
	else printf("%i\n",sol);
	return 0;
}