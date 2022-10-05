#include <bits/stdc++.h>
using namespace std;
int n,a[101],dp[101][3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",a+i);
	memset(dp,1,sizeof(dp));
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	for(int i=1;i<=n;i++){
		int s1=a[i]/2,s2=a[i]%2;
		if(s1)	dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if(s2)	dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
	}
	printf("%d\n",min(min(dp[n][0],dp[n][1]),dp[n][2]));
}