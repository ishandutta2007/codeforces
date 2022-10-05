#include<bits/stdc++.h>

const int N = 100010;
const int M = 40;

bool dp[N][M];

int power(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret *= a;
		}
		a *= a;
	}
	return ret;
}

int main(){
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	for (int i = N - 1; i > 1; -- i){
		for (int j = M - 1; j; -- j){
			if (pow(i, j) > 1.5e9 || power(i, j) >= n){
				dp[i][j] = true;
			}
			else{
				dp[i][j] = !dp[i + 1][j] || !dp[i][j + 1];
			}
			if (i == N - 1 && j == 1 && i < n){
				dp[i][j] = !(n - i & 1);
			}
		}
	}
	if (a == 1){
		int now = 0;
		while (b <= 30 && 1 << b < n){
			if (!dp[a + 1][b]){
				return printf(now ? "Stas\n" : "Masha\n"), 0;
			}
			++ b;
			now ^= 1;
		}
		return printf("Missing\n"), 0;
	}
	return printf(dp[a][b] ? "Masha\n" : "Stas\n"), 0;
}