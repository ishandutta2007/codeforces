#include <stdio.h>
const int N=1005;
int a[6][N],pl[6][N],dp[N],sol,n,k;
int max(int a, int b){ return a>b?a:b;}
bool Check(int x, int y)
{
	for(int i=1;i<=k;i++) if(pl[i][x]>pl[i][y]) return 0;
	return 1;
}
int main()
{
	int i,j;
	scanf("%i %i",&n,&k);
	for(j=1;j<=k;j++) for(i=1;i<=n;i++) scanf("%i",&a[j][i]),pl[j][a[j][i]]=i;
	for(i=1;i<=n;i++)
	{
		dp[i]=1;
		for(j=1;j<i;j++) if(Check(a[1][j],a[1][i])) dp[i]=max(dp[i],dp[j]+1);
		sol=max(sol,dp[i]);
	}
	printf("%i\n",sol);
	return 0;
}