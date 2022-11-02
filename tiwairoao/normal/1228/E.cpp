#include<cstdio>
const int MAXN = 250;
const int MOD = int(1E9) + 7;
int f[MAXN + 5][MAXN + 5];
int c[MAXN + 5][MAXN + 5];
int pw1[MAXN + 5], pw2[MAXN + 5], n, k;
void init() {
	pw1[0] = pw2[0] = 1;
	for(int i=1;i<=n;i++)
		pw1[i] = 1LL*pw1[i-1]*k%MOD, pw2[i] = 1LL*pw2[i-1]*(k-1)%MOD;
	for(int i=0;i<=n;i++) {
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
	}
}
int main() {
	scanf("%d%d", &n, &k), init();
	for(int j=1;j<=n;j++)
		f[1][j] = 1LL*c[n][j]*pw2[n-j]%MOD;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=0;j+k<=n;k++) {
				f[i][j+k] = (f[i][j+k] + 1LL*c[n-j][k]*pw1[j]%MOD*pw2[n-j-k]%MOD*f[i-1][j]%MOD)%MOD;
				if( k == 0 ) {
					f[i][j+k] = (f[i][j+k] + MOD - 1LL*pw2[n]*f[i-1][j]%MOD)%MOD;
				}
			}
		}
	}
	printf("%d\n", f[n][n]);
}