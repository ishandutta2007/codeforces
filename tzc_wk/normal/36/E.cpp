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
const int MAXN = 1e4;
const int MAXM = 2e4;
int n, m, hd[MAXN + 5], to[MAXM + 15], nxt[MAXM + 15], ec = 1, deg[MAXN + 5];
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
bool vis[MAXN + 5]; int cmp = 0;
void dfs(int x) {
	if (vis[x]) return; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {int y = to[e]; dfs(y);}
}
namespace TWO {
	bool vis[MAXN + 5]; vector<int> pt;
	void dfs(int x) {
		if (vis[x]) return; vis[x] = 1; pt.pb(x);
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e]; dfs(y);
		}
	}
	vector<int> pth[3], E;
	bool vise[MAXN + 10];
	void circuit(int x) {
		for (int &e = hd[x]; e; e = nxt[e]) if (!vise[e >> 1]) {
			int ee = e >> 1; vise[ee] = 1; circuit(to[e]); E.pb(ee);
		}
	}
	void solve() {
		memset(vis, 0, sizeof(vis)); int pth_cnt = 0;
		for (int i = 1; i <= n; i++) if (!vis[i] && hd[i]) {
			pt.clear(); dfs(i); vector<int> deg1;
			for (int x : pt) if (deg[x] & 1) deg1.pb(x);
			if (deg1.size() >= 4) return puts("-1"), void();
			else if (deg1.size() == 2) {
				adde(deg1[0], deg1[1]); adde(deg1[1], deg1[0]);
				E.clear(); circuit(pt[0]); int pos = 0;
				for (int j = 0; j < E.size(); j++) if (E[j] == (ec >> 1)) pos = j;
				pth_cnt++;
				for (int j = 1; j < E.size(); j++) pos = (pos + 1) % E.size(), pth[pth_cnt].pb(E[pos]);
			} else {E.clear(); circuit(pt[0]); pth_cnt++; pth[pth_cnt] = E;}
		}
		for (int i = 1; i <= 2; i++) {
			printf("%d\n", (int)pth[i].size());
			for (int x : pth[i]) printf("%d ", x); printf("\n");
		}
	}
}
namespace ONE {
	bool vis[MAXN + 5]; vector<int> pt;
	void dfs(int x) {
		if (vis[x]) return; vis[x] = 1; pt.pb(x);
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e]; dfs(y);
		}
	}
	vector<int> pth[3], E;
	bool vise[MAXN + 10];
	void circuit(int x) {
		for (int &e = hd[x]; e; e = nxt[e]) if (!vise[e >> 1]) {
			int ee = e >> 1; vise[ee] = 1; circuit(to[e]); E.pb(ee);
		}
	}
	void solve() {
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) if (!vis[i] && hd[i]) {
			pt.clear(); dfs(i); vector<int> deg1;
			for (int x : pt) if (deg[x] & 1) deg1.pb(x);
			if (deg1.size() >= 6) return puts("-1"), void();
			else if (deg1.size() == 4) {
				int E1, E2;
				adde(deg1[0], deg1[1]); adde(deg1[1], deg1[0]); E1 = ec >> 1;
				adde(deg1[2], deg1[3]); adde(deg1[3], deg1[2]); E2 = ec >> 1;
				E.clear(); circuit(pt[0]); int pos1 = 0, pos2 = 0;
				for (int j = 0; j < E.size(); j++) {
					if (E[j] == E1) pos1 = j;
					if (E[j] == E2) pos2 = j;
				}
				for (int j = (pos1 + 1) % E.size(); j != pos2; j = (j + 1) % E.size()) pth[1].pb(E[j]);
				for (int j = (pos2 + 1) % E.size(); j != pos1; j = (j + 1) % E.size()) pth[2].pb(E[j]);
			} else if (deg1.size() == 2) {
				adde(deg1[0], deg1[1]); adde(deg1[1], deg1[0]);
				E.clear(); circuit(pt[0]); int pos = 0;
				for (int j = 0; j < E.size(); j++) if (E[j] == (ec >> 1))
					pos = j;
				pth[1].pb(E[(pos + 1) % E.size()]);
				for (int j = (pos + 2) % E.size(); j != pos; j = (j + 1) % E.size())
					pth[2].pb(E[j]);
			} else {
//				puts("-2");
				E.clear(); circuit(pt[0]); pth[1].pb(E[0]);
				for (int j = 1; j < E.size(); j++) pth[2].pb(E[j]);
			}
		}
		for (int i = 1; i <= 2; i++) {
			printf("%d\n", (int)pth[i].size());
			for (int x : pth[i]) printf("%d ", x); printf("\n");
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &m); n = MAXN;
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v); adde(u, v); adde(v, u);
		deg[u]++; deg[v]++;
	}
	if (m == 1) return puts("-1"), 0;
	for (int i = 1; i <= n; i++) if (!vis[i] && hd[i]) cmp++, dfs(i);
	if (cmp >= 3 || !cmp) return puts("-1"), 0;
	if (cmp == 2) TWO :: solve();
	if (cmp == 1) ONE :: solve();
	return 0;
}