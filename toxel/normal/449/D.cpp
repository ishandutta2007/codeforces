#include<bits/stdc++.h>

const int N = 20;
const int moder = 1e9 + 7;
inline int lowbit(int n){return n & -n;}

template <typename T>
T read(){
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9'){
		ch = getchar();
	}
	T ret = 0;
	while (ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int dp[1 << N][N + 1];
int bitcnt[1 << N];

int main(){
	for (int i = 1; i < 1 << N; ++ i){
		bitcnt[i] = bitcnt[i ^ lowbit(i)] + 1;
	}
	int n = read <int>();
	while (n --){
		int x = read <int>();
		++ dp[x][0];
	}
	for (int i = (1 << N) - 1; i >= 0; -- i){
		for (int j = 1; j <= N; ++ j){
			dp[i][j] = dp[i][j - 1] + (i >> j - 1 & 1 ? 0 : dp[i ^ 1 << j - 1][j - 1]);
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << N; ++ i){
		ans = (ans + (bitcnt[i] & 1 ? -1 : 1) * (powermod(2, dp[i][N]) - 1)) % moder;
		ans += ans < 0 ? moder : 0;
	}
	return printf("%d\n", ans), 0;
}