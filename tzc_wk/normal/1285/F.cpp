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
int pr[MAXN / 4 + 5], prcnt = 0, mu[MAXN + 5];
bool vis[MAXN + 5];
vector<int> fac[MAXN + 5];
void sieve(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mu[i] = -1;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; if (i % pr[j] == 0) break;
			mu[i * pr[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= n; i++) for (int j = i; j <= MAXN; j += i)
		fac[j].pb(i);
}
int n, cnt[MAXN + 5], buc[MAXN + 5]; ll res = 1;
void ins(int x) {for (int y : fac[x]) buc[y]++;}
void del(int x) {for (int y : fac[x]) buc[y]--;}
int main() {
	scanf("%d", &n); sieve(MAXN);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), cnt[x] = 1;
	for (int i = MAXN; i; i--) for (int j = i; j <= MAXN; j += i) cnt[i] |= cnt[j];
	static int stk[MAXN + 5], tp = 0;
	for (int i = MAXN; i; i--) if (cnt[i]) {
		int sum = 0;
		for (int j : fac[i]) sum += mu[j] * buc[j];
		if (sum) {
			while (sum) {
				if (__gcd(i, stk[tp]) == 1) chkmax(res, 1ll * stk[tp] * i);
				del(stk[tp]), --tp; sum = 0;
				for (int j : fac[i]) sum += mu[j] * buc[j];
			}
		}
		stk[++tp] = i; ins(i);
	}
	printf("%lld\n", res);
	return 0;
}
/*
6
16 32 40 54 60 72
*/