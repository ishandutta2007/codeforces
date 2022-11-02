#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int fun(int l, int r) {
	if( l > r ) return 0;
	else return 1LL*(l + r)*(r - l + 1)/2%MOD;
}

int f[2][3500][3500], g[2][3500][3500], b[3500], p, a, n;
void solve() {
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<i;j++) {
			f[0][i][j] = add(f[0][i][j], mul(f[0][i - 1][j], fun(1, p)));
			f[0][i][j] = add(f[0][i][j], mul(f[1][i - 1][j], fun(1, p - 1)));
			f[1][i][j + 1] = add(f[1][i][j + 1], mul(f[0][i - 1][j], fun(1, p - 1)));
			f[1][i][j + 1] = add(f[1][i][j + 1], mul(f[1][i - 1][j], fun(1, p)));
		}
	}
	for(int i=0;i<=n;i++)
		for(int j=i-1;j>=0;j--) {
			f[0][i][j] = add(f[0][i][j], f[0][i][j + 1]);
			f[1][i][j] = add(f[1][i][j], f[1][i][j + 1]);
		}
	
	g[0][n + 1][0] = 1; int ans = 0;
	for(int i=n;i>=1;i--) {
		for(int j=0;j<=n-i;j++) {
			if( a - j <= i - 1 ) {
				ans = add(ans, mul(mul(g[0][i + 1][j], f[0][i - 1][max(a - j, 0)]), fun(1, b[i])));
				ans = add(ans, mul(mul(g[0][i + 1][j], f[1][i - 1][max(a - j, 0)]), fun(1, b[i] - 1)));
			}
			if( a - j <= i - 1 ) {
				ans = add(ans, mul(mul(g[1][i + 1][j], f[0][i - 1][max(a - j, 0)]), fun(p - b[i], p - 1)));
				ans = add(ans, mul(mul(g[1][i + 1][j], f[1][i - 1][max(a - j, 0)]), fun(p - b[i] + 1, p)));
			}
			
			g[0][i][j] = add(g[0][i][j], mul(g[0][i + 1][j], b[i] + 1));
			g[0][i][j] = add(g[0][i][j], mul(g[1][i + 1][j], p - b[i] - 1));
			g[1][i][j + 1] = add(g[1][i][j + 1], mul(g[0][i + 1][j], b[i]));
			g[1][i][j + 1] = add(g[1][i][j + 1], mul(g[1][i + 1][j], p - b[i]));
		}
	}
	printf("%d\n", ans);
}

int A[1005], len;
int rem() {
	int r = 0;
	for(int i=len;i>=1;i--) {
		int t = (10LL*r + A[i]) / p;
		r = (10LL*r + A[i]) % p;
		A[i] = t;
	}
	while( len > 1 && A[len] == 0 ) len--;
	return r;
}
char S[1005];
int main() {
	scanf("%d%d%s", &p, &a, S), len = strlen(S);
	for(int i=0;i<len;i++)
		A[len - i] = S[i] - '0';
	
	while( len != 1 || A[1] != 0 )
		b[++n] = rem();
	
	b[1]++;
	for(int i=1;i<=n;i++)
		b[i + 1] += b[i] / p, b[i] %= p;
	if( b[n + 1] ) n++;
	
	solve();
}