//#define INTERACTOR_MODE
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
const int MAXN = 2e5;
int pr[MAXN / 4 + 5], prcnt = 0, vis[MAXN + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; if (i % pr[j] == 0) break;
		}
	}
}
ll gcd(ll x, ll y) {return (!y) ? x : gcd(y, x % y);}
ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}
#ifdef INTERACTOR_MODE
namespace interactor {
	int p[MAXN + 5];
	void gen(int n) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
		} else {
			int L; scanf("%d", &L);
			for (int i = 1; i <= n; i++) p[i] = L + i - 1;
			random_shuffle(p + 1, p + n + 1);
			for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
		}
	}
	ll query(int x, int y) {return :: lcm(p[x], p[y]);}
}
#endif
int n, seq[MAXN + 5], res[MAXN + 5];
ll query(int x, int y) {
#ifndef INTERACTOR_MODE
	printf("? %d %d\n", x, y); fflush(stdout);
	ll v; scanf("%lld", &v); return v;
#else
	printf("query(%d, %d)\n", x, y);
	return interactor :: query(x, y);
#endif
}
void solve() {
	scanf("%d", &n);
#ifdef INTERACTOR_MODE
	interactor :: gen(n);
#endif
	if (n == 3) {
		ll mx = max(query(1, 2), max(query(1, 3), query(2, 3)));
		ll X = (1 + (sqrt(mx * 4 + 1) + 0.05)) / 2;
//		printf("%d\n", X);
		static int perm[5]; for (int i = 1; i <= 3; i++) perm[i] = i;
		do {
			bool flg = 1;
			for (int i = 1; i <= 3; i++) for (int j = i + 1; j <= 3; j++)
				flg &= (query(i, j) == lcm(X + 1 - perm[i], X + 1 - perm[j]));
			if (flg) {
				printf("!");
				for (int i = 1; i <= 3; i++) printf(" %d", X + 1 - perm[i]);
				printf("\n"); fflush(stdout); return;
			}
		} while (next_permutation(perm + 1, perm + 4));
		return;
	}
	else if (n <= 100) {
		static ll val[111][111];
		for (int i = 1; i <= n; i++) for (int j = 1; j < i; j++)
			val[i][j] = val[j][i] = query(i, j);
		for (int i = 1; i <= n; i++) {
			ll D = 0;
			for (int j = 1; j <= n; j++) if (i != j) D = gcd(D, val[i][j]);
			res[i] = D;
		}
		printf("!"); for (int i = 1; i <= n; i++) printf(" %d", res[i]);
		printf("\n"); fflush(stdout);
		return;
	}
	for (int i = 2; i <= n; i++) seq[i] = i;
	random_shuffle(seq + 2, seq + n + 1);
	ll a1 = 0;
	for (int i = 2; i <= min(n, 500); i++) a1 = gcd(a1, query(1, seq[i]));
	random_shuffle(seq + 2, seq + n + 1);
	int mx = (!vis[a1]) ? a1 : 0, pos = (!vis[a1]) ? 1 : 0;
	for (int i = 2; i <= min(n, 0x1064); i++) {
		int v = query(1, seq[i]) / a1;
		if (!vis[v]) {
			if (mx < v) mx = v, pos = seq[i];
		}
	}
	res[pos] = mx;
	for (int i = 1; i <= n; i++) if (i != pos) res[i] = query(i, pos) / mx;
	printf("!"); for (int i = 1; i <= n; i++) printf(" %d", res[i]);
	printf("\n"); fflush(stdout); 
}
int main() {
	srand(time(0)); sieve(MAXN); int qu;
	scanf("%d", &qu); while (qu--) solve(); return 0;
}