#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
int n, m, mod, dp1[MAXN + 5], dp2[MAXN + 5], c[MAXN + 5][MAXN + 5], dp3[MAXN + 5][MAXN + 5], dp4[MAXN + 5][MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	dp1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp1[i] = (dp1[i] + 1ll * dp1[j - 1] * dp1[i - j] % mod * c[i - 1][j - 1] % mod * (i + 1)) % mod;
			dp2[i] = (dp2[i] + 1ll * (1ll * dp1[j - 1] * dp1[i - j] % mod * (c[j][2] + c[i - j + 1][2]) % mod + 1ll * dp2[j - 1] * dp1[i - j] % mod * (i + 1) % mod
			+ 1ll * dp1[j - 1] * dp2[i - j] % mod * (i + 1) % mod) % mod * c[i - 1][j - 1]) % mod;
		}
	}
	for (int i = 0; i <= n; i++) {
		dp3[i][0] = 1; dp3[i][i] = dp1[i]; dp4[i][i] = dp2[i];
		for (int j = 1; j < i; j++) for (int l = 0; l <= min(j, i - 1); l++) {
			dp3[i][j] = (dp3[i][j] + 1ll * c[j][l] * dp3[i - l - 1][j - l] % mod * dp1[l]) % mod;
			dp4[i][j] = (dp4[i][j] + 1ll * (1ll * dp3[i - l - 1][j - l] * dp2[l] + 1ll * dp4[i - l - 1][j - l] * dp1[l]) % mod * c[j][l]) % mod;
		}
	}
	printf("%d\n", dp4[n][m]);
}