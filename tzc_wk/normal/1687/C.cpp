// Created time: 2022/6/6 14:45:56
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
int n, m, a[MAXN + 5], b[MAXN + 5], vis[MAXN + 5];
pii c[MAXN + 5]; set<int> st;
ll sum[MAXN + 5];
vector<pii> qv[MAXN + 5];
queue<int> Q;
void clear() {
	st.clear();
	for (int i = 0; i <= n; i++) qv[i].clear();
	for (int i = 1; i <= m; i++) vis[i] = 0;
}
void deal(int x) {
	st.erase(st.find(x)); sum[x] = 0;
	for (pii pp : qv[x]) if (!sum[pp.fi] && !vis[pp.se])
		vis[pp.se] = 1, Q.push(pp.se);
}
void solve() {
	scanf("%d%d", &n, &m); clear();
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d%d", &x, &y); x--;
		qv[x].pb(mp(y, i)); qv[y].pb(mp(x, i));
		c[i] = mp(x, y);
	}
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i] - b[i];
	for (int i = 0; i <= n; i++) st.insert(i);
	for (int i = 0; i <= n; i++) if (!sum[i]) deal(i);
	while (!Q.empty()) {
		int id = Q.front(); Q.pop();
		while (1) {
			set<int> :: iterator it = st.upper_bound(c[id].fi);
			if (it == st.end() || (*it) > c[id].se) break;
			deal(*it);
		}
	}
	printf("%s\n", (st.empty()) ? "YES" : "NO");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}