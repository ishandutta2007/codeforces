#include<bits/stdc++.h>

const int N = 110;

int dp[N], a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < i; ++ j){
			if (a[i] || !a[i] && !a[j]){
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; ++ i){
		max = std::max(max, dp[i]);
	}
	return printf("%d\n", max), 0;
}