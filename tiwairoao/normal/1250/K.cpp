#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int MOD = 998244353;

inline int add(int x, int y) {return (x + y >= MOD ? x + y - MOD : x + y);}
inline int sub(int x, int y) {return (x - y < 0 ? x - y + MOD : x - y);}
inline int mul(int x, int y) {return 1LL * x * y % MOD;}

int pow_mod(int b, int p) {
	int ret = 1;
	for(int i=p;i;i>>=1,b=mul(b,b))
		if( i & 1 ) ret = mul(ret, b);
	return ret;
}

const int INV100 = pow_mod(100, MOD - 2);

struct matrix{
	int m[2][2];
	matrix() {m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;}
	friend matrix operator * (matrix A, matrix B) {
		matrix C;
		C.m[0][0] = add(mul(A.m[0][0], B.m[0][0]), mul(A.m[0][1], B.m[1][0]));
		C.m[0][1] = add(mul(A.m[0][0], B.m[0][1]), mul(A.m[0][1], B.m[1][1]));
		C.m[1][0] = add(mul(A.m[1][0], B.m[0][0]), mul(A.m[1][1], B.m[1][0]));
		C.m[1][1] = add(mul(A.m[1][0], B.m[0][1]), mul(A.m[1][1], B.m[1][1]));
		return C;
	}
};

matrix M[MAXN + 5]; int p[MAXN + 5];
matrix get(int i, int type) {
	if( type == 1 ) M[i].m[0][1] = 0;
	else if( type == 2 ) M[i].m[0][0] = M[i].m[0][1] = 0;
	else if( type == 3 ) M[i].m[1][0] = M[i].m[1][1] = 0;
	return M[i];
}

struct segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*MAXN + 5], ri[4*MAXN + 5]; matrix s[4*MAXN + 5];
	void pushup(int x) {s[x] = s[rch] * s[lch];}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r;
		if( l == r ) {
			s[x] = get(l, 0);
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		pushup(x);
	}
	void modify(int x, int p, matrix k) {
		if( le[x] == ri[x] ) {
			s[x] = k;
			return ;
		}
		int m = (le[x] + ri[x]) >> 1;
		modify(p <= m ? lch : rch, p, k);
		pushup(x);
	}
}T;

struct node{
	int x, v, i, type; node() {}
	node(int _x, int _v, int _i, int _t) : x(_x), v(_v), i(_i), type(_t) {}
	friend bool operator < (node a, node b) {
//		return 1.0 * a.x / a.v < 1.0 * b.x / b.v;
		return 1LL*a.x*b.v < 1LL*b.x*a.v;
	}
}a[2*MAXN + 5];

int x[MAXN + 5], v[MAXN + 5];

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d", &x[i], &v[i], &p[i]), p[i] = mul(p[i], INV100);
		M[i].m[0][0] = M[i].m[0][1] = sub(1, p[i]);
		M[i].m[1][0] = M[i].m[1][1] = p[i];
	}
	T.build(1, 1, n);
	int cnt = 0;
	for(int i=1;i<n;i++) {
		a[++cnt] = node(x[i+1] - x[i], v[i+1] + v[i], i+1, 1);
		if( v[i+1] > v[i] ) a[++cnt] = node(x[i+1] - x[i], v[i+1] - v[i], i+1, 2);
		if( v[i+1] < v[i] ) a[++cnt] = node(x[i+1] - x[i], v[i] - v[i+1], i, 3);
	}
	sort(a + 1, a + cnt + 1);
	int ans = 0, pro = 0;
	for(int i=1;i<=cnt;i++) {
		T.modify(1, a[i].i, get(a[i].i, a[i].type));
		int t = mul(a[i].x, pow_mod(a[i].v, MOD - 2));
		int p = sub(sub(1, add(T.s[1].m[0][0], T.s[1].m[1][0])), pro);
		ans = add(ans, mul(p, t));
		pro = sub(1, add(T.s[1].m[0][0], T.s[1].m[1][0]));
	}
	printf("%d\n", ans);
}