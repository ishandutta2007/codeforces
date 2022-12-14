#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int a[1100100];
long long dp[1100100][3];
int N;

const long long inf=1e16;

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<=N;i++) for(int j=0;j<3;j++) dp[i][j]=-inf;
	dp[0][2]=0;
	for(int i=1;i<N;i++){
		long long dif=(long long)a[i]-a[i-1];
		dp[i][0]=max(dp[i-1][0],dp[i-1][2])+dif;
		dp[i][1]=max(dp[i-1][1],dp[i-1][2])-dif;
		dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
	}
	long long ans=-inf;
	for(int i=0;i<3;i++) ans=max(ans,dp[N-1][i]);
	cout<<ans<<"\n";
	return 0;
}