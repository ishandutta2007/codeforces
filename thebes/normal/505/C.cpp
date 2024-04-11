#include <bits/stdc++.h>
using namespace std;

const int MN = 3e4+4, MS = 606;
int cnt[MN], dp[3*MN][MS], n, m, i, x, j;

int main(){
	for(scanf("%d%d",&n,&m);i<n;i++){
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=MN;i>=0;i--){
		for(j=0;j<MS;j++){
			if(m-300+j<=0) continue;
			int p=m-300+j;
			if(i+p<=MN) dp[i][j]=max(dp[i][j],dp[i+p][j]);
			if(i+p+1<=MN) dp[i][j]=max(dp[i][j],dp[i+p+1][j+1]);
			if(i+p-1<=MN) dp[i][j]=max(dp[i][j],dp[i+p-1][j-1]);
			dp[i][j]+=cnt[i];
		}
	}
	printf("%d\n",cnt[0]+dp[m][300]);
	return 0;
}