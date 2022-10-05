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
int vis[MAXN + 5], pr[MAXN + 5], prcnt;
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) vis[pr[j] * i] = 1;
	}
}
int n, qu, a[MAXN + 5]; ll sum[20][MAXN + 5];
void solve() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> fac; multiset<ll> st;
	for (int i = 1; i < n; i++) if (n % i == 0 && !vis[n / i]) fac.pb(i);
	for (int i = 0; i < fac.size(); i++) {
		int id = fac[i];
		for (int j = 0; j <= n; j++) sum[i][j] = 0;
		for (int j = 1; j <= n; j++) sum[i][j % id] += a[j];
		for (int j = 0; j < id; j++) st.insert(sum[i][j] * id);
	}
	printf("%lld\n", (*st.rbegin()));
	while (qu--) {
		int x, v; scanf("%d%d", &x, &v);
		for (int i = 0; i < fac.size(); i++) {
			int id = fac[i];
			st.erase(st.find(sum[i][x % id] * id));
			sum[i][x % id] -= a[x]; sum[i][x % id] += v;
			st.insert(sum[i][x % id] * id);
		}
		a[x] = v;
		printf("%lld\n", (*st.rbegin()));
	}
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	sieve(MAXN);
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}