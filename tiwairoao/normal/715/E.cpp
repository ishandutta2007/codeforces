#include <cstdio>
const int MAXN = 250;
const int MOD = 998244353;
int f[MAXN + 5], g[MAXN + 5], c[4];
void solve() {
	int p = 0; f[0] = 1;
	for(int i=1;i<=c[0];i++) f[0] = 1LL*f[0]*i%MOD;
	for(int i=1;i<=c[3];i++) {
		for(int j=0;j<=p;j++) g[j] = f[j], f[j] = 0;
		p++;
		for(int j=1;j<=p;j++) f[j] = (1LL*g[j]*(i-1)%MOD + g[j-1]) % MOD;
	}
	for(int i=1;i<=c[2];i++) {
		for(int j=0;j<=p;j++) g[j] = f[j], f[j] = 0;
		p++;
		for(int j=1;j<=p;j++) f[j] = (1LL*g[j]*(c[3]+i-1)%MOD + g[j-1]) % MOD;
	}
	for(int i=1;i<=c[1];i++) {
		for(int j=0;j<=p;j++) g[j] = f[j], f[j] = 0;
		p++;
		for(int j=1;j<=p;j++) f[j] = (1LL*g[j]*(c[3]+i-1)%MOD + g[j-1]) % MOD;
	}
}
int a[MAXN + 5], b[MAXN + 5], n;
int u[MAXN + 5], d[MAXN + 5], p[MAXN + 5];
bool vis[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), u[a[i]] = i;
	for(int i=1;i<=n;i++) scanf("%d", &b[i]), d[b[i]] = i;
	for(int i=1;i<=n;i++)
		if( u[i] ) p[i] = b[u[i]];
	for(int i=1;i<=n;i++)
		if( !d[i] || !a[d[i]] ) {
			int x = i;
			while( p[x] )
				vis[x] = true, x = p[x];
			vis[x] = true;
			if( !d[i] ) {
				if( !u[x] ) c[0]++;
				else c[1]++;
			}
			else {
				if( !u[x] ) c[2]++;
				else c[3]++;
			}
		}
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		if( vis[i] ) continue;
		int x = i;
		do {
			vis[x] = true;
			x = p[x];
		}while( x != i );
		cnt++;
	}
	for(int i=1;i<=n;i++)
		if( !a[i] && !b[i] ) c[3]++;
	solve();
	for(int i=n;i>=cnt&&i>=1;i--)
		printf("%d ", f[i-cnt]);	
	for(int i=cnt-1;i>=1;i--) printf("%d ", 0);
}