// Created time: 2022/6/7 18:42:08
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 1e5;
const int MAXV = 1e6;
int n, a[MAXN + 5];
int pr[MAXV / 5 + 5], prcnt = 0, vis[MAXV + 5], mnp[MAXV + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mnp[i] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; mnp[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
}
vector<pii> calc(int v) { // ( 
	vector<pii> res;
	while (v ^ 1) {
		int p = mnp[v], cnt = 0;
		while (v % p == 0) v /= p, cnt++;
		res.pb(mp(p, cnt));
	}
	return res;
}
bool in[MAXN + 5];
vector<int> occ[MAXV + 5];
pii c[MAXV + 5];
void calc_c() {
	for (int i = 1; i <= n; i++) {
		vector<pii> vec = calc(a[i]);
//		for (pii p : vec) printf("(%d, %d) ", p.fi, p.se);
//		printf("\n");
		for (pii p : vec) occ[p.fi].pb(p.se);
	}
	for (int i = 2; i <= MAXV; i++) if (!vis[i]) {
		if (occ[i].size() <= n - 2) c[i] = mp(0, 0);
		else if (occ[i].size() == n - 1) {
			c[i].se = 0; c[i].fi = 1e9;
			for (int x : occ[i]) chkmin(c[i].fi, x);
		} else {
			c[i].fi = c[i].se = 1e9;
			for (int x : occ[i]) {
				if (x < c[i].fi) c[i].se = c[i].fi, c[i].fi = x;
				else if (x < c[i].se) c[i].se = x;
			}
		}
	}
}
int getcnt(int v, int p) {
	int cnt = 0;
	while (v % p == 0) v /= p, cnt++;
	return cnt;
}
void work(int x, int y) {
	vector<pii> v1 = calc(a[x]), v2 = calc(a[y]);
	in[x] = in[y] = 1;
	for (pii p : v1) {
		if (a[y] % p.fi == 0) {
			vector<pii> vec;
			for (int i = 1; i <= n; i++)
				vec.pb(mp(getcnt(a[i], p.fi), i));
			sort(vec.begin(), vec.end());
			in[vec[0].se] = in[vec[1].se] = 1;
		}
	}
	if (n > 2) {
		for (pii p : v1) {
			if (a[y] % p.fi) {
				vector<pii> vec;
				for (int i = 1; i <= n; i++) if (i != x && i != y)
					vec.pb(mp(getcnt(a[i], p.fi), i));
				sort(vec.begin(), vec.end()); in[vec[0].se] = 1;
			}
		}
		for (pii p : v2) {
			if (a[x] % p.fi) {
				vector<pii> vec;
				for (int i = 1; i <= n; i++) if (i != x && i != y)
					vec.pb(mp(getcnt(a[i], p.fi), i));
				sort(vec.begin(), vec.end()); in[vec[0].se] = 1;
			}
		}
	}
}
void gen_smaller_set() {
	for (int i = 1; i <= MAXV; i++) if (c[i].fi && c[i].se) {
		vector<pii> vec;
		for (int j = 1; j <= n; j++)
			vec.pb(mp(getcnt(a[j], i), j)); 
		sort(vec.begin(), vec.end());
		work(vec[0].se, vec[1].se); return;
	}
	bool flg = 1;
	for (int i = 1; i <= MAXV; i++) flg &= (c[i].fi == 0 && c[i].se == 0);
	if (flg) puts("0"), exit(0);
	for (int i = 1; i <= n; i++) if (a[i] % 2) {
		if (a[i] % 3) {work(i, (i == 1) ? 2 : 1); return;}
		else {
			for (int j = 1; j <= n; j++) if (a[j] % 3) {
				work(i, j); return;
			}
		}
	}
}
int main() {
	scanf("%d", &n); sieve(MAXV);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	calc_c(); gen_smaller_set();
	vector<int> vec;
	vector<pair<int, vector<int> > > res;
	for (int i = 1; i <= n; i++) if (in[i]) vec.pb(i);
	for (int i = 1; i < (1 << vec.size()); i++) {
		int coef = ((__builtin_popcount(i) & 1) ? (-1) : 1) * (__builtin_popcount(i) - 2);
		vector<int> vecc;
		for (int j = 0; j < vec.size(); j++) if (i >> j & 1) vecc.pb(vec[j]);
		for (int j = 1; j <= abs(coef); j++) res.pb(mp(coef < 0, vecc));
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%d %d", res[i].fi, res[i].se.size());
		for (int x : res[i].se) printf(" %d", x);
		printf("\n");
	}
	return 0;
}