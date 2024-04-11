#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
int f[1005][55], cap[1005], ans[1005][55], cb[1055][1055], fac[1005];

int main() {
	f[0][0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 50; ++j) {
			f[i][j] = 0;
			for (int k = 1; k * j <= i; ++k) {
				(f[i][j] += f[i - k * j][j - 1]) %= MOD;
			}
			if (f[i][j] == 0) {
				cap[i] = j;
				break;
			}
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
	}
	for (int i = 0; i <= 1050; ++i) {
		cb[i][0] = cb[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			cb[i][j] = (cb[i - 1][j] + cb[i - 1][j - 1]) % MOD;
		}
	}
	cap[0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= cap[i]; ++j) {
			ans[i][j] = 0;
			for (int l2 = j; l2 <= i; ++l2) {
				int l1 = i - l2;
				if (j > cap[l1]) {
					continue;
				}
				(ans[i][j] += (long long)(f[l1][j] + f[l1][j - 1]) * fac[j] % MOD * cb[l2 - 1][j - 1] % MOD) %= MOD;
			}
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= cap[i]; ++j) {
			(ans[i][j] += ans[i - 1][j]) %= MOD;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (k - 1 >= cap[n]) {
			printf("0\n");
		} else {
			printf("%d\n", ans[n][k]);
		}
	}
	return 0;
}