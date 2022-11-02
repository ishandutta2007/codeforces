#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

const int N = 100005;
long long f[N + N + 5], fi[N + N + 5];

long long inv(long long a) {
	return a == 1 ? 1 : (MOD - MOD / a) * inv(MOD % a) % MOD;
}

void prepare() {
	f[0] = 1;
	for (int i = 1; i <= N + N; ++i) {
		f[i] = f[i - 1] * i % MOD;
	}
	for (int i = 0; i <= N + N; ++i) {
		fi[i] = inv(f[i]);
	}
}

long long binom(const int n, const int m) {
	return f[n] * fi[m] % MOD * fi[n - m] % MOD;
}

long long dp[N][2];

long long cal(const int n, const int m, const int g) {
	if (n + m == 1) {
		if (n == 0) {
			return g == 1;
		} else {
			return g == 0;
		}
	}
	if (dp[n][g] != -1) {
		return dp[n][g];
	}
	long long ret = 0;
	if (g == 1) {
		if (n > 0) {
			ret = cal(n - 1, m, 0);
		}
	} else {
		if (n > 0) {
			ret = cal(n - 1, m, 1);
		}
		if (m > 0) {
			(ret += binom(n + m - 1, m - 1)) %= MOD;
		}
	}
	return dp[n][g] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	prepare();
	int n, m, g;
	scanf("%d%d%d", &n, &m, &g);
	cout << cal(n, m, g) << endl;
	return 0;
}