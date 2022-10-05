#include<bits/stdc++.h>

const int N = 100;
const int M = 20;
const int moder = 1e9 + 7;

char s[N];
int dp[N][1 << M];

int get_num(int sit, int len){
	int ans = 0;
	for (int i = sit; i < sit + len; ++ i){
		ans = 2 * ans + s[i] - '0';
		if (ans > M){
			return M + 1;
		}
	}
	return ans;
}

int main(){
	int len;
	scanf("%d%s", &len, s);
	for (int i = 0; i <= len; ++ i){
		dp[i][0] = 1;
	}
	for (int i = 0; i < len; ++ i){
		for (int k = 1; k <= len - i; ++ k){
			int x = get_num(i, k);
			if (x <= 0 || x > M){
				continue;
			}
			for (int j = 0; j < 1 << M; ++ j){
				if (i + k > len){
					break;
				}
				auto &u = dp[i + k][j | 1 << x - 1];
				u = (u + dp[i][j]) % moder;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= len; ++ i){
		for (int j = 1; j < M; ++ j){
			ans = (ans + dp[i][(1 << j) - 1]) % moder;
		}
	}
	return printf("%d\n", ans), 0;
}