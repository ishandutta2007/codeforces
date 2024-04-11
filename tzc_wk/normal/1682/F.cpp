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
const int MAXN = 2e5;
const int MAXP = MAXN * 32;
const int MOD = 1e9 + 7;
int n, qu, a[MAXN + 5], b[MAXN + 5], num;
ll sum[MAXN + 5], key[MAXN + 5], uni[MAXN + 5];
int get(ll x) {return lower_bound(uni + 1, uni + num + 1, x) - uni;}
struct node {int ch[2], sum_v, sum_sv;} s[MAXP + 5];
int ncnt, rt[MAXN + 5];
void build(int &k, int l, int r) {
	k = ++ncnt; s[k].sum_v = s[k].sum_sv = 0; if (l == r) return;
	int mid = l + r >> 1; build(s[k].ch[0], l, mid); build(s[k].ch[1], mid + 1, r);
}
int modify(int k, int l, int r, int p, int v, int sv) {
	int z = ++ncnt; s[z] = s[k]; s[z].sum_v = (s[z].sum_v + v) % MOD; s[z].sum_sv = (s[z].sum_sv + sv) % MOD;
	if (l == r) return z; int mid = l + r >> 1;
	if (p <= mid) s[z].ch[0] = modify(s[k].ch[0], l, mid, p, v, sv);
	else s[z].ch[1] = modify(s[k].ch[1], mid + 1, r, p, v, sv);
	return z;
}
int query_v(int kl, int kr, int l, int r, int ql, int qr) {
	if (ql > qr) return 0;
	if (ql <= l && r <= qr) return (s[kr].sum_v - s[kl].sum_v + MOD) % MOD;
	int mid = l + r >> 1;
	if (qr <= mid) return query_v(s[kl].ch[0], s[kr].ch[0], l, mid, ql, qr);
	else if (ql > mid) return query_v(s[kl].ch[1], s[kr].ch[1], mid + 1, r, ql, qr);
	else return (query_v(s[kl].ch[0], s[kr].ch[0], l, mid, ql, mid) + query_v(s[kl].ch[1], s[kr].ch[1], mid + 1, r, mid + 1, qr)) % MOD;
}
int query_sv(int kl, int kr, int l, int r, int ql, int qr) {
	if (ql > qr) return 0;
	if (ql <= l && r <= qr) return (s[kr].sum_sv - s[kl].sum_sv + MOD) % MOD;
	int mid = l + r >> 1;
	if (qr <= mid) return query_sv(s[kl].ch[0], s[kr].ch[0], l, mid, ql, qr);
	else if (ql > mid) return query_sv(s[kl].ch[1], s[kr].ch[1], mid + 1, r, ql, qr);
	else return (query_sv(s[kl].ch[0], s[kr].ch[0], l, mid, ql, mid) + query_sv(s[kl].ch[1], s[kr].ch[1], mid + 1, r, mid + 1, qr)) % MOD;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) a[i] = a[i + 1] - a[i];
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i], key[i] = sum[i];
	sort(key + 1, key + n + 1); key[0] = -1e18;
	for (int i = 1; i <= n; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	build(rt[0], 1, num);
	for (int i = 1; i <= n; i++) rt[i] = modify(rt[i - 1], 1, num, get(sum[i]), a[i], 1ll * (sum[i] % MOD + MOD) * a[i] % MOD);
	// for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) printf("%lld%c", sum[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) printf("%d%c", get(sum[i]), " \n"[i == n]);
	while (qu--) {
		int l, r; scanf("%d%d", &l, &r); int posv = get(sum[l - 1]);
		int res = (query_sv(rt[l - 1], rt[r], 1, num, posv + 1, num) - 1ll * (sum[l - 1] % MOD + MOD) * query_v(rt[l - 1], rt[r], 1, num, posv + 1, num) % MOD + MOD) % MOD;
		res = (res + 1ll * (sum[l - 1] % MOD + MOD) * query_v(rt[l - 1], rt[r], 1, num, 1, posv) - query_sv(rt[l - 1], rt[r], 1, num, 1, posv) + MOD) % MOD;
		printf("%d\n", res);
	}
	return 0;
}