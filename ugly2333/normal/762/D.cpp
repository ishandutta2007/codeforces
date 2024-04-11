#include<iostream>
#include<cstdio>
using namespace std;
long long a[100005][3],dp[100005][3],x;
const long long inf = ((long long)1<<(22+32));
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<3;i=i+1)
		for(j=1;j<=n;j=j+1){
			scanf("%I64d",&a[j][i]);
			dp[j][i]=-inf;
		}
	/*dp[1][0]=a[1][0];
	dp[1][1]=dp[1][0]+a[1][1];
	dp[1][2]=dp[1][1]+a[1][2];
	for(i=2;i<=n;i=i+1)
	{
		dp[i][0]=a[i][0]+max(dp[i-1][0],a[i][1]+max(dp[i-1][1],a[i][2]+dp[i-1][2]));
		dp[i][0]=max(dp[i][0],dp[i-2][2]+a[i-1][0]+a[i-1][1]+a[i-1][2]+a[i][0]+a[i][1]+a[i][2]);
		dp[i][1]=a[i][1]+max(dp[i-1][1],max(a[i][0]+dp[i-1][0],a[i][2]+dp[i-1][2]));
		dp[i][2]=a[i][2]+max(dp[i-1][2],a[i][1]+max(dp[i-1][1],a[i][0]+dp[i-1][0]));
		dp[i][2]=max(dp[i][2],dp[i-2][0]+a[i-1][0]+a[i-1][1]+a[i-1][2]+a[i][0]+a[i][1]+a[i][2]);
	}*/
	dp[0][0]=0;
	dp[0][1]=-inf;
	dp[0][2]=-inf;
	for(i=0;i<n;i=i+1)
	{
		dp[i+1][0]=max(dp[i+1][0],dp[i][0]+a[i+1][0]);
		dp[i+1][0]=max(dp[i+1][0],dp[i][1]+a[i+1][1]+a[i+1][0]);
		dp[i+1][0]=max(dp[i+1][0],dp[i][2]+a[i+1][2]+a[i+1][1]+a[i+1][0]);
		
		dp[i+1][1]=max(dp[i+1][1],dp[i][1]+a[i+1][1]);
		dp[i+1][1]=max(dp[i+1][1],dp[i][0]+a[i+1][0]+a[i+1][1]);
		dp[i+1][1]=max(dp[i+1][1],dp[i][2]+a[i+1][2]+a[i+1][1]);
		
		dp[i+1][2]=max(dp[i+1][2],dp[i][2]+a[i+1][2]);
		dp[i+1][2]=max(dp[i+1][2],dp[i][1]+a[i+1][1]+a[i+1][2]);
		dp[i+1][2]=max(dp[i+1][2],dp[i][0]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
		
		if(i+2<=n){
			x=a[i+1][0]+a[i+1][1]+a[i+1][2]+a[i+2][0]+a[i+2][1]+a[i+2][2];
			dp[i+2][0]=max(dp[i+2][0],dp[i][2]+x);
			dp[i+2][2]=max(dp[i+2][2],dp[i][0]+x);
		}
	}
	/*for(i=0;i<3;i=i+1){
		for(j=1;j<=n;j=j+1){
			printf("%I64d ",dp[j][i]);
		}
		printf("\n");
	}*/
	printf("%I64d",dp[n][2]);
	return 0;
}