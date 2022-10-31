#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define pr make_pair
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int N = 200000;
const ll INF = ll(1E18);

struct segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5]; ll mn[4*N + 5], tg[4*N + 5];
	void addtag(int x, ll k) {tg[x] += k, mn[x] += k;}
	void pushdown(int x) {
		if( tg[x] ) addtag(lch, tg[x]), addtag(rch, tg[x]);
		tg[x] = 0;
	}
	void pushup(int x) {mn[x] = min(mn[lch], mn[rch]);}
	void build(const ll *A, int x, int l, int r) {
		le[x] = l, ri[x] = r, tg[x] = 0;
		if( l == r ) {
			mn[x] = A[l];
			return ;
		}
		int m = (l + r) >> 1;
		build(A, lch, l, m), build(A, rch, m + 1, r), pushup(x);
	}
	void update(int x, int l, int r, ll k) {
		if( l > ri[x] || r < le[x] ) return ;
		if( l <= le[x] && ri[x] <= r ) {
			addtag(x, k);
			return ;
		}
		pushdown(x);
		update(lch, l, r, k), update(rch, l, r, k);
		pushup(x);
	}
}A, B;

vector<pii>G[N + 5];
ll a[N + 5], b[N + 5], f[N + 5];
int main() {
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<n;i++) scanf("%lld%lld", &a[i], &b[i + 1]);
	for(int i=1,x,y,z;i<=m;i++) {
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back(pr(y, z));
	}
	
	B.build(b, 1, 1, n);
	for(int i=1;i<=n;i++) {
		for(auto x : G[i])
			B.update(1, 1, x.fi, x.se);
		f[i] = a[i] + B.mn[1];
	}
	
	A.build(f, 1, 1, n), printf("%lld\n", A.mn[1]);
	for(int i=1,v,w;i<=q;i++) {
		scanf("%d%d", &v, &w);
		A.update(1, v, v, w - a[v]), printf("%lld\n", A.mn[1]);
		a[v] = w;
	}
}