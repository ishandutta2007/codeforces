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
const int MAXN = 1000;
int n;
struct point {
	int x, y;
	point() {x = y = 0;}
	point(int _x, int _y) {x = _x; y = _y;}
	point operator + (const point &rhs) {return point(x + rhs.x, y + rhs.y);}
	point operator - (const point &rhs) {return point(x - rhs.x, y - rhs.y);}
	ll operator | (const point &rhs) {return 1ll * x * rhs.y - 1ll * y * rhs.x;}
	ll operator ^ (const point &rhs) {return 1ll * x * rhs.x + 1ll * y * rhs.y;}
};
struct dat {point p; int col, id;} a[MAXN + 5];
bool cmp(dat A, dat B) {return (A.p.x ^ B.p.x) ? (A.p.x < B.p.x) : (A.p.y < B.p.y);}
ll area(point A, point B, point C) {return abs((B - A) | (C - A));}
struct tri {
	int A, B, C;
	tri() {A = B = C = 0;}
	tri(int _A = 0, int _B = 0, int _C = 0): A(_A), B(_B), C(_C) {}
	bool in(int id) {
		return area(a[A].p, a[B].p, a[id].p) + area(a[A].p, a[C].p, a[id].p) +
			   area(a[B].p, a[C].p, a[id].p) == area(a[A].p, a[B].p, a[C].p);
	}
	int gettyp() {
		if (a[A].col == a[B].col && a[B].col == a[C].col) return -1;
		static int cnt[2]; fill0(cnt);
		cnt[a[A].col]++; cnt[a[B].col]++; cnt[a[C].col]++;
		return (cnt[1] > cnt[0]);
	}
};
struct convex {
	vector<int> vec; // in counter-clockwise direction
	bool in(int x) {
		for (int i = 2; i < vec.size(); i++) if (tri(vec[0], vec[i - 1], vec[i]).in(x))
			return 1;
		return 0;
	}
} H;
bool on[MAXN + 5]; int f[MAXN + 5]; vector<pii> res;
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void con(int x, int y) {
	assert(a[x].col == a[y].col);
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		f[fx] = fy;
		res.pb(mp(a[x].id - 1, a[y].id - 1));
	} else cerr << "!!!\n";
}
void solve_tri(tri A, vector<int> pt) {
	if (pt.empty()) return; int id = pt[0];
//	printf("solve:"); for (int x : pt) printf(" %d", x); printf("\n");
	if (~A.gettyp()) {
		for (int x : pt) if (a[x].col == (A.gettyp() ^ 1))
			id = x;
	}
	if (a[A.A].col == a[id].col) con(A.A, id);
	else if (a[A.B].col == a[id].col) con(A.B, id);
	else if (a[A.C].col == a[id].col) con(A.C, id);
	else exit(-1);
	vector<int> vec1, vec2, vec3;
	for (int x : pt) if (x != id) {
		if (tri(A.A, A.B, id).in(x)) vec1.pb(x);
		else if (tri(A.B, A.C, id).in(x)) vec2.pb(x);
		else if (tri(A.C, A.A, id).in(x)) vec3.pb(x);
	}
	solve_tri(tri(A.A, A.B, id), vec1);
	solve_tri(tri(A.B, A.C, id), vec2);
	solve_tri(tri(A.C, A.A, id), vec3);
}
void solve_hull(convex h, vector<int> pt) {
	if (pt.empty()) return;
	static int cnt[2]; fill0(cnt);
	for (int i = 0; i < h.vec.size(); i++) cnt[a[h.vec[i]].col]++;
	int C = (cnt[0] == 1) ? 0 : 1, id = pt[0];
	for (int x : pt) if (a[x].col == C) id = x;
	for (int x : h.vec) if (a[x].col == a[id].col) {con(x, id); break;}
//	printf("! %d %d\n", C, id);
//	for (int x : pt) printf("%d ", x); printf("\n");
	static vector<int> bel[MAXN + 5];
	for (int i = 0; i < h.vec.size(); i++) bel[i].clear();
	for (int x : pt) if (x != id) {
		for (int j = 0; j < h.vec.size(); j++)
			if (tri(h.vec[j], h.vec[(j + 1) % h.vec.size()], id).in(x))
				bel[j].pb(x);
	}
	for (int i = 0; i < h.vec.size(); i++)
		solve_tri(tri(h.vec[i], h.vec[(i + 1) % h.vec.size()], id), bel[i]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].p.x, &a[i].p.y, &a[i].col), a[i].id = i;
	sort(a + 1, a + n + 1, cmp); static int stk[MAXN + 5]; int tp = 0;
	for (int i = 1; i <= n; i++) {
		while (tp > 1 && ((a[stk[tp - 1]].p - a[stk[tp]].p) | (a[i].p - a[stk[tp]].p)) >= 0) --tp;
		stk[++tp] = i;
	}
	for (int i = 1; i <= tp; i++) H.vec.pb(stk[i]);
	for (int i = 1; i <= n; i++) {
		while (tp > 1 && ((a[stk[tp - 1]].p - a[stk[tp]].p) | (a[i].p - a[stk[tp]].p)) <= 0) --tp;
		stk[++tp] = i;
	}
	for (int i = tp - 1; i > 1; i--) H.vec.pb(stk[i]);
	for (int id : H.vec) on[id] = 1;
	int pos = -1, cnt = 0;
	for (int i = 0; i < H.vec.size(); i++) if (a[H.vec[i]].col != a[H.vec[(i + 1) % H.vec.size()]].col)
		pos = (i + 1) % H.vec.size(), cnt++;
	if (cnt >= 4) return puts("Impossible"), 0;
	for (int i = 0; i < H.vec.size(); i++) if (a[H.vec[i]].col == a[H.vec[(i + 1) % H.vec.size()]].col)
		con(H.vec[i], H.vec[(i + 1) % H.vec.size()]);
	if (!~pos) {
		int id = -1;
		for (int i = 1; i <= n; i++) if (!on[i] && a[i].col != a[H.vec[0]].col)
			id = i;
		if (!~id) {
			static vector<int> bel[MAXN + 5];
			for (int i = 1; i <= n; i++) if (!on[i]) {
				for (int j = 2; j < H.vec.size(); j++)
					if (tri(H.vec[j - 1], H.vec[j], H.vec[0]).in(i))
						bel[j].pb(i);
			}
			for (int j = 2; j < H.vec.size(); j++)
				solve_tri(tri(H.vec[j - 1], H.vec[j], H.vec[0]), bel[j]);
		} else {
			static vector<int> bel[MAXN + 5];
			for (int i = 1; i <= n; i++) if (!on[i] && i != id) {
				for (int j = 0; j < H.vec.size(); j++)
					if (tri(H.vec[j], H.vec[(j + 1) % H.vec.size()], id).in(i))
						bel[j].pb(i);
			}
			for (int j = 0; j < H.vec.size(); j++)
				solve_tri(tri(H.vec[j], H.vec[(j + 1) % H.vec.size()], id), bel[j]);
		}
	} else {
		int L = pos, R = pos;
		while (a[H.vec[R]].col == a[H.vec[L]].col) R = (R + 1) % H.vec.size();
		if (R == (L + 1) % H.vec.size() || L == (R + 1) % H.vec.size()) {
			vector<int> vec;
			for (int i = 1; i <= n; i++) if (!on[i]) vec.pb(i);
			solve_hull(H, vec);
		} else {
			convex H1, H2;
			for (int i = L; i != (R + 1) % H.vec.size(); i = (i + 1) % H.vec.size())
				H1.vec.pb(H.vec[i]);
			for (int i = R; i != (L + 1) % H.vec.size(); i = (i + 1) % H.vec.size())
				H2.vec.pb(H.vec[i]);
			vector<int> vec1, vec2;
			for (int i = 1; i <= n; i++) if (!on[i]) {
				if (H1.in(i)) vec1.pb(i);
				else vec2.pb(i);
			}
			solve_hull(H1, vec1); solve_hull(H2, vec2);
		}
	}
	printf("%d\n", res.size());
	for (pii p : res) printf("%d %d\n", p.fi, p.se);
	return 0;
}
/*
11
0 0 0
0 10000 0
10000 0 1
10000 10000 0
5001 4994 0
2499 2501 0
7503 7499 0
4010 5995 0
6011 3987 0
1015 5003 0
5043 5007 0
*/