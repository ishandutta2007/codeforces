#include <bits/stdc++.h>
using namespace std;

const int MN = 2002, mod=1e9+7;
int n, h, i, arr[MN], dp[MN][MN], j;
int add(int x,int y){return(x+y)%mod;}

int main(){
	for(scanf("%d%d",&n,&h),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	dp[1][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			if(j+arr[i]==h){
				dp[i+1][j]=add(dp[i+1][j],dp[i][j]);
				if(j) dp[i+1][j-1]=add(dp[i+1][j-1],(1LL*j*dp[i][j])%mod);
			}
			if(j+arr[i]+1==h){
				dp[i+1][j]=add(dp[i+1][j],(1LL*(j+1)*dp[i][j])%mod);
				dp[i+1][j+1]=add(dp[i+1][j+1],dp[i][j]);
			}
		}
	}
	printf("%d\n",dp[n+1][0]);
	return 0;
}