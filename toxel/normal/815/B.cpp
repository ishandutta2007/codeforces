#include<bits/stdc++.h>

const int N = 200010;
const int moder = 1e9 + 7;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int fac[N], inv[N];
int a[N], coe[N], temp[2][N];
int n;

int comb(int n, int m){
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int x = (n - 1) / 4, left = n - 1 - x * 4;
	for (int i = 0; i <= left; ++ i){
		for (int j = 0; j <= x * 4; j += 2){
			temp[0][i] = (temp[0][i] + 1ll * a[i + j] * comb(x << 1, j >> 1)) % moder;
		}
	}
	int now = 1;
	for (int i = left; i; -- i){
		for (int j = 0; j < i; ++ j){
			temp[1][j] = temp[0][j] + (now ? temp[0][j + 1] : -temp[0][j + 1]);
			temp[1][j] = (temp[1][j] % moder + moder) % moder;
			now ^= 1;
		}
		memcpy(temp[0], temp[1], sizeof(temp[0]));
	}
	return printf("%d\n", temp[0][0]), 0;
}