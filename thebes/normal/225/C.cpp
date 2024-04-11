#include <bits/stdc++.h>
using namespace std;

const int MN = 1003;
int cost[MN][2], N, M, i, j, x, y, dp[MN][2];
char c;

int main(){
	for(scanf("%d%d%d%d",&N,&M,&x,&y),i=1;i<=N;i++){
		for(getchar(),j=1;j<=M;j++){
			scanf("%c",&c);
			if(c=='#') cost[j][0]++;
		}
	}
	for(i=1;i<=M;i++) cost[i][1]=N-cost[i][0];
	for(i=1;i<=M;i++){
		int a=0, b=0;
		dp[i][0]=dp[i][1]=1<<30;
		for(j=i;j>=max(1,i-y+1);j--){
			a += cost[j][0];
			b += cost[j][1];
			if(j-1<=i-x){
				dp[i][0]=min(dp[i][0],a+dp[j-1][1]);
				dp[i][1]=min(dp[i][1],b+dp[j-1][0]);
			}
		}
	}
	printf("%d\n",min(dp[M][0],dp[M][1]));
	return 0;
}