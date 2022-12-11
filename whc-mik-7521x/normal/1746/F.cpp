#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

mt19937 rnd(time(NULL));
const int maxn = 1e6 + 10;
int n, m, q, a[maxn], tmp[maxn], A[maxn], ans[maxn], vis[40][maxn];
struct BIT {
	int c[maxn];
	void clr() { memset(c, 0, sizeof c); }
	void add(int x, int y) { for (; x <= n; x += x & -x) c[x] += y; }
	int ask(int x) {
		int res = 0;
		for (; x > 0; x &= x - 1) res += c[x];
		return res;
	}
	int ask(int l, int r) { return ask(r) - ask(l - 1); }
} tr;
struct node {
	int op, l, r, x;
} b[maxn];
void test(int t) {
	tr.clr();
	for (int i = 1; i <= n; ++i) {
		if (vis[t][a[i]]) tr.add(i, 1);
		tmp[i] = a[i];
	}
	for (int i = 1; i <= q; ++i) {
		if (b[i].op == 1) {
			if (vis[t][tmp[b[i].l]]) tr.add(b[i].l, -1);
			if (vis[t][b[i].x]) tr.add(b[i].l, 1);
			tmp[b[i].l] = b[i].x;
		}
		else ans[i] &= (tr.ask(b[i].l, b[i].r) % b[i].x == 0);
	}
}

int main() {
	read(n, q);
	for (int i = 1; i <= n; ++i) read(a[i]), A[++m] = a[i];
	for (int i = 1; i <= q; ++i) {
		read(b[i].op);
		if (b[i].op == 1) read(b[i].l, b[i].x), A[++m] = b[i].x;
		else read(b[i].l, b[i].r, b[i].x), ans[i] = 1;
	}
	sort(A + 1, A + m + 1), m = unique(A + 1, A + m + 1) - A - 1;
	for (int i = 1; i <= n; ++i) a[i] = lower_bound(A + 1, A + m + 1, a[i]) - A;
	for (int i = 1; i <= q; ++i) if (b[i].op == 1) b[i].x = lower_bound(A + 1, A + m + 1, b[i].x) - A;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= 30; ++j) vis[j][i] = rnd() & 1;
	for (int t = 1; t <= 30; ++t) test(t);
	for (int i = 1; i <= q; ++i) if (b[i].op == 2) write(ans[i] ? "YES\n" : "NO\n");
	return 0;
}