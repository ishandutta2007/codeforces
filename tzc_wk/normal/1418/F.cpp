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
using namespace fastio;
const int MAXN = 2e5;
vector<int> fac[MAXN + 5];
void init(int n) {
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i)
		fac[j].pb(i);
}
int n, m; ll L, R;
set<pii> st;
int main() {
	init(MAXN); scanf("%d%d%lld%lld", &n, &m, &L, &R);
	int cl = m + 1, cr = m;
	for (int i = 1; i <= n; i++) {
		ll l = (L + i - 1) / i, r = R / i;
		chkmin(r, m);
		if (l > r) {
			print(-1, '\n');
			continue;
		}
		while (cl > l) {
			--cl;
			for (int f : fac[cl]) st.insert(mp(f, cl));
		}
		while (cr > r) {
			for (int f : fac[cr]) st.erase(st.find(mp(f, cr)));
			--cr;
		}
		bool fnd = 0;
		for (int f : fac[i]) {
			set<pii> :: iterator nt = st.lower_bound(mp(f + 1, 0));
			if (nt != st.end()) {
				int g = nt -> fi, y1 = nt -> se;
				ll x2 = 1ll * i / f * g;
				if (x2 <= n) {
					print(i, ' '); print(y1, ' ');
					print(x2, ' '); print(1ll * i * y1 / x2, '\n');
					fnd = 1; break;
				}
			}
		}
		if (!fnd) print(-1, '\n');
	}
	print_final();
	return 0;
}