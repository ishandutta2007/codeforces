#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 1e5;
const int MOD = 1e9 + 7;
int n, m, x, dp[50000000];
int& getpos(int i, int j, int k) {return dp[i * (n + 1) * (n + 1) + j * (n + 1) + k];}
void add(int &x, int y) {(x += y) >= MOD && (x -= MOD);}
int main() {
	scanf("%d%d%d", &n, &m, &x); if (n > m) return puts("0"), 0;
	getpos(0, 0, 0) = 1;
	for (int i = 0; i < m; i++) for (int j = 0; j <= min(i, n); j++)
		for (int k = 0; k <= min(j, n); k++) if (getpos(i, j, k)) {
			if (i + 1 != x) add(getpos(i + 1, j, k), getpos(i, j, k));
			if (j + 1 <= n) add(getpos(i + 1, j + 1, k), getpos(i, j, k));
			if (i + 1 != x && k + 1 <= n && j != k)
				add(getpos(i + 1, j, k + 1), getpos(i, j, k));
			if (j + 1 <= n && k + 1 <= n) add(getpos(i + 1, j + 1, k + 1), getpos(i, j, k));
		}
	int res = getpos(m, n, n);
	for (int i = 1; i <= n; i++) res = 1ll * res * i % MOD;
	printf("%d\n", res);
	return 0;
}