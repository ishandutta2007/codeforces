#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int) (1LL * x * y % MOD);}
 
int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

int ifct[55];
void init() {
	ifct[0] = 1; for(int i=1;i<55;i++) ifct[i] = mul(ifct[i - 1], i);
	for(int i=0;i<55;i++) ifct[i] = pow_mod(ifct[i], MOD - 2);
}

int lf[55], rf[55];
int get(int x, int n, int *y) {
	lf[0] = 1; for(int i=1;i<=n;i++) lf[i] = mul(lf[i - 1], sub(x, i));
	rf[n + 1] = 1; for(int i=n;i>=1;i--) rf[i] = mul(rf[i + 1], sub(x, i));
	
	int ret = 0;
	for(int i=1;i<=n;i++) {
		int del = mul(mul(lf[i - 1], rf[i + 1]), mul(ifct[i - 1], ifct[n - i]));
		
		ret = (((n - i) & 1) ? sub(ret, mul(del, y[i])) : add(ret, mul(del, y[i])));
	}
	return ret;
}

int f[55][55], c[55];

int l[55], r[55], d[105], dcnt;
int main() {
	init(); int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &l[i], &r[i]), r[i]++;
		d[++dcnt] = l[i], d[++dcnt] = r[i];
	}
	sort(d + 1, d + dcnt + 1), dcnt = unique(d + 1, d + dcnt + 1) - d - 1;
	
	c[n + 1] = 1, l[n + 1] = r[n + 1] = -1;
	for(int i=1;i<dcnt;i++) {
		int deg = min(d[i + 1] - d[i], n) + 3;
		for(int j=n+1;j>=1;j--) {
			if( l[j] <= d[i] && d[i + 1] <= r[j] ) {
				f[j][0] = c[j];
				for(int k=1;k<=deg;k++)
					f[j][k] = add(f[j][k - 1], f[j + 1][k]);
				c[j] = get(d[i + 1] - d[i], deg, f[j]); 
			} else {
				for(int k=1;k<=deg;k++)
					f[j][k] = c[j];
			}
		}
	}
	
	int ans = c[1];
	for(int i=1;i<=n;i++)
		ans = mul(ans, pow_mod(r[i] - l[i], MOD - 2));
	printf("%d\n", ans);
}