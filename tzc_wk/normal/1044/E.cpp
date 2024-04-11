// Created time: 2022/7/3 10:06:54
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
const int MAXN = 20;
vector<vector<int> > ans;
int n, m, a[MAXN + 2][MAXN + 2], ought[MAXN + 2][MAXN + 2];
void rotate() {
	static int tmp_a[MAXN + 2][MAXN + 2], tmp_ought[MAXN + 2][MAXN + 2];
	memset(tmp_a, 0, sizeof(tmp_a)); memset(tmp_ought, 0, sizeof(tmp_ought));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		tmp_a[j][i] = a[i][j], tmp_ought[j][i] = ought[i][j];
	swap(n, m);
	memset(a, 0, sizeof(a)); memset(ought, 0, sizeof(ought));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		a[i][j] = tmp_a[i][j], ought[i][j] = tmp_ought[i][j];
}
void opt(vector<pii> vec) {
	vector<int> A; for (pii p : vec) A.pb(a[p.fi][p.se]); ans.pb(A);
	static int b[MAXN + 2][MAXN + 2];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) b[i][j] = a[i][j];
	for (int i = 0; i < vec.size(); i++) b[vec[(i + 1) % vec.size()].fi][vec[(i + 1) % vec.size()].se] = a[vec[i].fi][vec[i].se];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = b[i][j];
}
void work(int v, int x, int y) {
	int nx = 0, ny = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == v) nx = i, ny = j;
	while (nx > x) {
		if (ny != m) opt(vector<pii>{mp(nx, ny), mp(nx - 1, ny), mp(nx - 1, ny + 1), mp(nx, ny + 1)});
		else opt(vector<pii>{mp(nx, ny), mp(nx - 1, ny), mp(nx - 1, ny - 1), mp(nx, ny - 1)});
		nx--;
	}
	while (nx < x) {
		if (ny != m) opt(vector<pii>{mp(nx, ny), mp(nx + 1, ny), mp(nx + 1, ny + 1), mp(nx, ny + 1)});
		else opt(vector<pii>{mp(nx, ny), mp(nx + 1, ny), mp(nx + 1, ny - 1), mp(nx, ny - 1)});
		nx++;
	}
	while (ny > y) opt(vector<pii>{mp(nx, ny), mp(nx, ny - 1), mp(nx + 1, ny - 1), mp(nx + 1, ny)}), ny--;
}
namespace Three_Times_Three {
	const int MAXC = 362880;
	vector<int> CYC[12] = {
	vector<int>{0, 1, 4, 3},
	vector<int>{3, 4, 7, 6},
	vector<int>{1, 2, 5, 4},
	vector<int>{4, 5, 8, 7},
	vector<int>{0, 1, 4, 7, 6, 3},
	vector<int>{1, 2, 5, 8, 7, 4},
	vector<int>{0, 1, 2, 5, 4, 3},
	vector<int>{3, 4, 5, 8, 7, 6},
	vector<int>{0, 1, 4, 5, 8, 7, 6, 3},
	vector<int>{0, 1, 2, 5, 8, 7, 4, 3},
	vector<int>{0, 1, 2, 5, 4, 7, 6, 3},
	vector<int>{1, 2, 5, 8, 7, 6, 3, 4}
	};
	bool vis[MAXC + 5];
	vector<vector<int> > pth[MAXC + 5];
	int calc(vector<int> vec) {
		int prd = 1, res = 0;
		for (int i = 8; ~i; i--) {
			int sum = 0;
			for (int j = i + 1; j < 9; j++) sum += vec[j] < vec[i];
			res += sum * prd; prd *= (9 - i);
		}
		return res;
	}
	void solve33() {
		queue<vector<int> > q; vector<int> st, ed;
		for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) st.pb(a[i][j]), ed.pb(ought[i][j]);
		q.push(st);
		while (!q.empty()) {
			vector<int> vec = q.front(); q.pop(); int ID = calc(vec);
			if (vec == ed) {for (auto v : pth[ID]) ans.pb(v); break;}
			for (int i = 0; i < 12; i++) {
				vector<int> tmp = vec;
				for (int j = 0; j < CYC[i].size(); j++) tmp[CYC[i][(j + 1) % CYC[i].size()]] = vec[CYC[i][j]];
				int nID = calc(tmp);
				if (!vis[nID]) {
					pth[nID] = pth[ID]; vector<int> trs;
					for (int x : CYC[i]) trs.pb(vec[x]);
					pth[nID].pb(trs); vis[nID] = 1;
					q.push(tmp);
				}
			}
		}
	}
} using namespace Three_Times_Three;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		scanf("%d", &a[i][j]), ought[i][j] = (i - 1) * m + j;
	while (n > 3 || m > 3) {
		if (n < m) rotate();
		auto deal2 = [&](int id) {
			work(ought[n][id + 1], 1, 1); work(ought[n][id], 2, 1);
			for (int i = 1; i <= n - 3; i++) opt(vector<pii>{mp(i, 1), mp(i + 1, 1), mp(i + 2, 1), mp(i + 2, 2), mp(i + 1, 2), mp(i, 2)});
			opt(vector<pii>{mp(n - 2, 1), mp(n - 1, 1), mp(n - 1, 2), mp(n - 2, 2)});
			for (int i = 1; i < id; i++) opt(vector<pii>{mp(n - 1, i), mp(n - 1, i + 1), mp(n - 1, i + 2), mp(n - 2, i + 2), mp(n - 2, i + 1), mp(n - 2, i)});
			opt(vector<pii>{mp(n - 1, id), mp(n - 1, id + 1), mp(n, id + 1), mp(n, id)});
			opt(vector<pii>{mp(n - 1, id), mp(n - 1, id + 1), mp(n, id + 1), mp(n, id)});
		};
		auto deal3 = [&](int id) {
			work(ought[n][id + 2], 1, 1); work(ought[n][id + 1], 2, 1); work(ought[n][id], 3, 1);
			for (int i = 1; i <= n - 4; i++) opt(vector<pii>{mp(i, 1), mp(i + 1, 1), mp(i + 2, 1), mp(i + 3, 1), mp(i + 3, 2), mp(i + 2, 2), mp(i + 1, 2), mp(i, 2)});
			opt(vector<pii>{mp(n - 3, 1), mp(n - 2, 1), mp(n - 1, 1), mp(n - 1, 2), mp(n - 2, 2), mp(n - 3, 2)});
			opt(vector<pii>{mp(n - 2, 1), mp(n - 1, 1), mp(n - 1, 2), mp(n - 1, 3), mp(n - 2, 3), mp(n - 2, 2)});
			for (int i = 1; i < id; i++) opt(vector<pii>{mp(n - 1, i), mp(n - 1, i + 1), mp(n - 1, i + 2), mp(n - 1, i + 3), mp(n - 2, i + 3), mp(n - 2, i + 2), mp(n - 2, i + 1), mp(n - 2, i)});
			opt(vector<pii>{mp(n - 1, id), mp(n - 1, id + 1), mp(n - 1, id + 2), mp(n, id + 2), mp(n, id + 1), mp(n, id)});
			opt(vector<pii>{mp(n - 1, id), mp(n - 1, id + 1), mp(n - 1, id + 2), mp(n, id + 2), mp(n, id + 1), mp(n, id)});
			opt(vector<pii>{mp(n - 1, id), mp(n - 1, id + 1), mp(n - 1, id + 2), mp(n, id + 2), mp(n, id + 1), mp(n, id)});
		};
		if (m % 2 == 0) {
			for (int i = 1; i <= m; i += 2) deal2(i);
		} else {
			for (int i = 1; i <= m - 3; i += 2) deal2(i);
			deal3(m - 2);
		}
		n--;
	}
	solve33();
	printf("%d\n", (int)ans.size());
	for (auto v : ans) {
		printf("%d", (int)v.size());
		for (int x : v) printf(" %d", x);
		printf("\n");
	}
	return 0;
}
/*
4 4
9 5 8 11
2 13 7 4
15 1 3 6
10 16 12 14
*/