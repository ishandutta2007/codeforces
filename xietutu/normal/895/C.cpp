#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int MOD = 1e9+7, S = 1 << 19;
bool prime[71];
int n, m, now, p[maxn], g[maxn][2], value[71], id[71], cnt[71], f[2][1 << 19];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= 70; ++i) {
		prime[i] = true;
		for (int j = 2; j < i; ++j)
			if (i % j == 0) prime[i] = false;
		if (prime[i]) value[id[i] = m++] = i;
	}
	p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
		p[i] = p[i - 1] * 2 % MOD;
	}
	
	f[0][0] = 1;
	for (int i = 1; i <= 70; ++i) {
		if (!cnt[i]) continue;
		now ^= 1;
		int tmp = 0, x = i;
		for (int k = 0; k < m; ++k) {
			while (x % value[k] == 0) x /= value[k], tmp ^= (1 << k);	
		}
		for (int j = 0; j < (1 << 19); ++j) f[now][j] = 0;
		
		for (int j = 0; j < (1 << 19); ++j) {
			f[now][j ^ tmp] = (f[now][j ^ tmp] + 1LL * f[now ^ 1][j] * p[cnt[i] - 1] % MOD) % MOD;
			f[now][j] = (f[now][j] + 1LL * f[now ^ 1][j] * p[cnt[i] - 1] % MOD) % MOD; 	
		}
	}
	printf("%d\n", (f[now][0] + MOD - 1) % MOD);
}