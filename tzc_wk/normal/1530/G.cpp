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
int n, k; char s[MAXN + 5], t[MAXN + 5];
struct solver {
	char str[MAXN + 5];
	int pos[MAXN + 5], pos_cnt = 0;
	vector<pii> res;
	void init() {
		memset(pos, 0, sizeof(pos)); 
		pos_cnt = 0;
		for (int i = 1; i <= n; i++) if (str[i] == '1')
			pos[++pos_cnt] = i;
		pos[pos_cnt + 1] = n + 1;
	}
	void perf(int l, int r) {
		if (l > r) return;
		reverse(str + l, str + r + 1);
		res.pb(mp(l, r)); init();
	}
	void work() {
		res.clear();
		for (int i = pos_cnt; i > k; i--) perf(pos[i - k + 1], pos[i + 1] - 1);
		if (~k & 1) {
			for (int i = 1; i <= k; i++) {
				if (i & 1) perf(pos[1], pos[k + 1] - 1);
				else perf(pos[1] + 1, pos[k + 1]);
			}
		} else {
			for (int i = 1; i <= k * 2; i++) {
				if (i & 1) perf(pos[1], pos[k + 1] - 1);
				else perf(pos[2], pos[k + 2] - 1);
			}
		}
//		printf("%s\n", str + 1);
	}
} A, B;
void solve() {
	fill0(s); fill0(t);
	scanf("%d%d%s%s", &n, &k, s + 1, t + 1);
	int cs = 0, ct = 0;
	for (int i = 1; i <= n; i++) cs += (s[i] == '1'), ct += (t[i] == '1');
	if (cs != ct) return puts("-1"), void();
	if (k == 0 || k > cs) {
		for (int i = 1; i <= n; i++) if (s[i] != t[i])
			return puts("-1"), void();
		puts("0"); return;
	}
	memcpy(A.str, s, sizeof(s));
	memcpy(B.str, t, sizeof(t));
	A.init(); B.init();
	if (k == cs) {
		bool flg = 1;
		for (int i = 1; i <= n; i++) flg &= (s[i] == t[i]);
		if (flg) return puts("0"), void();
		function<bool(int)> check = [&](int rev) {
			bool flg = 1;
			for (int i = 1; i < cs; i++) {
				if (A.pos[i + 1] - A.pos[i] != B.pos[i + 1] - B.pos[i]) {
					flg = 0; break;
				}
			}
			if (flg) {
				if (rev) printf("3\n%d %d\n%d %d\n%d %d\n", 1, n, A.pos[1], n, B.pos[1], n);
				else printf("2\n%d %d\n%d %d\n", A.pos[1], n, B.pos[1], n);
				return 1;
			}
			return 0;
		};
		if (check(0)) return;
		reverse(A.str + 1, A.str + n + 1);
		reverse(s + 1, s + n + 1);
		flg = 1;
		for (int i = 1; i <= n; i++) flg &= (s[i] == t[i]);
		if (flg) return printf("1\n%d %d\n", 1, n), void();
		A.init();
		if (check(1)) return;
		puts("-1");
		return;
	}
	if (~k & 1) {
		int sA = 0, sB = 0;
		for (int i = 1; i <= cs; i += 2) sA += A.pos[i + 1] - A.pos[i];
		for (int i = 1; i <= cs; i += 2) sB += B.pos[i + 1] - B.pos[i];
		if (sA != sB) return puts("-1"), void();
	}
	A.work(); B.work();
	printf("%d\n", A.res.size() + B.res.size());
	for (int i = 0; i < A.res.size(); i++) printf("%d %d\n", A.res[i].fi, A.res[i].se);
	for (int i = (int)(B.res.size()) - 1; ~i; i--) printf("%d %d\n", B.res[i].fi, B.res[i].se);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}
/*
1
11 3
11001011010
01111000110

1
10 8
1101111110
0110111111
*/