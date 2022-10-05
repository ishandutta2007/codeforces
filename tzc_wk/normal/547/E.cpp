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
const int MAXL = 2e5;
const int MAXQ = 5e5;
const int ALPHA = 26;
int n, qu; char buf[MAXL + 5];
int ch[MAXL + 5][ALPHA + 2], ncnt, fail[MAXL + 5], ed[MAXL + 5];
void insert(char *s, int id) {
	int len = strlen(s + 1), cur = 0;
	for (int i = 1; i <= len; i++) {
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
int hd[MAXL + 5], to[MAXL + 5], nxt[MAXL + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int dfn[MAXL + 5], edt[MAXL + 5], tim = 0;
void dfs0(int x) {
	dfn[x] = ++tim;
	for (int e = hd[x]; e; e = nxt[e]) dfs0(to[e]);
	edt[x] = tim;
}
vector<tuple<int, int, int> > qv[MAXL + 5];
string s[MAXL + 5];
int res[MAXQ + 5];
struct fenwick {
	int t[MAXL + 5];
	void add(int x, int v) {for (int i = x; i <= ncnt + 1; i += (i & (-i))) t[i] += v;}
	int query(int x) {int ret = 0; for (int i = x; i; i -= (i & (-i))) ret += t[i]; return ret;}
	int query(int l, int r) {return query(r) - query(l - 1);}
} T;
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 1; i <= n; i++) {
		scanf("%s", buf + 1); int len = strlen(buf + 1);
		for (int j = 1; j <= len; j++) s[i].pb(buf[j]);
		insert(buf, i);
	}
	getfail();
	for (int i = 1; i <= ncnt; i++) adde(fail[i], i); dfs0(0);
	for (int i = 1, l, r, k; i <= qu; i++) {
		scanf("%d%d%d", &l, &r, &k);
		qv[r].pb(mt(k, 1, i)); qv[l - 1].pb(mt(k, -1, i));
	}
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 0; j < s[i].size(); j++) cur = ch[cur][s[i][j] - 'a'], T.add(dfn[cur], 1);
		for (auto t : qv[i]) res[get<2>(t)] += get<1>(t) * T.query(dfn[ed[get<0>(t)]], edt[ed[get<0>(t)]]);
	}
	for (int i = 1; i <= qu; i++) printf("%d\n", res[i]);
	return 0;
}