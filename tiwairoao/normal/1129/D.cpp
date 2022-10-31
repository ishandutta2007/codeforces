#include <cstdio>
#include <algorithm>
using namespace std;

#define rep(i, x, n) for(int i=x;i<=n;i++)

const int B = 320;
const int N = 100000;
const int P = 998244353;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int) (1LL * x * y % P);}

int n, k;

int le[N + 5], ri[N + 5], id[N + 5], bcnt;
void build() {
	rep(i, 1, n) {
		if( (i - 1) % B == 0 )
			le[++bcnt] = i;
		ri[bcnt] = i, id[i] = bcnt;
	}
}

int c[N + 5], dp[N + 5];
int s[B + 5][B + 5], tg[B + 5], lb[B + 5];
void pushtag(int x) {
	if( !tg[x] ) return ;
	rep(i, le[x], ri[x]) c[i] += tg[x];
	tg[x] = 0;
}
void rebuild(int x) {
	lb[x] = 10*N + 5;
	rep(i, 0, B) s[x][i] = 0;
	rep(i, le[x], ri[x]) lb[x] = min(lb[x], c[i]);
	rep(i, le[x], ri[x]) s[x][c[i]-lb[x]] = add(s[x][c[i]-lb[x]], dp[i - 1]);
	rep(i, 1, B) s[x][i] = add(s[x][i], s[x][i - 1]);
}
void add(int l, int r, int d) {
	int p = id[l], q = id[r];
	if( p == q ) {
		pushtag(p); rep(i, l, r) c[i] += d; rebuild(p);
	} else {
		pushtag(p); rep(i, l, ri[p]) c[i] += d; rebuild(p);
		rep(i, p + 1, q - 1) tg[i] += d;
		pushtag(q); rep(i, le[q], r) c[i] += d; rebuild(q);
	}
}
int query() {
	int ret = 0;
	rep(i, 1, bcnt) {
		if( lb[i] + tg[i] <= k ) {
			if( lb[i] + tg[i] + B <= k )
				ret = add(ret, s[i][B]);
			else ret = add(ret, s[i][k - lb[i] - tg[i]]);
		}
	}
	return ret;
}

int a[N + 5], b[N + 5], lst[N + 5];
int main() {
	scanf("%d%d", &n, &k), build();
	rep(i, 1, n) scanf("%d", &a[i]), lst[i] = b[a[i]], b[a[i]] = i;
	
	dp[0] = 1, rebuild(1);
	rep(i, 1, n) {
		add(lst[i] + 1, i, 1);
		if( lst[i] ) add(lst[lst[i]] + 1, lst[i], -1);
		dp[i] = query(), rebuild(id[i + 1]);
	}
	printf("%d\n", dp[n]);
}