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
const int MAXN = 1e5;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, x[MAXN + 5], v[MAXN + 5], p[MAXN + 5], iv100 = qpow(100, MOD - 2);
bool ban[MAXN + 5][2][2];
struct mat {
	int a[2][2];
	int* operator [](int x) {return a[x];}
	mat() {memset(a, 0, sizeof(a));}
	mat operator + (const mat &rhs) {
		mat res;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
			res.a[i][j] = (a[i][j] + rhs.a[i][j]) % MOD;
		return res;
	}
};
mat merge(mat x, mat y, int z) {
	mat v;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++)
			if (!ban[z][j][p])
				v[i][q] = (v[i][q] + 1ll * x[i][j] * y[p][q]) % MOD;
	return v;
}
struct node {int l, r; mat val;} s[MAXN * 4 + 5];
void pushup(int k) {s[k].val = merge(s[k << 1].val, s[k << 1 | 1].val, s[k << 1].r);}
void build(int k, int l, int r) {
	s[k].l = l; s[k].r = r;
	if (l == r) {
		s[k].val[0][0] = (1 - p[l] + MOD) % MOD;
		s[k].val[1][1] = p[l]; return;
	}
	int mid = l + r >> 1; build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
mat query(int k, int l, int r) {
	if (l <= s[k].l && s[k].r <= r) return s[k].val;
	int mid = s[k].l + s[k].r >> 1;
	if (r <= mid) return query(k << 1, l, r);
	else if (l > mid) return query(k << 1 | 1, l, r);
	else return merge(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r), mid);
}
void banpos(int k, int x, int p, int q) {
	if (s[k].l == s[k].r) return ban[x][p][q] = 1, void();
	int mid = s[k].l + s[k].r >> 1;
	(x <= mid) ? banpos(k << 1, x, p, q) : banpos(k << 1 | 1, x, p, q);
	pushup(k);
}
int get(int x, int typ) {return (typ == 1) ? p[x] : (1 - p[x] + MOD) % MOD;}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &v[i], &p[i]), p[i] = 1ll * p[i] * iv100 % MOD;
	build(1, 1, n); vector<tuple<double, int, int, int, int> > vec;
	for (int i = 1; i < n; i++) {
		vec.pb(mt(1.0 * (x[i + 1] - x[i]) / (v[i] + v[i + 1]), i, 1, 0, 1ll * (x[i + 1] - x[i]) * qpow(v[i] + v[i + 1], MOD - 2) % MOD));
		if (v[i] > v[i + 1]) vec.pb(mt(1.0 * (x[i + 1] - x[i]) / (v[i] - v[i + 1]), i, 1, 1, 1ll * (x[i + 1] - x[i]) * qpow(v[i] - v[i + 1], MOD - 2) % MOD));
		if (v[i] < v[i + 1]) vec.pb(mt(1.0 * (x[i + 1] - x[i]) / (v[i + 1] - v[i]), i, 0, 0, 1ll * (x[i + 1] - x[i]) * qpow(v[i + 1] - v[i], MOD - 2) % MOD));
	}
	sort(vec.begin(), vec.end()); int res = 0;
	for (int i = 0; i < vec.size(); i++) {
		int prd = 1, id = get<1>(vec[i]), X = get<2>(vec[i]), Y = get<3>(vec[i]);
		mat d = query(1, 1, id);
		prd = 1ll * prd * (d.a[0][X] + d.a[1][X]) % MOD;
		d = query(1, id + 1, n);
		prd = 1ll * prd * (d.a[Y][0] + d.a[Y][1]) % MOD;
		banpos(1, id, X, Y);
		res = (res + 1ll * prd * get<4>(vec[i])) % MOD;
	}
	printf("%d\n", res);
	return 0;
}
/*
3
1 1 80
3 2 50
6 1 0
*/