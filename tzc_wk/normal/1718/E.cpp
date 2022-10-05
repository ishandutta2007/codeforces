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
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
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
int n, m, vis[MAXN + 5]; bool flg;
vector<int> a[MAXN + 5], b[MAXN + 5];
vector<pii> A[MAXN + 5], B[MAXN + 5];
bool visa[MAXN + 5], visb[MAXN + 5]; int cl, cr, cmpa, cmpb;
vector<int> ca[MAXN + 5], cb[MAXN + 5];
void dfsa(int x) {
	if (visa[x]) return; visa[x] = 1; ca[cmpa].pb(x); cl += (x <= n); cr += (x > n);
	for (pii p : A[x]) dfsa(p.se);
}
void dfsb(int x) {
	if (visb[x]) return; visb[x] = 1; cb[cmpb].pb(x); cl += (x <= n); cr += (x > n);
	for (pii p : B[x]) dfsb(p.se);
}
int p[MAXN + 5], tmp[MAXN + 5];
bool check(int x, int y) {
	if (tmp[x]) return tmp[x] == y;
	if (A[x].size() != B[y].size()) return 0;
	tmp[x] = y;
	for (int i = 0; i < A[x].size(); i++) {
		if (A[x][i].fi != B[y][i].fi) return 0;
		if (!check(A[x][i].se, B[y][i].se)) return 0;
	}
	return 1;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m); flg = (n > m); if (flg) swap(n, m);
	for (int i = 1; i <= n; i++) a[i].resize(m + 1), b[i].resize(m + 1);
	if (!flg) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &b[i][j]);
	} else {
		for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) scanf("%d", &a[j][i]);
		for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) scanf("%d", &b[j][i]);
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (a[i][j]) A[i].pb(mp(a[i][j], j + n)), A[j + n].pb(mp(a[i][j], i));
		if (b[i][j]) B[i].pb(mp(b[i][j], j + n)), B[j + n].pb(mp(b[i][j], i));
	}
	for (int i = 1; i <= n + m; i++) sort(A[i].begin(), A[i].end()), sort(B[i].begin(), B[i].end());
	map<pii, vector<pii> > vec;
	for (int i = 1; i <= n + m; i++) if (!visa[i]) cl = cr = 0, ++cmpa, dfsa(i), vec[mp(cl, cr)].pb(mp(0, cmpa));
	for (int i = 1; i <= n + m; i++) if (!visb[i]) cl = cr = 0, ++cmpb, dfsb(i), vec[mp(cl, cr)].pb(mp(1, cmpb));
	for (int i = 1; i <= cmpa; i++) sort(ca[i].begin(), ca[i].end());
	for (int i = 1; i <= cmpb; i++) sort(cb[i].begin(), cb[i].end());
	for (auto tt : vec) {
		set<int> sta, stb; int L = tt.fi.fi, R = tt.fi.se;
		for (pii pp : tt.se) {
			if (pp.fi == 0) sta.insert(pp.se);
			if (pp.fi == 1) stb.insert(pp.se);
		}
		if (sta.size() != stb.size()) return puts("-1"), 0;
		if (!L) {
			while (!sta.empty()) {
				int ida = *sta.begin(); sta.erase(sta.find(ida));
				int idb = *stb.begin(); stb.erase(stb.find(idb));
				p[ca[ida][0]] = cb[idb][0];
			}
			continue;
		}
		while (!sta.empty()) {
			int x = *sta.rbegin(); sta.erase(sta.find(x));
			bool flg = 0;
			for (int y : stb) {
				for (int pt : cb[y]) {
					if (pt > n) break;
					for (int z : ca[x]) tmp[z] = 0;
					if (check(ca[x][0], pt)) {
						flg = 1; stb.erase(stb.find(y));
						for (int z : ca[x]) p[z] = tmp[z];
						break;
					}
				}
				if (flg) break;
			}
			if (!flg) return puts("-1"), 0;
		}
	}
	// for (int i = 1; i <= n + m; i++) printf("%d%c", p[i], " \n"[i == n + m]);
	vector<tuple<int, int, int> > res;
	for (int i = 1; i <= n + m; i++) if (!vis[i]) {
		vector<int> v; int cur = i;
		while (!vis[cur]) {vis[cur] = 1; v.pb(cur); cur = p[cur];}
		for (int j = (int)(v.size()) - 1; j; j--) {
			if (i > n) res.pb(mt(2, v[j] - n, v[j - 1] - n));
			else res.pb(mt(1, v[j], v[j - 1]));
		}
	}
	printf("%d\n", (int)(res.size()));
	for (auto t : res) printf("%d %d %d\n", ((flg) ? 3 : 0) ^ get<0>(t), get<1>(t), get<2>(t));
	return 0;
}