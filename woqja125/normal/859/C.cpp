#include<stdio.h>
int in[51];
int dp[52];
int max(const int &a, const int &b){return a>b?a:b;}
int main(){
	int n, s=0, m;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", in+i), s+=in[i];
	dp[n] = in[n];
	for(int i=n-1; i>=1; i--){
		dp[i] = max(dp[i+1] - in[i], in[i] - dp[i+1]);
	}
	int y = (s-dp[1])/2;
	int x = y + dp[1];
	printf("%d %d\n", y, x);
	return 0;
}