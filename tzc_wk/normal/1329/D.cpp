#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 2e5;
int n, m, cnt[28], pos[MAXN + 5];
char s[MAXN + 5], t[MAXN + 5];
namespace seg {
	struct node {int l, r, sum, lz;} s[MAXN * 4 + 5];
	void pushup(int k) {s[k].sum = s[k << 1].sum + s[k << 1 | 1].sum;}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; s[k].sum = r - l + 1; s[k].lz = 0;
		if (l == r) return; int mid = l + r >> 1;
		build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	}
	void tag(int k) {s[k].sum = 0; s[k].lz = 1;}
	void pushdown(int k) {if (s[k].lz) tag(k << 1), tag(k << 1 | 1), s[k].lz = 0;}
	void modify(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return tag(k), void();
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) modify(k << 1, l, r);
		else if (l > mid) modify(k << 1 | 1, l, r);
		else modify(k << 1, l, mid), modify(k << 1 | 1, mid + 1, r);
		pushup(k);
	}
	int query(int k, int l, int r) {
		if (l <= s[k].l && s[k].r <= r) return s[k].sum;
		pushdown(k); int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return query(k << 1, l, mid) + query(k << 1 | 1, mid + 1, r);
	}
}
using seg :: build;
using seg :: modify;
using seg :: query;
vector<pii> res;
void deal(int l, int r) {
	res.pb(mp(query(1, 1, l), query(1, 1, r)));
	modify(1, l, r);
}
void clear() {res.clear(); m = 0; memset(cnt, 0, sizeof(cnt));}
int getmx() {
	pii mx = mp(-1, -1);
	for (int i = 0; i < 26; i++) chkmax(mx, mp(cnt[i], i));
	return mx.se;
}
bool check() {
	int ss = 0;
	for (int i = 0; i < 26; i++) ss += cnt[i];
	return cnt[getmx()] * 2 <= ss;
}
void solve() {
	scanf("%s", s + 1); n = strlen(s + 1); clear();
	build(1, 1, n);
	for (int i = 2; i <= n; i++) if (s[i] == s[i - 1]) t[++m] = s[i], pos[m] = i;
	for (int i = 1; i <= m; i++) cnt[t[i] - 'a']++;
	if (m & 1) {
		int id = getmx();
		for (int i = 1; i <= m; i++) if (t[i] - 'a' == id) {
			deal(pos[i], pos[i]);
			for (int j = i + 1; j <= m; j++) t[j - 1] = t[j], pos[j - 1] = pos[j];
			break;
		}
		cnt[id]--; m--;
	}
	static int stk[MAXN + 5]; int tp = 0, id = getmx();
	if (cnt[id] * 2 <= m) {
		for (int i = 1; i <= m; i++) {
			if (!tp || t[i] == t[stk[tp]]) stk[++tp] = i;
			else {
				cnt[t[i] - 'a']--; cnt[t[stk[tp]] - 'a']--;
				if (check()) {deal(pos[stk[tp]], pos[i] - 1); --tp;}
				else cnt[t[i] - 'a']++, cnt[t[stk[tp]] - 'a']++, stk[++tp] = i;
			} 
		}
	} else {
		for (int i = 1; i <= m; i++) {
			if (t[i] - 'a' == id) {
				if (!tp || t[stk[tp]] - 'a' == id) stk[++tp] = i;
				else deal(pos[stk[tp]], pos[i] - 1), --tp;
			} else {
				if (tp && t[stk[tp]] - 'a' == id) deal(pos[stk[tp]], pos[i] - 1), --tp;
				else stk[++tp] = i;
			}
		}
	}
	string lft;
	for (int i = 1; i <= n; i++) if (query(1, i, i)) lft.pb(s[i]);
	if (!lft.empty()) {
//		cout << lft << endl;
		int pre = -1;
		for (int i = 1; i < lft.size(); i++) if (lft[i] == lft[i - 1]) {
			res.pb(mp(1, i - 1 - pre)); pre = i - 1;
		}
		res.pb(mp(1, lft.size() - 1 - pre));
	}
	printf("%d\n", res.size());
	for (pii p : res) printf("%d %d\n", p.fi, p.se);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}