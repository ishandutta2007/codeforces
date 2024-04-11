//#define DEBUG_MODE
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
//#ifndef DEBUG_MODE
//#include "it.h"
//#else
//int query(int x);
//#endif
int query(int x) {
	printf("? %d\n", x); fflush(stdout);
	int v; scanf("%d", &v); if (v < 0) exit(0);
	return v;
}
const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;
int n, deg[MAXN + 5], fa[MAXN + 5];
int dp[MAXN + 5], dp_out[MAXN + 5];
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
void dfs1(int x, int f) {
	vector<int> vec; fa[x] = f;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs1(y, x); vec.pb(dp[y]);
	}
	sort(vec.begin(), vec.end(), greater<int>()); dp[x] = 1;
	for (int i = 0; i < vec.size(); i++) chkmax(dp[x], vec[i] + i);
}
void dfs2(int x, int f) {
	vector<pii> vec;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) vec.pb(mp(dp_out[x], -1));
		else vec.pb(mp(dp[y], y));
	}
	sort(vec.begin(), vec.end(), greater<pii>());
	for (pii p : vec) if (~p.se) dp_out[p.se] = 1;
	int mx = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (~vec[i].se) chkmax(dp_out[vec[i].se], mx);
		chkmax(mx, vec[i].fi + i);
	}
	mx = 0;
	for (int i = (int)(vec.size()) - 1; ~i; i--) {
		if (~vec[i].se) chkmax(dp_out[vec[i].se], mx);
		chkmax(mx, vec[i].fi + i - 1);
	}
	for (pii p : vec) if (~p.se) dfs2(p.se, x);
}
vector<int> init(int N, vector<pii> e) {
	n = N;
	for (pii p : e) adde(p.fi, p.se), adde(p.se, p.fi);
	if (n == 1) return vector<int>{0};
	dfs1(1, 0); dfs2(1, 0);
	vector<int> vec;
//	for (int i = 1; i <= n; i++) printf("%d%c", dp[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) {
		vector<int> tmp;
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e];
			if (y == fa[i]) tmp.pb(dp_out[i]);
			else tmp.pb(dp[y]);
		}
		int mx = tmp[0];
		sort(tmp.begin(), tmp.end(), greater<int>());
		for (int j = 1; j < tmp.size(); j++) chkmax(mx, tmp[0] + tmp[j] + j - 1);
//		printf("%d\n", mx);
		vec.pb(mx);
	}
	return vec;
}
int calc(int x, int f) {
//	printf("calc %d %d\n", x, f);
	vector<pii> vec; bool is = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		vec.pb(mp(dp[y], y)); is = 0;
	}
	sort(vec.begin(), vec.end(), greater<pii>());
	for (pii p : vec) {
		int y = p.se, z = calc(y, x);
		if (z != x) return z;
	}
	return (is) ? query(x) : x; 
}
pii solve(int R) {
	if (n == 1) return mp(1, 1);
	dfs1(R, 0); vector<int> res; vector<pii> vec;
	for (int e = hd[R]; e; e = nxt[e]) vec.pb(mp(dp[to[e]], to[e]));
	sort(vec.begin(), vec.end(), greater<pii>());
	for (pii p : vec) {
		int z = calc(p.se, R);
		if (z != R) res.pb(z);
		if (res.size() == 2) break;
	}
	while (res.size() < 2) res.pb(R);
	return mp(res[0], res[1]);
}
/*
#ifdef DEBUG_MODE
namespace grader{
	#define pb push_back
	#define x first
	#define y second
	const int N=200005;
	int n, q, mn[N][20], dfn[N], seq[N], dep[N], lg[N], cnt;
	int a, b, x;
	vector<int> e[N], ans;
	void dfs(int u, int fa)
	{
		dfn[u]=++cnt;
		seq[cnt]=u;
		dep[u]=dep[fa]+1;
		for(int v:e[u]) if(v!=fa)
		{
			dfs(v, u);
			seq[++cnt]=u;
		}
	}
	inline int gmn(int x, int y) { return dep[x]<dep[y]?x:y; }
	void initl(void)
	{
		for(int i=2; i<=cnt; i<<=1) ++lg[i];
		for(int i=1; i<=cnt; ++i) lg[i]+=lg[i-1];
		for(int i=1; i<=cnt; ++i) mn[i][0]=seq[i];
		for(int l=1; (1<<l)<=cnt; ++l) for(int i=1; i+(1<<l)-1<=cnt; ++i)
			mn[i][l]=gmn(mn[i][l-1], mn[i+(1<<(l-1))][l-1]);
	}
	inline int lca(int x, int y)
	{
		x=dfn[x], y=dfn[y];
		if(x>y) std::swap(x, y);
		int l=lg[y-x+1];
		return gmn(mn[x][l], mn[y-(1<<l)+1][l]);
	}
	int query(int v)
	{
		++cnt;
		if(cnt>ans[x-1]) { puts("WA_Exceed"); exit(0); }
		int l=lca(a, b);
		if(lca(v, l)==v) return l;
		return l^lca(a, v)^lca(b, v);
	}
	int main()
	{
		scanf("%d%d", &n, &q);
		vector<pair<int, int> > re;
		for(int i=1, x, y; i<n; ++i)
		{
			scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
			re.pb({x, y});
		}
		ans.resize(n);
		for(int i=1; i<=n; ++i) scanf("%d", &ans[i-1]);
		dfs(1, 0);
		initl();
		auto vec=init(n, re);
		if(vec.size()!=ans.size()) return puts("WA_size"), 0;
		for(int i=0; i<ans.size(); ++i) if(vec[i]>ans[i]) return puts("WA_answer"), 0;
		for(int i=1; i<=q; ++i)
		{
			scanf("%d%d%d", &x, &a, &b);
			cnt=-1;
			x=query(x);
			cnt=0;
			if(a>b) std::swap(a, b);
			pair<int, int> t=solve(x);
			if(t.x>t.y) std::swap(t.x, t.y);
			if(t.x!=a||t.y!=b)
			{
//				printf("find %d %d %d %d %d %d\n", i, x, a, b, t.x, t.y);
				return puts("WA_find"), 0;
			}
			if(vec[x-1]<cnt) return puts("WA_Exceed"), 0;
//			printf("Cnt: %d %d\n", vec[x-1], cnt);
		}
		puts("AC");
		return 0;
	}
	#undef x
	#undef y
}
int query(int x)
{
	int ret=grader::query(x);
//	printf("query %d %d\n", x, ret);
	return ret;
}
int main()
{
	grader::main();
	return 0;
}
#endif
*/
int main() {
	int n; scanf("%d", &n); vector<pii> E;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), E.pb(mp(u, v));
	vector<int> tt = init(n, E); int mx = 0;
	for (int x : tt) chkmax(mx, x);
	printf("%d\n", mx); fflush(stdout);
	int R; scanf("%d", &R);
	pii pp = solve(R);
	printf("! %d %d\n", pp.fi, pp.se);
	fflush(stdout);
	return 0;
}