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
const int MAXN = 2e5;
int n, b[MAXN + 5], res[MAXN + 5];
vector<int> pos[MAXN + 5];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) pos[i].clear(), res[i] = 0;
	for (int i = 1; i <= n; i++) pos[b[i]].pb(i);
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (!pos[i].empty());
	printf("%d\n", cnt);
	if (cnt == n) {
		for (int i = 1; i <= n; i++) res[pos[i][0]] = i;
	} else if (cnt == n - 1) {
		int tt = 0;
		for (int i = 1; i <= n; i++) if (pos[i].empty()) tt = i;
		for (int i = 1; i <= n; i++) if (i != tt) {
			if (pos[i].size() == 1) res[pos[i][0]] = i;
			else {
				for (int j = 0; j < 2; j++) if (pos[i][j ^ 1] != tt) {
					res[pos[i][j]] = i;
					res[pos[i][j ^ 1]] = tt;
				}
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (!pos[i].empty()) res[pos[i][0]] = i;
		}
		vector<int> vec;
		queue<int> nd;
		for (int i = 1; i <= n; i++) if (pos[i].empty()) {
			if (!res[i]) vec.pb(i);
			else nd.push(i);
		}
		if (!vec.empty()) {
			if (vec.size() >= 2) {
				for (int i = 0; i < vec.size(); i++) {
					res[vec[i]] = vec[(i + 1) % vec.size()];
				}
			} else res[vec[0]] = nd.front(), nd.pop(), nd.push(vec[0]);
		}
		for (int i = 1; i <= n; i++) if (!res[i]) res[i] = nd.front(), nd.pop();
	}
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}