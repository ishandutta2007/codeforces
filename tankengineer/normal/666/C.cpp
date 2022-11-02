#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100001, BAR = 500, MOD = 1000000007;

int fac[N], inv[N];

int powMod(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1) {
			ret = (long long)ret * a % MOD;
		}
		a = (long long)a * a % MOD;
		n >>= 1;
	}
	return ret;
}

int binom(int n, int m) {
	if (m > n) {
		return 0;
	}
	return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int m;

char s[N];

int ans[N];

void prepare(int l) {
	int base = 1;
	for (int i = 0; i < N; ++i) {
		ans[i] = i < l ? 0 : (long long)binom(i - 1, l - 1) * base % MOD;
		if (i >= l) {
			base = (long long)base * 25 % MOD;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (ans[i] >= MOD) {
			ans[i] -= MOD;
		}
		if (i + 1 < N) {
			ans[i + 1] += (long long)ans[i] * 26 % MOD;
		}
	}
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
	}
	inv[N - 1] = powMod(fac[N - 1], MOD - 2);
	assert((long long)inv[N - 1] * fac[N - 1] % MOD == 1);
	for (int i = N - 2; i >= 0; --i) {
		inv[i] = (long long)inv[i + 1] * (i + 1) % MOD;
	}
	scanf("%d", &m);
	scanf("%s", s);
	int l = strlen(s);
	if (l > BAR) {
		prepare(l);
	}
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%s", s);
			l = strlen(s);
			if (l > BAR) {
				prepare(l);
			}
		} else {
			int n;
			scanf("%d", &n);
			if (l > BAR) {
				printf("%d\n", ans[n]);
			} else {
				if (n < l) {
					printf("0\n");
				} else {
					int ans = powMod(26, n);
					int base = powMod(25, n - l + 1);
					for (int i = l - 1; i >= 0; --i) {
						ans -= (long long)binom(n, i) * base % MOD;
						if (ans < 0) {
							ans += MOD;
						}
						base = (long long)base * 25 % MOD;
					}
					printf("%d\n", ans);
				}
			}
		}
	}
	return 0;
}