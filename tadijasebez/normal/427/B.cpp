#include <stdio.h>
const int N=200050;
int dp[N],sol;
int main()
{
	int n,c,t,i,x;
	scanf("%i %i %i",&n,&t,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x>t) dp[i]=1;
		dp[i]+=dp[i-1];
		if(i>=c) sol+=dp[i]==dp[i-c];
	}
	printf("%i\n",sol);
	return 0;
}