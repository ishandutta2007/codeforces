#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN = 4000;
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
int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];
int main() {
	int n, k, l;
	scanf("%d%d%d", &n, &k, &l);
	l = 1LL*l*pow_mod(2*n + 1, MOD-2)%MOD;
	g[0][0] = 1;
	for(int i=1;i<=2*n;i++) {
		for(int j=0;j<i;j++)
			g[i][j+1] = (g[i][j+1] + g[i-1][j])%MOD;
		for(int j=1;j<=i;j++)
			g[i][j-1] = (g[i][j-1] + 1LL*j*g[i-1][j]%MOD)%MOD;
	}
	for(int i=1;i<=2*n;i++) {
		for(int j=1;j<=i;j++)
			f[i][j-1] = 1LL*j*((f[i-1][j] + 1LL*(j >= k)*g[i-1][j]%MOD)%MOD)%MOD;
		for(int j=0;j<i;j++)
			f[i][j+1] = ((f[i][j+1] + f[i-1][j])%MOD + 1LL*(j >= k)*g[i-1][j]%MOD)%MOD;
	}
	cout << 1LL*f[2*n][0]*l%MOD*pow_mod(g[2*n][0], MOD-2)%MOD << endl;
}