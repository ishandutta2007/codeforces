#include<cstdio>
const int MAXN = 3600;
const int MOD = 998244353;
int c[MAXN + 5][MAXN + 5], fct[MAXN + 5];
int a[MAXN + 5], b[MAXN + 5];
int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];
int h, w, n;
void init() {
	for(int i=0;i<=MAXN;i++) {
		c[i][0] = 1;
		for(int j=1;j<=i;j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
	}
	fct[0] = 1;
	for(int i=1;i<=MAXN;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
}
int main() {
	init(); scanf("%d%d%d", &h, &w, &n);
	for(int i=1;i<=n;i++) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		a[r1] = a[r2] = 1, b[c1] = b[c2] = 1;
	}
	a[0] = b[0] = 1;
	int cnth = 0, cntw = 0;
	for(int i=1;i<=h;i++) cnth += (1 - a[i]);
	for(int i=1;i<=w;i++) cntw += (1 - b[i]);
	f[0][0] = 1;
	for(int i=1;i<=h;i++) {
		for(int j=w;j>=0;j--) {
			f[i][j] = f[i-1][j];
			if( !a[i] && !a[i-1] && j )
				f[i][j] = (f[i][j] + f[i-2][j-1])%MOD;
		}
	}
	g[0][0] = 1;
	for(int j=1;j<=w;j++) {
		for(int i=h;i>=0;i--) {
			g[i][j] = g[i][j-1];
			if( !b[j] && !b[j-1] && i )
				g[i][j] = (g[i][j] + g[i-1][j-2])%MOD;
		}
	}
	int ans = 0;
	for(int i=0;i<=cnth;i++) //  
		for(int j=0;j<=cntw;j++) { //  
			if( 2*j + i > cnth || 2*i + j > cntw ) continue;
			int del = 1LL*fct[i]*fct[j]%MOD;
			int tmp1 = 1LL*f[h][j]*c[cnth-2*j][i]%MOD;
			int tmp2 = 1LL*g[i][w]*c[cntw-2*i][j]%MOD;
			del = 1LL*del*tmp1%MOD*tmp2%MOD;
			ans = (ans + del)%MOD;
		}
	printf("%d\n", ans);
}