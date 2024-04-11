#include <stdio.h>
const int N=100050;
int dp[N];
bool vis[N];
int a[N];
int main()
{
	int n,q,i,x;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>=1;i--)
	{
		dp[i]=dp[i+1]+(vis[a[i]]?0:1);
		vis[a[i]]=true;
	}
	while(q--)
	{
		scanf("%i",&x);
		printf("%i\n",dp[x]);
	}
	return 0;
}