#include <stdio.h>
const int N=5050;
int dp[N][N],a[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	for(i=0;i<n;i++) for(j=0;j<n;j++) dp[i][j]=(i==0?0:dp[i-1][j])+(a[i]<j);
	int all=0;
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(a[i]>a[j]) all++;
	int sol=N*N,cnt=0;
	for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(a[i]>a[j])
	{
		int ans=all+2*(dp[i][a[i]]+dp[j][a[j]]-dp[i][a[j]]-dp[j][a[i]])+1;
		if(sol>ans) sol=ans,cnt=0;
		if(sol==ans) cnt++;
	}
	printf("%i %i\n",sol,cnt);
	return 0;
}