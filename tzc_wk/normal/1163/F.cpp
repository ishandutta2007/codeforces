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
const int MAXN = 4e5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, qu, hd[MAXN + 5], to[MAXN * 2 + 5], val[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 1;
void adde(int u, int v, int w) {to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;}
struct edge {int u, v, w;} e[MAXN + 5];
ll d1[MAXN + 5], dn[MAXN + 5]; int p1[MAXN + 5], pn[MAXN + 5];
bool onp[MAXN + 5], onpe[MAXN + 5]; int id[MAXN + 5], bel[MAXN + 5];
bool vis[MAXN + 5];
void dijkstra(int s, ll *dis, int *pre) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 63, sizeof(d1));
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
	q.push(mp(dis[s] = 0, s));
	while (!q.empty()) {
		pair<ll, int> p = q.top(); q.pop();
		int x = p.se; if (vis[x]) continue;
		vis[x] = 1;
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = val[e];
			if (dis[y] > dis[x] + z) {
				dis[y] = dis[x] + z; pre[y] = e;
				q.push(mp(dis[y], y));
			}
		}
	}
}
vector<ll> ins[MAXN + 5], del[MAXN + 5];
ll mn[MAXN + 5];
int _hd[MAXN + 5], _nxt[MAXN + 5], _to[MAXN + 5], _ec = 0;
void _adde(int u, int v) {_to[++_ec] = v; _nxt[_ec] = _hd[u]; _hd[u] = _ec;}
void dfs(int x, int f) {
	if(onp[x]) bel[x] = id[x];
	else bel[x] = bel[f];
//	printf("%d %d\n", x, bel[x]);
	for (int e = _hd[x]; e; e = _nxt[e]) dfs(_to[e], x);
}
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w); adde(v, u, w);
		e[i] = {u, v, w};
	}
	dijkstra(1, d1, p1); dijkstra(n, dn, pn); vector<int> seq;
	for (int i = n; i != 1; i = to[p1[i] ^ 1]) {
		onpe[p1[i] >> 1] = 1, onp[i] = 1, seq.pb(i);
	}
	onp[1] = 1; seq.pb(1); reverse(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++) id[seq[i]] = i;
	for (int i = 2; i <= n; i++) _adde(to[p1[i] ^ 1], i);
	dfs(1, 0);
	for (int i = 1; i <= m; i++) if (!onpe[i]) {
		ll nwd = min(d1[e[i].u] + dn[e[i].v], d1[e[i].v] + dn[e[i].u]) + e[i].w;
		int l = bel[e[i].u], r = bel[e[i].v];
		if (l > r) swap(l, r); ins[l].pb(nwd); del[r].pb(nwd);
	}
	multiset<ll> st; st.insert(INF);
	for (int i = 0; i < seq.size(); i++) {
		for (ll x : ins[i]) st.insert(x);
		for (ll x : del[i]) st.erase(st.find(x));
		mn[i] = *st.begin();
//		printf("%d %lld\n", i, mn[i]);
	}
	while (qu--) {
		int x, v; scanf("%d%d", &x, &v);
		if (!vis[e[x].u]) printf("%lld\n", d1[n]);
		else if (!onpe[x])
			printf("%lld\n", min(d1[n], min(d1[e[x].u] + dn[e[x].v], d1[e[x].v] + dn[e[x].u]) + v));
		else printf("%lld\n", min(mn[min(id[e[x].u], id[e[x].v])],
		min(d1[e[x].u] + dn[e[x].v], d1[e[x].v] + dn[e[x].u]) + v));
	}
	return 0;
}
/*
4 2 1
1 4 1
2 3 1
2 100
*/