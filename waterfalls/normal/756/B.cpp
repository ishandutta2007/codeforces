#include <bits/stdc++.h>
using namespace std;

int n;
int t[100013];
int dp[100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<=n;i++) t[i] = 1.1e9;
	for (int i=1;i<=n;i++) {
		scanf("%d",&t[i]);
		dp[i] = dp[i-1]+20;
		int j = upper_bound(t+1,t+i+1,t[i]-90)-t;
		dp[i] = min(dp[i],dp[j-1]+50);
		j = upper_bound(t+1,t+i+1,t[i]-1440)-t;
		dp[i] = min(dp[i],dp[j-1]+120);
		printf("%d\n",dp[i]-dp[i-1]);
	}

	return 0;
}