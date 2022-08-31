#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N=110000;
int A[N],n,dp[N][2];
int main(){
	while (1){
		scanf("%d",&n); if (n==0) return 0;
		for (int i=1;i<=n;i++) scanf("%d",&A[i]);
		memset(dp,0x00,sizeof dp);
		dp[1][0]=1; dp[2][1]=2;
		for (int i=2;i<=n;i++){
			if (A[i]>A[i-1]){
				dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
				dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
			}
			dp[i][0]=max(dp[i][0],1);
			dp[i][1]=max(dp[i][1],2);
			if (i>2&&A[i-2]+1<A[i]) dp[i][1]=max(dp[i][1],dp[i-2][0]+2);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			ans=max(ans,dp[i][0]+(i!=n));
			ans=max(ans,dp[i][1]);
		}
		printf("%d\n",ans);
		return 0;
	}
	return 0;
}