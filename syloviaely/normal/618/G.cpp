#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
double A[1100][60],B[1100][60],dp[1100][60];
int n;
double p;
int lim=1000,K=50;
double solve(int n){
	memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B);
	memset(dp,0x00,sizeof dp);
	for (int i=1;i<=n;i++){
		A[i][1]=p; A[i][2]=1-p;
		B[i][2]=1;
		for (int j=1;j<=K+1;j++){
			A[i][j]+=A[i][j-1]*A[i-1][j-1];
			B[i][j]+=B[i][j-1]*A[i-1][j-1];
		}
	}
	dp[1][1]=p*(1-p);
	for (int i=2;i<=K;i++) dp[1][i]=A[n][i]-A[n][i+1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=K;j++)
			if (j==1)
				for (int k=2;k<=K;k++) dp[i][k]+=dp[i-1][j]*(B[n-i+1][k]-B[n-i+1][k+1]);
			else if (j==2) dp[i][1]+=dp[i-1][2];
			else if (i==n)
				for (int k=1;k<j;k++) dp[i][k]+=dp[i-1][j]*A[1][k];
			else for (int k=1;k<j;k++){
				double k1=A[n-i+1][k]-A[n-i+1][k+1]; if (k==1) k1=p*(1-p);
				dp[i][k]+=dp[i-1][j]*k1/(1-A[n-i+1][j]);
			}
	double ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=K;j++) ans=ans+dp[i][j]*j;
	return ans;
}
int main(){
	scanf("%d%lf",&n,&p); p/=1000000000;
	if (n==1){
		printf("%.11lf\n",p+2*(1-p));
		return 0;
	}
	if (n<=lim){
		printf("%.11lf\n",solve(n)); return 0;
	}
	double k1=solve(lim),k2=solve(lim-1);
	double ans=k1+(k1-k2)*(n-lim);
	printf("%.11lf\n",ans);
	return 0;
}