#include<bits/stdc++.h>
using namespace std;
int n, d, modulo;
int inv[99];
const int N(1111);
int dp[N][N][15];
int f(int i, int j, int k) {
	if(dp[i][j][k] != -1) {
		return dp[i][j][k];
	}else if(i == 0 && j == 0 && k == 0) {
		return 1;
	}else if(j == 0) {
		return 0;
	}else if(dp[i][j][k] != -1) {
		return dp[i][j][k];
	}else {
		int & res(dp[i][j][k]);
		res = 0;
		int x(j == 1 ? 1 : f(j - 1, j - 1, d));
		int lst(1);
		for(int o(0); o * j <= i && o <= k; o++) {
			res = (res + (long long)f(i - o * j, j - 1, k - o) * lst) % modulo;
			lst = (long long)lst * (x + o + modulo) % modulo * inv[o + 1] % modulo;
		}
		return res;
	}
}
int pw(int x, int n) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = (long long)res * x % modulo;
		}
		x = (long long)x * x % modulo;
		n /= 2;
	}
	return res;
}
int main() {
	scanf("%d%d%d", &n, &d, &modulo);
	d--;
	if(d == 1 || n <= 2) {
		printf("1\n");
		return 0;
	}
	for(int i(1); i <= d + 1; i++) {
		inv[i] = pw(i, modulo - 2);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 1;
	f(n - 1, n - 1, d + 1);
	for(int i(0); i <= n - 1; i++) {
		f(i, i, d + 1);
		f(i, i, d);
	}
	int ans(dp[n - 1][n - 1][d + 1]);
	dp[0][0][d] = 0;
	for(int i(1); i <= n - i; i++) {
		//printf("%d %d %d %d\n", i, n - i, dp[i - 1][i - 1][d], dp[n - i - 1][n - i - 1][d]);
		ans = (ans - (long long)dp[i - 1][i - 1][d] * dp[n - i - 1][n - i - 1][d] % modulo + modulo) % modulo;
	//printf("%d\n", ans);
	}
	//printf("%d\n", ans);
	if(n % 2 == 0) {
		ans = (ans + (long long)(dp[n / 2 - 1][n / 2 - 1][d]) * (dp[n / 2 - 1][n / 2 - 1][d] + 1) / 2) % modulo;
	}
	printf("%d\n", ans);
}