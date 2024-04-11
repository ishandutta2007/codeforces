#include <stdio.h>
const int N=1000050;
int p[N],dp[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i,x,y;
	scanf("%i",&n);
	int sol=0;
	for(i=1;i<=n;i++) scanf("%i %i",&x,&y),p[x]=y,dp[x]=1;
	for(i=0;i<N;i++)
	{
		if(i-p[i]-1>=0)dp[i]+=dp[i-1-p[i]];
		sol=max(sol,dp[i]);
	}
	printf("%i\n",n-sol);
	return 0;
}