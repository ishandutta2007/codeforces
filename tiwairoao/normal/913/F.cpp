#include<cstdio>
const int MAXN = 2000;
const int MOD = 998244353;
int pow_mod(int b, int p) {
	int ret = 1;
	while( p ) {
		if( p & 1 ) ret = 1LL*ret*b%MOD;
		b = 1LL*b*b%MOD;
		p >>= 1;
	}
	return ret;
}
int n, a, b, p1[MAXN + 5], p2[MAXN + 5];
int f[MAXN + 5][MAXN + 5], g[MAXN + 5];
int dp[MAXN + 5], h[MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &a, &b);
	p1[0] = 1, p1[1] = 1LL*a*pow_mod(b, MOD-2)%MOD;
	p2[0] = 1, p2[1] = (MOD + 1 - p1[1])%MOD;
	for(int i=2;i<=n;i++)
		p1[i] = 1LL*p1[i-1]*p1[1]%MOD, p2[i] = 1LL*p2[i-1]*p2[1]%MOD;
	f[1][1] = 1;
	for(int i=2;i<=n;i++) {
		f[i][1] = (1LL*f[i-1][1]*p1[1]%MOD + p2[i-1])%MOD;
		for(int j=2;j<=i;j++)
			f[i][j] = (1LL*f[i-1][j]*p1[j]%MOD + 1LL*f[i-1][j-1]*p2[i-j]%MOD)%MOD;
	}
	for(int i=1;i<=n;i++) {
		g[i] = 1;
		for(int j=1;j<i;j++)
			g[i] = (g[i] + MOD - 1LL*g[j]*f[i][j]%MOD)%MOD;
	}
	h[1] = dp[1] = 0;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<i;j++)
			h[i] = (h[i] + 1LL*g[j]*f[i][j]%MOD*(dp[j] + h[i-j])%MOD)%MOD;
		dp[i] = 1LL*(h[i] + 1LL*i*(i-1)/2%MOD)*pow_mod((1 + MOD - g[i])%MOD, MOD-2)%MOD;
		h[i] = (h[i] + 1LL*g[i]*dp[i]%MOD)%MOD;
	}
	printf("%d\n", dp[n]);
}