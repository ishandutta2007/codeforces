#include<stdio.h>
const int MOD = 1000000007;
long long pow(int x, int p) {
	if (p == 0) return 1;
	long long d = pow(x, p / 2);
	long long re = d * d % MOD;
	if (p % 2 == 0) return re;
	else return re*x%MOD;
}
long long rev(long long x) { return pow(x, MOD - 2); }
long long d[1010][1010]; // i a after j ab
int main() {
	int n;
	long long a, b, pa, pb, eb;
	scanf("%d%lld%lld", &n, &a, &b);
	pa = a * rev(a + b) % MOD;
	pb = b * rev(a + b) % MOD;
	eb = rev(pb);
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) d[i][j] = (i + a * rev(b) % MOD) % MOD;
		for (int j = i + 1; j <= n; j++) {
			d[i][j] = pa * d[i + 1][j] % MOD;
			d[i][j] = (d[i][j] + pb * (d[i][j - i] + i)) % MOD;
		}
	}
	printf("%lld\n", d[1][n]);
	return 0;
}