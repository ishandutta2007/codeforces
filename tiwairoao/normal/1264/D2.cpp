#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
const int MAXN = 1000000;

inline int add(int x, int y) {x += y; return x >= MOD ? x - MOD : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + MOD : x;}
inline int mul(int x, int y) {return (int)(1LL * x * y % MOD);}
int mpow(int b, int p) {
	int ret; for(ret=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) ret = mul(ret, b);
	return ret;
}

int fct[MAXN + 5], ifct[MAXN + 5];
int comb(int n, int m) {
	if( n < m || m < 0 ) return 0;
	else return mul(fct[n], mul(ifct[m], ifct[n - m]));
}
void init() {
	fct[0] = 1; for(int i=1;i<=MAXN;i++) fct[i] = mul(fct[i - 1], i);
	ifct[MAXN] = mpow(fct[MAXN], MOD - 2);
	for(int i=MAXN-1;i>=0;i--) ifct[i] = mul(ifct[i + 1], i + 1);
}

char str[MAXN + 5]; int f[MAXN + 5], g[MAXN + 5];

int a[MAXN + 5], b[MAXN + 5], s[MAXN + 5], t[MAXN + 5], n;
int main() {
	init(), scanf("%s", str + 1), n = strlen(str + 1);
	for(int i=1;i<=n;i++)
		a[i] = a[i - 1] + (str[i] == '('), s[i] = s[i - 1] + (str[i] == '?');
	for(int i=n;i>=1;i--)
		b[i] = b[i + 1] + (str[i] == ')'), t[i] = t[i + 1] + (str[i] == '?');
	
	for(int i=1;i<=n;i++) {
		if( b[i + 1] + t[i + 1] - a[i - 1] - 1 < 0 ) break;
		if( str[i] == ')' ) continue;
		if( s[i - 1] + t[i + 1] == s[n] ) f[b[i + 1] + t[i + 1] - a[i - 1] - 1]++;
		else g[b[i + 1] + t[i + 1] - a[i - 1] - 1]++;
	}
	
	int ans = 0;
	for(int i=0,sum=1;i<=n;i++,sum=add(sum,comb(s[n],i)))
		ans = add(ans, mul(f[i], sum));
	for(int i=0,sum=1;i<=n;i++,sum=add(sum,comb(s[n]-1,i)))
		ans = add(ans, mul(g[i], sum));
	printf("%d\n", ans);
}