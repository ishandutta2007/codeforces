#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n, l, r, z;

int add(int x) {
	return (x >= mod) ? x - mod : x;
}

void Add(int &x, int y) {
	x = add(x + y);
}

int sub(int x) {
	return (x < 0) ? x + mod : x;
}

int dp[65][N], C[N][N];

int solve(int r) {
	if(r < 0) return 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	
	for(int i = 0; i < 64; ++ i) {
		long long a = ((z >> i) & 1), b = r / (1ull << i);
		for(int j = 0; j <= 1000; ++ j) if(dp[i][j]) {
			if(j + a > b) continue;
			for(int k = a; k <= n; k += 2) if(j + k <= b) {
				int nxt = (j + k + 1 - ((r >> i) & 1)) / 2;
				Add(dp[i + 1][nxt], 1LL * dp[i][j] * C[n][k] % mod);
			}
		}
	}
	
	int ans = dp[64][0];
	
	return ans;
}

void rmain() {
	scanf("%lld%lld%lld%lld", &n, &l, &r, &z);
	cout << sub(solve(r) - solve(l - 1)) << endl;
}

void prework(int n) {
	C[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		C[i][0] = 1;
		for(int j = 1; j <= n; ++ j)  
		C[i][j] = add(C[i - 1][j - 1] + C[i - 1][j]);
	}
}

main() {
	prework(N - 1);
	int t;
	for(t = 1; t --;) {
		rmain();
	}
}