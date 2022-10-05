#include <bits/stdc++.h>
using namespace std;
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
		if (x<0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 2000;
int n, a[MAXN + 5], pos;
struct point {
	int x, y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	point operator - (const point &rhs) const {return point(x - rhs.x, y - rhs.y);}
	double operator ~() const {return atan2(y, x);}
} p[MAXN + 5];
int f[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x != y) f[x] = y;
}
vector<pii> res;
void deal(int x, int y) {swap(a[x], a[y]); res.pb(mp(x, y));}
int seq[MAXN + 5], seq_num = 0;
bool cmp(int x, int y) {return (~(p[x] - p[pos])) < (~(p[y] - p[pos]));}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &a[i]);
	bool flg = 1;
	for (int i = 1; i <= n; i++) flg &= (a[i] == i);
	if (flg) return puts("0"), 0;
	for (int i = 1; i <= n; i++) if (a[i] != i) merge(i, a[i]);
	for (int i = 1; i <= n; i++) if (a[i] != i &&
	(!pos || (mp(p[i].x, p[i].y) < mp(p[pos].x, p[pos].y))))
		pos = i;
	for (int i = 1; i <= n; i++) if (a[i] != i && i != pos)
		seq[++seq_num] = i;
	sort(seq + 1, seq + seq_num + 1, cmp);
	for (int i = 1; i < seq_num; i++) {
		if (find(seq[i]) != find(seq[i + 1])) {
			deal(seq[i], seq[i + 1]);
			merge(seq[i], seq[i + 1]);
		}
	}
	while (a[pos] != pos) deal(a[pos], pos);
	printf("%llu\n", res.size());
	for (pii p : res) printf("%d %d\n", p.fi, p.se);
	return 0;
}