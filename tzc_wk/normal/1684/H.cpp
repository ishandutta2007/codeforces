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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
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
const int MAXN = 1e6;
int n; char s[MAXN + 5]; bool cut[MAXN + 5];
int get(int x) {
	if (x == 1) return 1; --x; int lg = 31 - __builtin_clz(x);
	return 1 << lg + 1;
}
void work(int l, int r, int k, int nd) {
	vector<int> occ; occ.pb(0);
	for (int i = l; i <= r; i++) if (s[i] == '1') occ.pb(i);
	if (nd != get(k)) {
		if (k == 4) {
			if (occ[2] == occ[1] + 1) cut[occ[2] + 1] = cut[occ[3]] = cut[occ[4]] = 1;
			else cut[occ[1] + 2] = cut[occ[2]] = cut[occ[3] + 1] = cut[occ[4]] = 1;
		} else {
			cut[occ[k >> 1]] = 1;
			work(l, occ[k >> 1], k >> 1, nd >> 1);
			work(occ[k >> 1] + 1, r, k >> 1, nd >> 1);
		}
		return;
	}
	if (k <= 16) {
		if (k + (k >> 1) >= nd) {
			for (int i = 1; i <= k; i++) cut[occ[i]] = 1;
			for (int i = 1, stp = 1; stp <= nd - k; stp++, i += 2) {
				cut[occ[i] + 1] = 1; cut[occ[i]] = 0;
			}
		} else if (k == 5) {
			if (occ[2] == occ[1] + 1 && occ[3] == occ[2] + 1 && occ[4] == occ[3] + 1 && occ[5] == occ[4] + 1)
				cut[occ[4]] = cut[occ[5]] = 1;
			else {
				for (int i = 1; i <= 5; i++) cut[occ[i]] = 1;
				for (int i = 1; i <= 4; i++) if (occ[i + 1] > occ[i] + 1) {
					cut[occ[i]] = 0; cut[occ[i] + 2] = 1;
					break;
				}
			}
		} else if (k == 10) {
			cut[occ[4]] = 1;
			work(l, occ[4], 4, 8); work(occ[4] + 1, r, 6, 8);
		} else if (k == 9) {
			bool flg = 1;
			for (int i = 1; i <= 8; i++) flg &= (occ[i + 1] == occ[i] + 1);
			if (flg) cut[occ[3]] = cut[occ[5]] = cut[occ[7]] = cut[occ[9]] = 1;
			else {
				for (int i = 1; i <= 8; i++) if (occ[i + 1] != occ[i] + 1) {
					if (i <= 4) work(l, occ[5], 5, 8), work(occ[5] + 1, r, 4, 8);
					else work(l, occ[4], 4, 8), work(occ[4] + 1, r, 5, 8);
					break;
				}
			}
		}
	} else {
		cut[occ[k >> 1]] = 1;
		work(l, occ[k >> 1], k >> 1, nd >> 1);
		work(occ[k >> 1] + 1, r, k - (k >> 1), nd >> 1);
	}
}
// int Casen = 0, Case2;
void solve() {
	scanf("%s", s + 1); n = strlen(s + 1); bool flg = 1;
	for (int i = 1; i <= n; i++) flg &= (s[i] == '0');
	if (flg) return puts("-1"), void();
	int k = 0; for (int i = 1; i <= n; i++) k += (s[i] == '1');
	for (int i = 1; i <= n; i++) cut[i] = 0; cut[n] = 1;
	work(1, n, k, get(k)); vector<pii> vec; int pre = 0;
	for (int i = 1; i <= n; i++) if (cut[i]) vec.pb(mp(pre + 1, i)), pre = i;
	// ++Casen; if (Casen == 88) printf("%s\n", s + 1);
	// if (!Case2) {
		printf("%d\n", (int)(vec.size()));
		for (pii p : vec) printf("%d %d\n", p.fi, p.se);
	// }
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int qu; scanf("%d", &qu); // Case2 = (qu == 70682);
	while (qu--) solve();
	return 0;
}