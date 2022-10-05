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
const int MAXN = 1e5;
const int BLK = 316;
const int MAXC = 3e5;
int n, qu, bel[MAXN + 5], L[BLK + 5], R[BLK + 5], blk_cnt, blk_sz;
int _gcd(int x, int y) {return (!y) ? x : _gcd(y, x % y);}
pii get(int x, int y) {
	int d = _gcd(abs(x), abs(y));
	return mp(x / d, y / d);
}
vector<pii> prs[MAXN + 5];
vector<int> cols[MAXN + 5];
pii key[MAXC + 5], uni[MAXC + 5]; int cnt = 0, num = 0;
int buc[MAXC + 5], sum = 0;
void ins(int id) {for (int c : cols[id]) buc[c]++, sum += (buc[c] == 1);}
void del(int id) {for (int c : cols[id]) buc[c]--, sum -= (buc[c] == 0);}
struct qry {
	int l, r, id;
	bool operator < (const qry &rhs) {
		if (bel[l] ^ bel[rhs.l]) return bel[l] < bel[rhs.l];
		else if (bel[l] & 1) return r < rhs.r;
		else return r > rhs.r;
	}
} q[MAXN + 5];
int res[MAXN + 5];
int main() {
	scanf("%d", &n); blk_sz = (int)sqrt(n); blk_cnt = (n - 1) / blk_sz + 1;
	for (int i = 1; i <= blk_cnt; i++) {
		L[i] = (i - 1) * blk_sz + 1; R[i] = min(i * blk_sz, n);
		for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
	}
	for (int i = 1; i <= n; i++) {
		vector<pii> tmp; int len; scanf("%d", &len);
		while (len--) {
			int x, y; scanf("%d%d", &x, &y);
			tmp.pb(mp(x, y));
		}
		for (int j = 1; j < tmp.size(); j++)
			prs[i].pb(get(tmp[j].fi - tmp[j - 1].fi, tmp[j].se - tmp[j - 1].se));
		prs[i].pb(get(tmp[0].fi - tmp.back().fi, tmp[0].se - tmp.back().se));
		for (pii p : prs[i]) key[++cnt] = p;
	}
	sort(key + 1, key + cnt + 1); key[0] = mp(-0x3f3f3f3f, -0x3f3f3f3f);
	for (int i = 1; i <= cnt; i++) if (key[i] != key[i - 1]) uni[++num] = key[i];
	for (int i = 1; i <= n; i++) for (pii p : prs[i])
		cols[i].pb(lower_bound(uni + 1, uni + num + 1, p) - uni);
	scanf("%d", &qu);
	for (int i = 1; i <= qu; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	sort(q + 1, q + qu + 1); int cl = 1, cr = 0;
	for (int i = 1; i <= qu; i++) {
		while (cr < q[i].r) ins(++cr);
		while (cl > q[i].l) ins(--cl);
		while (cl < q[i].l) del(cl++);
		while (cr > q[i].r) del(cr--);
		res[q[i].id] = sum;
	}
	for (int i = 1; i <= qu; i++) printf("%d\n", res[i]);
	return 0;
}