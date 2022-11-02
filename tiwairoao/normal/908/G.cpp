#include <bits/stdc++.h>

typedef long long ll;

const int N = 705;
const int P = int(1E9) + 7;
const int IV9 = (P + 1) / 9;

int pw[105][N + 5];
void init() {
	for(int i=0;i<=100;i++) {
		pw[i][0] = 1;
		for(int j=1;j<=N;j++) pw[i][j] = (ll)pw[i][j - 1] * i % P;
	}
}

int cnt[10];

int a[N + 5], n;
int solve() {
	int ret1 = 0, ret2 = 0;
	for(int m = n; m; m--) {
		
		int s = 0;
		for(int i=9;i>=0;i--) {
			int d1 = (i <= a[m - 1] - 1) ? (a[m - 1] - i) : 0;
			int d2 = a[m - 1] - d1;
			
			s += cnt[i];
			ret1 += (ll)i * pw[10][s] % P * pw[100 - 9 * i][m - 1] % P * d2 % P;
			if( ret1 >= P ) ret1 -= P;
			ret1 += (ll)i * pw[10][s + 1] % P * pw[100 - 9 * i][m - 1] % P * d1 % P;
			if( ret1 >= P ) ret1 -= P;
		}
		
		s = 0;
		for(int i=9;i>=0;i--) {
			int d1 = (i < a[m - 1] - 1) ? (a[m - 1] - i - 1) : 0;
			int d2 = a[m - 1] - d1;
			
			ret2 += (ll)i * pw[10][s] % P * pw[91 - 9 * i][m - 1] % P * d2 % P;
			if( ret2 >= P ) ret2 -= P;
			ret2 += (ll)i * pw[10][s + 1] % P * pw[91 - 9 * i][m - 1] % P * d1 % P;
			if( ret2 >= P ) ret2 -= P;
			s += cnt[i];
		}
	
		cnt[a[m - 1]]++;
	}
	return (ll)(ret1 - ret2 + P) * IV9 % P;
}

int calc() {
	std::sort(a, a + n);
	
	int ret = 0;
	for(int i=0;i<n;i++) ret = ((ll)10 * ret + a[i]) % P;
	return ret;
}

char str[N + 5];
int main() {
	init();
	scanf("%s", str), n = strlen(str);
	for(int i=0;i<n;i++) a[i] = str[n - i - 1] - '0';
	int ans = solve() + calc(); if( ans >= P ) ans -= P;
	printf("%d\n", ans);
}