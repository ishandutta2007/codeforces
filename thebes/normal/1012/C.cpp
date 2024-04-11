#include <bits/stdc++.h>
using namespace std;

const int MN=5005;
int dp[MN][MN], dp2[MN][MN], n, i, j, h[MN];
inline int c(int a,int b,int c){
	return max(0,b-a+1)+max(0,c-a+1);
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&h[i]);
	memset(dp,0x3f,sizeof(dp));
	memset(dp2,0x3f,sizeof(dp2));
	dp2[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			if(i>=2&&j>=1) dp[i][j]=min(dp[i][j],dp[i-2][j-1]+c(h[i],h[i-2]-1,h[i+1]));
            if(j>=1)dp[i][j]=min(dp[i][j],dp2[i-1][j-1]+c(h[i],h[i-1],h[i+1]));
			dp2[i][j]=min(dp2[i-1][j],dp[i-1][j]);
		}
	}
	for(i=1;i<=ceil(n/2.0);i++)
		printf("%d ",min(dp2[n][i],dp[n][i]));
	return 0;
}