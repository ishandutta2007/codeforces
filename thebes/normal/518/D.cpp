#include <bits/stdc++.h>
using namespace std;

const int MN = 2002;
long double dp[MN][MN], p, ex, tot;
int n, t, i, j;

int main(){
	scanf("%d%Lf%d",&n,&p,&t); dp[0][i] = 1;
	for(i=1;i<MN;i++) dp[0][i]=(1-p)*dp[0][i-1];
	for(i=1;i<=n;i++){
		for(j=1;j<=t;j++){
			if(i==n) dp[i][j]=dp[i][j-1]+dp[i-1][j-1]*p;
			else dp[i][j]=dp[i][j-1]*(1-p)+dp[i-1][j-1]*p;
		}
	}
	for(i=0;i<=n;i++){
		ex += i*dp[i][t];
		tot += dp[i][t];
	}
	printf("%.7Lf\n",ex/tot);
	return 0;
}