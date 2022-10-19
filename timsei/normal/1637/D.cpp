#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = N * N * 2;

int n, m , A[N], B[N];

bitset < M > dp[N]; 

int calc(int x) {
	return x * x;
}

void rmain() {
	scanf("%d", &n);
	int S = 0;
	int that = 0;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), S += A[i], that += A[i] * A[i];
	for(int i = 1; i <= n; ++ i) scanf("%d", &B[i]), S += B[i], that += B[i] * B[i];
	that = that * (n - 2);
	int Base = n * 100;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n + 1; ++ i) dp[i] = 0;
	dp[1][Base] = 1;
	for(int i = 1; i <= n; ++ i) {
		int now = abs(A[i] - B[i]);
		dp[i + 1] |= dp[i] >> (now);
		dp[i + 1] |= dp[i] << now;
	}
	
	int res = 1e9;
	
	for(int j = 0; j < M; ++ j) {
		if(dp[n + 1][j]) {
			res = min(res, abs(j - Base));
		}
	}
	
	cout << calc((S + res) / 2) + calc((S - res) / 2) + that << endl;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}