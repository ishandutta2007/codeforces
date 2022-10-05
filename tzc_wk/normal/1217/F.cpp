// Created time: 2022/7/10 16:00:32
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
int n, qu, lst; map<int, int> has[MAXN + 5];
struct qry {int opt, x, y;} q[MAXN + 5];
pii p[MAXN + 5][2]; int nxt[MAXN + 5][2];
struct node {int l, r; vector<pii> e;} s[MAXN * 4 + 5];
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r; if (l == r) return;
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void insert(int k, int l, int r, pii e) {
	if (l <= s[k].l && s[k].r <= r) return s[k].e.pb(e), void();
	int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) insert(k << 1, l, r, e);
	else if (l > mid) insert(k << 1 | 1, l, r, e);
	else insert(k << 1, l, mid, e), insert(k << 1 | 1, mid + 1, r, e);
}
struct ufset {
	int f[MAXN + 5], dep[MAXN + 5]; stack<tuple<int, int, int> > stk;
	ufset() {memset(f, 0, sizeof(f)); memset(dep, 0, sizeof(dep));}
	int find(int x) {return (!f[x]) ? x : find(f[x]);}
	void merge(int x, int y) {
		x = find(x); y = find(y); if (x == y) return;
		if (dep[x] < dep[y]) swap(x, y);
		stk.push(mt(x, y, dep[x] == dep[y]));
		dep[x] += (dep[x] == dep[y]); f[y] = x;
	}
	bool query(int x, int y) {return find(x) == find(y);}
	void undo() {
		auto p = stk.top(); stk.pop();
		f[get<1>(p)] = 0; dep[get<0>(p)] -= get<2>(p);
	}
} F;
set<pii> st;
void iterate(int k) {
	int tmp = F.stk.size();
	for (auto p : s[k].e) F.merge(p.fi, p.se);
	if (s[k].l == s[k].r) {
		if (q[s[k].l].opt == 1) {
			pii pp = p[s[k].l][lst];
			if (!has[pp.fi][pp.se]) {
				st.insert(pp); has[pp.fi][pp.se] = has[pp.se][pp.fi] = 1;
				if (nxt[s[k].l][lst] > s[k].l + 1)
					insert(1, s[k].l + 1, nxt[s[k].l][lst] - 1, p[s[k].l][lst]);
			} else {
				has[pp.fi][pp.se] = has[pp.se][pp.fi] = 0;
				st.erase(st.find(pp));
			}
			if (st.find(p[s[k].l][lst ^ 1]) != st.end() && nxt[s[k].l][lst ^ 1] > s[k].l + 1)
				insert(1, s[k].l + 1, nxt[s[k].l][lst ^ 1] - 1, p[s[k].l][lst ^ 1]);
		} else lst = F.query(p[s[k].l][lst].fi, p[s[k].l][lst].se), putchar(lst + '0');
	} else iterate(k << 1), iterate(k << 1 | 1);
	while (F.stk.size() > tmp) F.undo();
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= qu; i++) scanf("%d%d%d", &q[i].opt, &q[i].x, &q[i].y);
	build(1, 1, qu);
	for (int i = 1; i <= qu; i++) for (int j = 0; j < 2; j++) {
		p[i][j] = mp((q[i].x + j + n - 1) % n + 1, (q[i].y + j + n - 1) % n + 1);
		if (p[i][j].fi > p[i][j].se) swap(p[i][j].fi, p[i][j].se);
	}
	map<pii, int> buc;
	for (int i = qu; i; i--) if (q[i].opt == 1) {
		for (int j = 0; j < 2; j++) nxt[i][j] = (buc.count(p[i][j])) ? buc[p[i][j]] : qu + 1;
		for (int j = 0; j < 2; j++) buc[p[i][j]] = i;
	}
	iterate(1);
	return 0;
}
/*
3 6
1 1 2
1 2 3
1 3 1
2 1 3
1 3 2
2 2 3
*/