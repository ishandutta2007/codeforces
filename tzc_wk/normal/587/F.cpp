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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXN = 1e5;
const int BLK = 256;
const int ALPHA = 26;
int n, qu; char buf[MAXN + 5];
string s[MAXN + 5];
namespace AC_Automaton {
	int ch[MAXN + 5][ALPHA + 2], ncnt, fail[MAXN + 5], ed[MAXN + 5];
	void insert(string s, int id) {
		int cur = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!ch[cur][s[i] - 'a']) ch[cur][s[i] - 'a'] = ++ncnt;
			cur = ch[cur][s[i] - 'a'];
		}
		ed[id] = cur;
	}
	void getfail() {
		queue<int> q;
		for (int i = 0; i < ALPHA; i++) if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < ALPHA; i++) {
				if (ch[x][i]) fail[ch[x][i]] = ch[fail[x]][i], q.push(ch[x][i]);
				else ch[x][i] = ch[fail[x]][i];
			}
		}
	}
	int hd[MAXN + 5], to[MAXN + 5], nxt[MAXN + 5], ec = 0;
	void adde(int u, int v) {
//		printf("adde %d %d\n", u, v);
		to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;
	}
	int dfn[MAXN + 5], edt[MAXN + 5], tim;
	void dfs0(int x) {dfn[x] = ++tim; for (int e = hd[x]; e; e = nxt[e]) dfs0(to[e]); edt[x] = tim;}
	void init() {getfail(); for (int i = 1; i <= ncnt; i++) adde(fail[i], i); dfs0(0);}
}
using namespace AC_Automaton;
ll res[MAXN + 5];
namespace BIG {
	int id[MAXN + 5], idcnt, mark[MAXN + 5]; ll cnt[MAXN + 5];
	void dfspush(int x) {
		for (int e = hd[x]; e; e = nxt[e]) {
			dfspush(to[e]); mark[x] += mark[to[e]];
		}
	}
	void init_big() {
		for (int i = 1; i <= n; i++) if (s[i].size() > BLK)
			id[i] = ++idcnt;
	}
	vector<tuple<int, int, int> > qv_big[MAXN + 5];
	void solve_big() {
		for (int i = 1; i <= n; i++) if (id[i]) {
			int cur = 0; memset(mark, 0, sizeof(mark));
			for (int j = 0; j < s[i].size(); j++) {
				cur = ch[cur][s[i][j] - 'a'];
				mark[cur]++;
			}
			dfspush(0);
			for (int j = 1; j <= n; j++) cnt[j] = mark[ed[j]];
			for (int j = 1; j <= n; j++) cnt[j] += cnt[j - 1];
			for (auto T : qv_big[i]) res[get<2>(T)] = cnt[get<1>(T)] - cnt[get<0>(T) - 1];
		}
	}
}
using namespace BIG;
namespace SMALL {
	vector<tuple<int, int, int> > qv_sml[MAXN + 5];
	int t[MAXN + 5];
	void add(int x, int v) {for (int i = x; i <= ncnt + 1; i += (i & (-i))) t[i] += v;}
	int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
	void solve_small() {
		for (int i = 1; i <= n; i++) {
			add(dfn[ed[i]], 1); add(edt[ed[i]] + 1, -1);
			for (auto T : qv_sml[i]) {
				int id = get<2>(T), sum = 0, cur = 0;
				for (int j = 0; j < s[id].size(); j++) {
					cur = ch[cur][s[id][j] - 'a'];
					sum += query(dfn[cur]);
				}
				res[get<0>(T)] += get<1>(T) * sum;
			}
		}
	}
}
using namespace SMALL;
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) {
		scanf("%s", buf + 1); int len = strlen(buf + 1);
		for (int j = 1; j <= len; j++) s[i].pb(buf[j]);
		insert(s[i], i);
	}
	init(); init_big();
	for (int i = 1, l, r, k; i <= qu; i++) {
		scanf("%d%d%d", &l, &r, &k);
		if (id[k]) qv_big[k].pb(mt(l, r, i));
		else qv_sml[r].pb(mt(i, 1, k)), qv_sml[l - 1].pb(mt(i, -1, k));
	}
	solve_small(); solve_big();
	for (int i = 1; i <= qu; i++) printf("%lld\n", res[i]);
	return 0;
}