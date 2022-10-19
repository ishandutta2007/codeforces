#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 300005;

int n , m , ans , two , one , l , r ,k , a[N] , dp[N][31];

int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) {
		scanf("%d",&a[i]); a[i] /= 100;
	}
	
	memset(dp , 127 ,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 0;i < n;i ++) {
		for(int j = 0;j <= 30;j ++) if(dp[i][j] <= 2e8){
			if(j + a[i + 1] / 10 <= 30) dp[i + 1][j + a[i + 1] / 10] = min(dp[i + 1][j + a[i + 1] / 10] , dp[i][j] + a[i + 1]);
			if(j >= a[i + 1]) dp[i + 1][j - a[i + 1]] = min(dp[i + 1][j - a[i + 1]] , dp[i][j]);
			else dp[i + 1][0] = min(dp[i + 1][0] , dp[i][j] + (a[i + 1] - j)); 
		}
	}
	int ans = 2e9;
	for(int i = 0;i <= 30;i ++) {
		ans = min(ans , dp[n][i]);
	}
	printf("%d00\n",ans);
}