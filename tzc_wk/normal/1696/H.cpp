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
const int MAXN = 600;
const int MOD = 1e9 + 7;
int n, k, p[MAXN + 5], t[MAXN + 5], np, nt, res = 0;
int dp_p[MAXN + 5][MAXN + 5], dp_t[MAXN + 5][MAXN + 5], dp_t2[MAXN + 5][MAXN + 5], pw2[MAXN + 5];
struct dat {
	ll v; int opt, l, r;
	dat(ll _v, int _opt, int _l, int _r) {v = _v; opt = _opt; l = _l; r = _r;}
	friend bool operator < (const dat &X, const dat &Y) {
		return mt(X.v, X.opt, X.l, X.r) < mt(Y.v, Y.opt, Y.l, Y.r);
	}
};
vector<dat> vec;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for (int i = (pw2[0] = 1); i <= n; i++) pw2[i] = 2 * pw2[i - 1] % MOD;
	for (int i = 1, x; i <= n; i++) {scanf("%d", &x); if (x > 0) p[++np] = x; else t[++nt] = x;}
	sort(p + 1, p + np + 1, greater<int>()); sort(t + 1, t + nt + 1);
	dp_p[0][0] = 1;
	for (int i = 0; i < np; i++) for (int j = 0; j <= i; j++) {
		dp_p[i + 1][j] = (dp_p[i + 1][j] + dp_p[i][j]) % MOD;
		dp_p[i + 1][j + 1] = (dp_p[i + 1][j + 1] + 1ll * dp_p[i][j] * p[i + 1]) % MOD;
	}
	dp_t[0][0] = 1;
	for (int i = 0; i < nt; i++) for (int j = 0; j <= i; j++) {
		dp_t[i + 1][j] = (dp_t[i + 1][j] + dp_t[i][j]) % MOD;
		dp_t[i + 1][j + 1] = (dp_t[i + 1][j + 1] + 1ll * dp_t[i][j] * (t[i + 1] + MOD)) % MOD;
	}
	dp_t2[nt + 1][0] = 1;
	for (int i = nt + 1; i >= 2; i--) for (int j = 0; j <= nt + 1 - i; j++) {
		dp_t2[i - 1][j] = (dp_t2[i - 1][j] + dp_t2[i][j]) % MOD;
		dp_t2[i - 1][j + 1] = (dp_t2[i - 1][j + 1] + 1ll * dp_t2[i][j] * (t[i - 1] + MOD)) % MOD;
	}
	int res = 0;
	for (int x = 1; x <= k; x += 2) res = (res + 1ll * dp_t[nt][x] * dp_p[np][k - x]) % MOD;
	if (k & 1) {
		for (int i = 1; i <= nt; i++)
			res = (res + 1ll * pw2[i - 1] * (dp_t2[i][k] - dp_t2[i + 1][k] + MOD)) % MOD;
		res = (res - dp_t2[1][k] + MOD) % MOD;
	}
	for (int i = 0; i <= np; i++) for (int j = 0; j <= nt; j++) {
		for (int x = 0; x <= k; x += 2) {
			int vp = (dp_p[i][k - x] - ((!i) ? 0 : dp_p[i - 1][k - x]) + MOD) % MOD;
			int vt = (dp_t[j][x] - ((!j) ? 0 : dp_t[j - 1][x]) + MOD) % MOD;
			res = (res + 1ll * vp * vt % MOD * pw2[np - i] % MOD * pw2[nt - j]) % MOD;
		}
	}
	for (int i = 1; i <= np; i++) for (int j = i + 1; j <= np; j++)
		vec.pb(dat(1ll * p[i] * p[j], 0, i, j));
	for (int i = 1; i <= nt; i++) for (int j = i + 1; j <= nt; j++)
		vec.pb(dat(1ll * t[i] * t[j], 1, i, j));
	sort(vec.begin(), vec.end());
	for (int x = 0; x + 2 <= k; x += 2) {
		int sum = 0;
		for (auto t : vec) {
			ll v = t.v; int opt = t.opt, l = t.l, r = t.r;
			if (!opt) sum = (sum + 1ll * v % MOD * dp_p[l - 1][k - x - 2] % MOD * pw2[np - r]) % MOD;
			else res = (res - 1ll * sum * dp_t[l - 1][x] % MOD * pw2[nt - r] % MOD + MOD) % MOD;
		}
	}
	for (int x = 2; x <= k; x += 2) {
		int sum = 0;
		for (auto t : vec) {
			ll v = t.v; int opt = t.opt, l = t.l, r = t.r;
			if (opt) sum = (sum + 1ll * v % MOD * dp_t[l - 1][x - 2] % MOD * pw2[nt - r]) % MOD;
			else res = (res - 1ll * sum * dp_p[l - 1][k - x] % MOD * pw2[np - r] % MOD + MOD) % MOD;
		}
	}
	printf("%d\n", res);
	return 0;
}