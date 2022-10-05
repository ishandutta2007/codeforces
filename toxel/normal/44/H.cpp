#include<bits/stdc++.h>

const int N = 60;
typedef long long ll;

char s[N];
ll dp[N][10];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < 10; ++ i){
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; ++ i){
		for (int j = 0; j < 10; ++ j){
			int x = j + s[i] - '0';
			if (x & 1){
				dp[i][x + 1 >> 1] += dp[i - 1][j];
			}
			dp[i][x >> 1] += dp[i - 1][j];
		}
	}
	ll sum = 0;
	for (int i = 0; i < 10; ++ i){
		sum += dp[n - 1][i];
	}
	bool flag = true;
	for (int i = 1; i < n; ++ i){
		if (std::abs(s[i] - s[i - 1]) > 1){
			flag = false;
			break;
		}
	}
	sum -= flag;
	return printf("%I64d\n", sum), 0;
}