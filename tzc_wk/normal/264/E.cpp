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
const int MAXN = 2e5 + 20;
int n, qu;
struct segtree {
	struct node {int l, r, mx;} s[MAXN * 4 + 5];
	void pushup(int k) {s[k].mx = max(s[k << 1].mx, s[k << 1 | 1].mx);}
	void build(int k, int l, int r) {
		s[k].l = l; s[k].r = r; s[k].mx = 0; if (l == r) return;
		int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	}
	void modify(int k, int p, int v) {
		if (s[k].l == s[k].r) return s[k].mx = v, void();
		int mid = s[k].l + s[k].r >> 1;
		(p <= mid) ? modify(k << 1, p, v) : modify(k << 1 | 1, p, v);
		pushup(k);
	}
	int query(int k, int l, int r) {
		if (l > r) return 0;
		if (l <= s[k].l && s[k].r <= r) return s[k].mx;
		int mid = s[k].l + s[k].r >> 1;
		if (r <= mid) return query(k << 1, l, r);
		else if (l > mid) return query(k << 1 | 1, l, r);
		else return max(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
	}
} S0, S[11];
int t[MAXN + 5], P[MAXN + 5], a[MAXN + 5], dp[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= MAXN; i += (i & (-i))) t[i] += v;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
int main() {
	scanf("%d%d", &n, &qu); S0.build(1, 1, n);
	for (int i = 1; i <= 10; i++) S[i].build(1, 1, MAXN);
	multiset<int> st, alive; st.insert(0);
	for (int i = 1; i <= qu; i++) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int pos, h; scanf("%d%d", &pos, &h);
			assert(!a[pos] && !P[h]);
			h = h + 2e5 - i; P[h] = pos; a[pos] = h;
			dp[pos] = S0.query(1, pos + 1, n) + 1;
			for (int j = h + 1; j <= min(h + 20, MAXN); j++) if (P[j] > pos)
				chkmax(dp[pos], dp[P[j]] + 1);
			st.insert(dp[pos]); add(pos, 1);
			int cc = query(pos - 1);
			for (int j = 1; j <= min(cc, 10); j++) S[j].modify(1, a[pos], dp[pos]);
			if (cc <= 10) {
				multiset<int> :: iterator it = alive.upper_bound(pos);
				for (int j = cc; j <= 10; j++) {
					if (it != alive.end()) {
						S[j].modify(1, a[*it], dp[*it]);
						++it;
					}
				}
			}
			for (int j = h - 1; j >= max(h - 10, 1); j--) if (P[j]) {
				st.erase(st.find(dp[P[j]]));
				for (int k = j + 1; k <= h; k++) if (P[k] > P[j])
					chkmax(dp[P[j]], dp[P[k]] + 1);
				st.insert(dp[P[j]]); int pp = query(P[j] - 1);
				for (int k = 1; k <= min(pp, 10); k++) S[k].modify(1, a[P[j]], dp[P[j]]);
			}
			alive.insert(pos);
		} else {
			int x; scanf("%d", &x); vector<int> poss;
			multiset<int> :: iterator it = alive.begin();
			for (int j = 1; j <= x; j++) poss.pb(*it), it++;
			for (int j = x - 1; ~j; j--) {
				int pos = poss[j]; st.erase(st.find(dp[pos]));
				if (j != x - 1) dp[pos] = S[j + 1].query(1, a[pos] + 1, MAXN) + 1;
				else dp[pos] = 0;
				for (int k = 0; k < j; k++) S[k + 1].modify(1, a[pos], dp[pos]);
				if (j != x - 1) st.insert(dp[pos]);
				if (a[pos] > 200020 - i) S0.modify(1, pos, dp[pos]);
			}
			P[a[poss.back()]] = 0; a[poss.back()] = 0;
			add(poss.back(), -1);
			alive.erase(alive.find(poss.back()));
			for (int j = x; j <= 10; j++) {
				if (it != alive.end()) {
					S[j].modify(1, a[*it], 0);
					++it;
				}
			}
		}
		if (P[200020 - i]) S0.modify(1, P[200020 - i], dp[P[200020 - i]]);
		printf("%d\n", *st.rbegin());
	}
	return 0;
}