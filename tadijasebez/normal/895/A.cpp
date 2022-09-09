#include <stdio.h>
#include <cstring>
#define ll long int
const int N=100050;
int dp[N],a[N];
int aps(int x){ return x>0?x:-x;}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j,sol=360;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),dp[i]=dp[i-1]+a[i];
	for(i=0;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			int b=dp[j]-dp[i];
			int c=360-b;
			sol=min(sol,aps(b-c));
		}
	}
	printf("%i\n",sol);
	return 0;
}