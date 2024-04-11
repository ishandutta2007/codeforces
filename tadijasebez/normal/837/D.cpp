#include <stdio.h>
int dp[205][5200];
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}
int main()
{
	int n,k,i,j,l;
	long long u;
	scanf("%i%i",&n,&k);
	for(i=0;i<205;i++)
		for(j=0;j<5200;j++)
			dp[i][j]=-1;
	dp[0][0]=0;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&u);
		int dva=0,pet=0;
		while(u%2==0) dva++,u/=2;
		while(u%5==0) pet++,u/=5;
		for(j=k-1;j>=0;j--)
		{
			for(l=0;l<5200-pet;l++)
			{
				if(dp[j][l]!=-1)
				{
					dp[j+1][l+pet]=max(dp[j+1][l+pet],dp[j][l]+dva);
				}
			}
		}
	}
	int sol=0;
	for(i=0;i<5200;i++) sol=max(sol,min(i,dp[k][i]));
	printf("%i\n",sol);
	return 0;
}