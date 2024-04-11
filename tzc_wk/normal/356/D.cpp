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
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 7e4;
int n, s, a[MAXN + 5], mx = 0, fst[MAXN + 5], nxt[MAXN + 5];
bitset<MAXN + 5> vis;
bool is[MAXN + 5];
void work(int x) {
	if (!x) return; is[fst[x]] = 1;
//	printf("work %d\n", x);
	work(x - a[fst[x]]);
}
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), chkmax(mx, a[i]);
	int pos = 0;
	for (int i = 1; i <= n; i++) if (a[i] == mx) {
		pos = i; break;
	}
	vis.set(0);
	if (s < mx) return puts("-1"), 0;
	for (int i = 1; i <= n; i++) if (i != pos) {
		bitset<MAXN + 5> nxt = vis | vis << a[i];
		bitset<MAXN + 5> dif = nxt ^ vis;
		for (int j = dif._Find_first(); j < dif.size(); j = dif._Find_next(j))
			fst[j] = i;
		vis = nxt;
	}
	if (!vis[s - mx]) return puts("-1"), 0;
//	printf("mx = %d\n", mx);
	work(s - mx); is[pos] = 1; vector <pii> vec;
	for (int i = 1; i <= n; i++) if (!is[i]) vec.pb(mp(a[i], i));
	sort(vec.begin(), vec.end(), greater<pii>());
//	printf("%d\n", vec.size());
	int pre = pos;
	for (int i = 0; i < vec.size(); i++) nxt[pre] = vec[i].se, pre = vec[i].se;
	for (int i = 1; i <= n; i++){
		if(!nxt[i]) printf("%d 0\n", a[i]);
		else printf("%d 1 %d\n", a[i] - a[nxt[i]], nxt[i]);
	}
	return 0;
}