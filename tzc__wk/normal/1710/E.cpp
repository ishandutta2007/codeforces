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
const int MAXN = 2e5;
int n, m, a[MAXN + 5], b[MAXN + 5], a1, b1;
ll sum[MAXN + 5]; int c[MAXN + 5];
bool check(int mid) {
	for (int i = 1, j = m; i <= n; i++) {
		while (j && a[i] + b[j] > mid) --j;
		c[i] = j; sum[i] = sum[i - 1] + j;
	}
	ll mx = 0; bool flg = 0;
	for (int i = m, j = 0, pos = n; i; i--) {
		while (pos && c[pos] < m - i) --pos;
		ll s = sum[pos] - 1ll * (m - i) * pos - 1ll * i * (n - j) + (sum[n] - sum[j]);
		if (mx < s) mx = s, flg = 0;
		if (mx == s) flg |= (a1 <= pos || b1 <= i);
		while (j < n && c[j + 1] == i) ++j;
	}
	return flg;
}
int main() {
//	freopen("chess.in", "r", stdin);
//	freopen("chess.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	a1 = a[1]; b1 = b[1];
	sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++) if (a[i] == a1) {a1 = i; break;}
	for (int i = 1; i <= m; i++) if (b[i] == b1) {b1 = i; break;}
	int l = 1, r = a[a1] + b[b1], p = r;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) p = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", p);
	return 0;
}