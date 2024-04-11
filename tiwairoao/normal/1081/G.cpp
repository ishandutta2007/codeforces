#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

int q;
inline int add(int x, int y) {x += y; return x >= q ? x - q : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + q : x;}
inline int mul(int x, int y) {return (int)(1LL * x * y % q);}
int mpow(int b, int p) {
	int ret; for(ret=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) ret = mul(ret, b);
	return ret;
}

int a[MAXN + 5];
void get(int l, int r, int h) {
	if( l == r || h == 1 ) a[r - l + 1]++;
	else {
		int m = (l + r) >> 1;
		get(l, m, h - 1), get(m + 1, r, h - 1);
	}
}

int inv[MAXN + 5], fct[MAXN + 5], ifct[MAXN + 5];
int comb(int n, int m) {
	if( n < m || m < 0 ) return 0;
	else return mul(fct[n], mul(ifct[m], ifct[n-m]));
}
int si[MAXN + 5];
void init() {
	inv[1] = 1; for(int i=2;i<=MAXN;i++) inv[i] = sub(0, mul(q / i, inv[q % i]));
	fct[0] = 1; for(int i=1;i<=MAXN;i++) fct[i] = mul(fct[i - 1], i);
	ifct[MAXN] = mpow(fct[MAXN], q - 2);
	for(int i=MAXN-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
	for(int i=1;i<=MAXN;i++) si[i] = add(si[i - 1], inv[i]);
}

int b[MAXN + 5], cnt;

int main() {
	int n, k; scanf("%d%d%d", &n, &k, &q), get(1, n, k), init();
	
	for(int i=1;i<=n;i++)
		if( a[i] ) b[++cnt] = i;
	
	int ans = 0;
	for(int i=1;i<=cnt;i++)
		ans = add(ans, mul(mul(mul(mul(b[i], b[i] - 1), inv[2]), inv[2]), a[b[i]]));
	
	for(int o1=1;o1<=cnt;o1++)
		for(int o2=1;o2<=cnt;o2++) {
			int coef = mul(a[b[o1]], o1 == o2 ? a[b[o2]] - 1 : a[b[o2]]), del = 0;
			if( coef == 0 ) continue;
			for(int i=1;i<=b[o1];i++) {
				int k = add(mul(inv[2], i - 1), 1), c = mul(inv[i + 1], b[o2]), d = sub(si[i + b[o2]], si[i]);
//				for(int j=1;j<=b[o2];j++) d = add(d, inv[i + j]);
				del = add(del, mul(k, sub(c, d)));
			}
			ans = add(ans, mul(del, coef));
		}
	
	printf("%d\n", ans);
}