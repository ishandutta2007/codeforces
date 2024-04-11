// Created time: 2022/6/12 21:42:02
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
const int MAXP = MAXN << 5;
const int LOG_V = 30;
int n, a[MAXN + 5], m, b[MAXN + 5]; map<int, int> id;
int f[MAXN + 5]; ll res = 0;
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y, int z) {
	x = find(x); y = find(y); if (x == y) return;
	f[x] = y; res += z;
}
vector<int> cmps[MAXN + 5];
struct node {int ch[2], siz;} s[MAXP + 5];
int rt, ncnt;
void insert(int &k, int v, int d, int coef) {
	if (!k) k = ++ncnt; s[k].siz += coef; if (d < 0) return;
	insert(s[k].ch[v >> d & 1], v, d - 1, coef);
}
int query(int k, int v, int d) {
	if (d < 0) return 0;
	if (s[s[k].ch[v >> d & 1]].siz) return query(s[k].ch[v >> d & 1], v, d - 1);
	else return query(s[k].ch[~v >> d & 1], v, d - 1) | (1 << d);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); a[0] = -1;
	for (int i = 1; i <= n; i++) if (a[i] != a[i - 1]) b[++m] = a[i];
	for (int i = 1; i <= m; i++) id[b[i]] = i;
	vector<vector<int> > vec;
	for (int i = 1; i <= m; i++) vec.pb({i});
	for (int i = 1; i <= m; i++) insert(rt, b[i], LOG_V, 1);
	while (vec.size() > 1) {
		for (int i = 1; i <= m; i++) cmps[i].clear();
		for (auto p : vec) {
			for (int x : p) insert(rt, b[x], LOG_V, -1);
			tuple<int, int, int> mn = mt(2e9, 0, 0);
			for (int x : p) {
				int val = query(rt, b[x], LOG_V);
				chkmin(mn, mt(val, x, id[val ^ b[x]]));
			}
			for (int x : p) insert(rt, b[x], LOG_V, 1);
			merge(get<1>(mn), get<2>(mn), get<0>(mn));
		}
		for (int i = 1; i <= m; i++) cmps[find(i)].pb(i);
		vector<vector<int> > nvec;
		for (int i = 1; i <= m; i++) if (!cmps[i].empty())
			nvec.pb(cmps[i]);
		swap(nvec, vec);
//		printf("%d\n", vec.size());
	}
	printf("%lld\n", res);
	return 0;
}