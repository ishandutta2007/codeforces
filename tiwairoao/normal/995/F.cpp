#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 3000;
const int MOD = int(1E9) + 7;

inline int add(int x, int y) {x += y; return (x >= MOD ? x - MOD : x);}
inline int sub(int x, int y) {x -= y; return (x < 0 ? x + MOD : x);}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

int ifct[MAXN + 5];
void init() {
	ifct[0] = 1; for(int i=1;i<=MAXN;i++) ifct[i] = mul(ifct[i - 1], i);
	for(int i=0;i<=MAXN;i++) ifct[i] = pow_mod(ifct[i], MOD - 2);
}

int lf[MAXN + 5], rf[MAXN + 5];
int get_y(int n, int *y, int x) {
	lf[0] = 1; for(int i=1;i<=n;i++) lf[i] = mul(lf[i - 1], sub(x, i));
	rf[n + 1] = 1; for(int i=n;i>=1;i--) rf[i] = mul(rf[i + 1], sub(x, i));
	
	int ans = 0;
	for(int i=1;i<=n;i++) {
		int del = mul(mul(lf[i - 1], rf[i + 1]), mul(ifct[i - 1], ifct[n - i]));
		
		ans = ((n - i) & 1) ? sub(ans, mul(del, y[i])) : add(ans, mul(del, y[i]));
	}
	return ans;
}

int dp[MAXN + 5][MAXN + 5];

int p[MAXN + 5], n, D;
int main() {
	init(), scanf("%d%d", &n, &D);
	for(int i=2;i<=n;i++) scanf("%d", &p[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			dp[i][j] = 1;
	for(int i=n;i>=1;i--) {
		for(int j=1;j<=n+1;j++) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
		for(int j=1;j<=n+1;j++) dp[p[i]][j] = mul(dp[p[i]][j], dp[i][j]);
	}
	printf("%d\n", get_y(n + 1, dp[1], D));
}