#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 500000;

struct type{
	int mx, cnt;
	friend type operator + (const type &a, const type &b) {
		type c; c.mx = max(a.mx, b.mx), c.cnt = 0;
		if( c.mx == a.mx ) c.cnt += a.cnt;
		if( c.mx == b.mx ) c.cnt += b.cnt;
		return c;
	}
};

int s[N + 5];
namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5]; type t[4*N + 5];
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r;
		if( l == r ) {
			t[x] = (type){s[l], 1};
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r), t[x] = t[lch] + t[rch];
	}
	type query(int x, int l, int r) {
		if( l > ri[x] || r < le[x] ) return (type){-N-5, 1};
		if( l <= le[x] && ri[x] <= r ) return t[x];
		return query(lch, l, r) + query(rch, l, r);
	}
}

namespace sam{
	int ch[2][2*N + 5], fa[2*N + 5], len[2*N + 5];
	int ncnt, root, lst;
	void init() {ncnt = root = lst = 1;}
	int clone(int q) {
		int nq = (++ncnt);
		fa[nq] = fa[q], ch[0][nq] = ch[0][q], ch[1][nq] = ch[1][q];
		return nq;
	}
	int extend(int c) {
		int p = lst, cur = (++ncnt); len[cur] = len[lst] + 1, lst = cur;
		while( p && !ch[c][p] ) ch[c][p] = cur, p = fa[p];
		if( !p ) fa[cur] = root;
		else {
			int q = ch[c][p];
			if( len[p] + 1 == len[q] ) fa[cur] = q;
			else {
				int nq = clone(q); len[nq] = len[p] + 1;
				fa[q] = fa[cur] = nq;
				while( p && ch[c][p] == q ) ch[c][p] = nq, p = fa[p];
			}
		}
		return cur;
	}
}

int stk[N + 5], tp; char str[N + 5];
int main() {
	int n; scanf("%d%s", &n, str + 1);
	for(int i=1;i<=n;i++) s[i] = s[i - 1] + (str[i] == ')' ? 1 : -1);
	segtree::build(1, 0, n - 1);
	
	long long ans = 0; sam::init();
	for(int i=1;i<=n;i++) {
		if( str[i] == '(' ) stk[++tp] = i;
		else if( tp ) stk[tp--] = 0;
		int l = (tp ? stk[tp] + 1 : 1);
		
		int x = sam::extend(str[i] == '(' ? 0 : 1);
		int r = i - sam::len[sam::fa[x]];
		
		if( l <= r ) {
			type p = segtree::query(1, l - 1, r - 1);
			if( p.mx == s[i] ) ans += p.cnt;
		}
	}
	printf("%lld\n", ans);
}