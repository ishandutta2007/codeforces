#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 505, MOD = 1000000007;

int f[2][N][N];

int pow[N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	pow[0] = 1;
	for (int i = 1; i <= 500; ++i) {
		pow[i] = pow[i - 1] * 2 % MOD;
	}
	int now = 1;
	f[1][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int next = now ^ 1;
		for (int j = 0; j < i && j <= k; ++j) {
			for (int k = 0; k < i; ++k) {
				(f[next][j + 1][i] += (long long)(pow[i - k] - 1) * pow[k] % MOD * f[now][j][k] % MOD) %= MOD;
				(f[next][j][k] += (long long)pow[k] * f[now][j][k] % MOD) %= MOD;
				f[now][j][k] = 0;
			}
		}
		now = next;
	}
	int ans = 0;
	for (int last = 0; last <= n; ++last) {
		(ans += f[now][k][last]) %= MOD;	
	}
	printf("%d\n", ans);
	return 0;
}