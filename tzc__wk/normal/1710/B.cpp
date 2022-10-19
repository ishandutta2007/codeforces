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
const int LOG_N = 20;
int n, m, x[MAXN + 5], p[MAXN + 5], key[MAXN * 3 + 5], uni[MAXN * 3 + 5], cnt, num;
ll d1[MAXN * 3 + 5], d2[MAXN * 3 + 5], premx[MAXN * 3 + 5], sufmx[MAXN * 3 + 5], v[MAXN * 3 + 5];
ll st1[LOG_N + 2][MAXN * 3 + 5], st2[LOG_N + 2][MAXN * 3 + 5];
int lg[MAXN * 3 + 5];
int get(int x) {return lower_bound(uni + 1, uni + num + 1, x) - uni;}
ll query1(int l, int r) {
	int k = lg[r - l + 1];
	return max(st1[k][l], st1[k][r - (1 << k) + 1]);
}
ll query2(int l, int r) {
	int k = lg[r - l + 1];
	return max(st2[k][l], st2[k][r - (1 << k) + 1]);
}
void clear() {
	key[0] = -2e9; cnt = num = 0;
	for (int i = 1; i <= n * 3 + 3; i++) d1[i] = d2[i] = premx[i] = sufmx[i] = 0;
}
void solve() {
	scanf("%d%d", &n, &m); clear();
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &p[i]), key[++cnt] = x[i], key[++cnt] = x[i] - p[i], key[++cnt] = x[i] + p[i];
	sort(key + 1, key + cnt + 1);
	for (int i = 1; i <= cnt; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= n; i++) {
		int L = get(x[i] - p[i]), R = get(x[i] + p[i]), M = get(x[i]);
		d1[L] += -(x[i] - p[i]); d1[M] -= -(x[i] - p[i]); d2[L]++; d2[M]--;
		d1[M] += (x[i] + p[i]); d1[R + 1] -= (x[i] + p[i]); d2[M]--; d2[R + 1]++;
	}
	for (int i = 1; i <= num; i++) d1[i] += d1[i - 1], d2[i] += d2[i - 1];
	for (int i = 1; i <= num; i++) v[i] = d1[i] + d2[i] * uni[i];
//	for (int i = 1; i <= num; i++) printf("%d %lld\n", uni[i], v[i]);
	for (int i = 1; i <= num; i++) premx[i] = max(premx[i - 1], v[i]);
	for (int i = num; i; i--) sufmx[i] = max(sufmx[i + 1], v[i]);
	for (int i = 1; i <= num; i++) st1[0][i] = v[i] - uni[i], st2[0][i] = v[i] + uni[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= num; j++) {
		st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << i - 1)]);
		st2[i][j] = max(st2[i - 1][j], st2[i - 1][j + (1 << i - 1)]);
	}
	for (int i = 1; i <= n; i++) {
		int L = get(x[i] - p[i]), R = get(x[i] + p[i]), M = get(x[i]);
		ll mx = max(premx[L - 1], sufmx[R + 1]);
		chkmax(mx, query1(L, M) + (x[i] - p[i]));
		chkmax(mx, query2(M, R) - (x[i] + p[i]));
//		printf("! %d %lld\n", i, mx);
		printf("%d", (mx <= m));
	}
	printf("\n");
}
int main() {
	for (int i = 2; i <= MAXN * 3; i++) lg[i] = lg[i >> 1] + 1;
	int qu; scanf("%d", &qu); while (qu--) solve();
	return 0;
}