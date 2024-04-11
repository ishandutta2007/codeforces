#include<bits/stdc++.h>

const int M = 10010;

int dp[M];
int n, x;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 1, y; i <= n; ++ i){
		scanf("%d", &y);
		y *= (n - i + 1);
		for (int j = x; j >= 0; -- j){
			if (j + y > x) continue;
			dp[j + y] = std::max(dp[j + y], dp[j] + 1);
		}
	}
	int max = 0;
	for (int i = 0; i <= x; ++ i){
		max = std::max(max, dp[i]);
	}
	return printf("%d\n", max), 0;
}