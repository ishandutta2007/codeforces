#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 1e7;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int pw2[MAXN + 5];
int main() {
	for (int i = (pw2[0] = 1); i <= MAXN; i++) pw2[i] = (pw2[i - 1] << 1) % MOD;
	int qu; scanf("%d", &qu);
	while (qu--) {
		int n, k, x; scanf("%d%d%d", &n, &k, &x);
		if (!x) {
			if (n > k) puts("0");
			else {
				int mul = 1, pw = qpow(2, k);
				for (int i = 0; i < n; i++) mul = 1ll * mul * (pw - pw2[i] + MOD) % MOD;
				printf("%d\n", mul);
			}
		} else {
			int pw = qpow(2, n), mul = 1, res = 0;
			static int prd[MAXN + 5];
			prd[k] = 1;
			for (int i = k - 1; i; i--) prd[i] = 1ll * prd[i + 1] * (pw2[i] - 1) % MOD;
			for (int i = 0; i < k; i++) {
				int coef = 1ll * pw2[i] * prd[i + 1] % MOD * mul % MOD;
				mul = 1ll * mul * pw % MOD;
				if ((k - i - 1) & 1) res = (res - coef + MOD) % MOD;
				else res = (res + coef) % MOD;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}