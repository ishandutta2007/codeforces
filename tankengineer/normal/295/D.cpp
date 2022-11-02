#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;
const int N = 2005;

int n, m;
long long f[N][N], g[N][N], sum[N][N], sumu[N][N], sumf[N][N], sumk[N][N];

int main() {
	scanf("%d %d", &n, &m);
	memset(f, 0, sizeof(f));
	memset(sum, 0, sizeof(sum));
	memset(sumu, 0, sizeof(sumu));
	for (int j = 1; j <= n; ++j) {
		for (int i = 2; i <= m; ++i) {
			if (j == 1) {
				f[i][j] = 1;
			} else {
				f[i][j] = (((i + 1) * sum[i][j - 1] % MOD - sumu[i][j - 1]) % MOD + MOD) % MOD;
			}
			sum[i][j] = (sum[i - 1][j] + f[i][j]) % MOD;
			sumu[i][j] = (sumu[i - 1][j] + i * f[i][j] % MOD) % MOD;
		}
	}
	memset(g, 0, sizeof(g));
	memset(sum, 0, sizeof(sum));
	memset(sumu, 0, sizeof(sumu));
	for (int j = 1; j <= n; ++j) {
		for (int i = 2; i <= m; ++i) {
			if (j == 1) {
				g[i][j] = 1;
			} else {
				g[i][j] = (((i + 1) * sum[i - 1][j - 1] % MOD - sumu[i - 1][j - 1]) % MOD + MOD) % MOD;
			}
			sum[i][j] = (sum[i - 1][j] + f[i][j]) % MOD;
			sumu[i][j] = (sumu[i - 1][j] + i * f[i][j] % MOD) % MOD;
		}
	}	
	memset(sumf, 0, sizeof(sumf));
	memset(sumk, 0, sizeof(sumk));
	for (int i = 2; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			sumf[i][j] = (sumf[i][j - 1] + f[i][j]) % MOD;
			sumk[i][j] = (sumk[i][j - 1] + j * f[i][j] % MOD) % MOD;
//cout << i << ' ' << j << ' ' << f[i][j] << endl;
//cout << i << ' ' << j << ' ' << g[i][j] << endl;
		}
	}
	long long ans = 0;
	for (int v = 2; v <= m; ++v) {
		for (int i = 1; i <= n; ++i) {
			ans += (m - v + 1) * g[v][i] % MOD * ((((n - i + 2) * sumf[v][n - i + 1] % MOD - sumk[v][n - i + 1]) % MOD + MOD) % MOD) % MOD;
			ans %= MOD;
//cout << v << ' ' << i << ' ' << g[v][i] << ' ' << ((((n - i + 2) * sumf[v][n - i + 1] % MOD - sumk[v][n - i + 1]) % MOD + MOD) % MOD) % MOD << endl;
//cout << sumf[v][n - i + 1] << ' ' << sumk[v][n - i + 1] << endl;
//cout << (m - v + 1) * g[v][i] % MOD * ((((n - i + 2) * sumf[v][n - i + 1] % MOD - sumk[v][n - i + 1]) % MOD + MOD) % MOD) % MOD << endl;
		}
	}
	cout << ans << endl;
	return 0;
}