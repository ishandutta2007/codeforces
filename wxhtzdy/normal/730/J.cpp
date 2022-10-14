#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=105;
int a[N],b[N];
int dp[N][N*N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	for(int i=1;i<=n;i++)scanf("%i",&b[i]);
	for(int i=0;i<=n;i++)for(int j=0;j<N*N;j++)dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			for(int k=b[i];k<N*N;k++){
				dp[j][k]=max(dp[j][k],dp[j-1][k-b[i]]+a[i]);
			}
		}
	}
	int sumA=0;
	for(int i=1;i<=n;i++)sumA+=a[i];
	int ans=n+1,ret=0;
	for(int i=1;i<=n;i++){
		for(int k=sumA;k<N*N;k++){
			if(dp[i][k]>0){
				if(ans>i||ans==i&&ret>sumA-dp[i][k]){
					ans=i;
					ret=sumA-dp[i][k];
				}
			}
		}
	}
	printf("%i %i\n",ans,ret);
	return 0;
}