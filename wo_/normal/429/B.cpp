#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[1010][1010];
int N,M;

long long getA(int i,int j){
	if(i>=0&&i<N&&j>=0&&j<M) return a[i][j];
	return -1;
}

long long dp[4][1010][1010];

int main(){
	cin>>N>>M;
	for(int i=0;i<=N+1;i++) for(int j=0;j<=M+1;j++){
		a[i][j]=-(1ll<<50);
		for(int k=0;k<4;k++) dp[k][i][j]=-(1ll<<50);
	}
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>a[i][j];
	dp[0][0][1]=0;
	dp[1][N][0]=0;
	dp[2][N+1][M]=0;
	dp[3][1][M+1]=0;
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
		dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1])+a[i][j];
	}
	for(int i=N;i>=1;i--) for(int j=1;j<=M;j++){
		dp[1][i][j]=max(dp[1][i+1][j],dp[1][i][j-1])+a[i][j];
	}
	for(int i=N;i>=1;i--) for(int j=M;j>=1;j--){
		dp[2][i][j]=max(dp[2][i][j+1],dp[2][i+1][j])+a[i][j];
	}
	for(int i=1;i<=N;i++) for(int j=M;j>=1;j--){
		dp[3][i][j]=max(dp[3][i-1][j],dp[3][i][j+1])+a[i][j];
	}
	long long ans=-(1ll<<50);
	for(int i=2;i<=N-1;i++) for(int j=2;j<=M-1;j++){
		long long tmp=dp[0][i][j-1]+dp[1][i+1][j]+dp[2][i][j+1]+dp[3][i-1][j];
		ans=max(ans,tmp);
		tmp=dp[0][i-1][j]+dp[1][i][j-1]+dp[2][i+1][j]+dp[3][i][j+1];
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}