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
int fct[MAXN + 5], ifct[MAXN + 5], pw[MAXN + 5];
int comb(int n, int m) {
	return 1LL*fct[n]*ifct[m]%MOD*ifct[n-m]%MOD;
}
int f[MAXN + 5][MAXN + 5];
void init(int n) {
	fct[0] = 1;
	for(int i=1;i<=n;i++)
		fct[i] = 1LL*fct[i-1]*i%MOD;
	ifct[n] = pow_mod(fct[n], MOD - 2);
	for(int i=n-1;i>=0;i--)
		ifct[i] = 1LL*ifct[i+1]*(i+1)%MOD;
	f[0][0] = f[1][0] = 1, f[1][1] = 0;
	for(int i=2;i<=n;i++) {
		f[i][0] = fct[i], f[i][1] = (fct[i] + MOD - fct[i-1]%MOD)%MOD;
		for(int j=2;j<=i;j++) {
			f[i][j] = 1LL*(j-1)*((f[i-1][j-1] + f[i-2][j-2])%MOD)%MOD;
			f[i][j] = (f[i][j] + 1LL*(i-j)*f[i-1][j-1]%MOD)%MOD;
		}
	}
	pw[0] = 1, pw[1] = f[n][n];
	for(int i=2;i<=n;i++)
		pw[i] = 1LL*pw[i-1]*pw[1]%MOD;
}
/*
m!*(n-i)!/i!*(m-i)!
C(m, 0)*n! - C(m, 1)*(n-1)! + C(m, 2)*(n-2)!
*/
int a[MAXN + 5][MAXN + 5], n;
bool tag[MAXN + 5];
int tree[2][MAXN + 5];
int lowbit(int x) {return x & -x;}
void update(int type, int x, int d) {
	for(int i=x;i<=n;i+=lowbit(i))
		tree[type][i] += d;
}
int sum(int type, int x) {
	int ret = 0;
	for(int i=x;i;i-=lowbit(i))
		ret += tree[type][i];
	return ret;
}
int main() {
	scanf("%d", &n), init(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &a[i][j]);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) tree[0][j] = tree[1][j] = tag[j] = 0;
		int tmp = n;
		for(int j=1;j<=n;j++) {
			int p = (a[i][j] - 1) - sum(0, a[i][j] - 1);
			if( i == 1 ) {
				ans = (ans + 1LL*p*f[n-j][0]%MOD*pw[n-i]%MOD)%MOD;
				update(0, a[i][j], 1);
			}
			else {
				if( a[i-1][j] < a[i][j] && !tag[a[i-1][j]] )
					p--;
				if( !tag[a[i-1][j]])
					tag[a[i-1][j]] = true, update(1, a[i-1][j], 1), tmp--;
				int q = (a[i][j] - 1) - sum(1, a[i][j] - 1);
				if( tmp != 0 )
					ans = (ans + 1LL*q*f[n-j][tmp-1]%MOD*pw[n-i]%MOD)%MOD;
				ans = (ans + 1LL*(p-q)*f[n-j][tmp]%MOD*pw[n-i]%MOD)%MOD;
				if( !tag[a[i][j]])
					tag[a[i][j]] = true, update(1, a[i][j], 1), tmp--;
				update(0, a[i][j], 1);
			}
		}
	}
	printf("%d", ans);
}