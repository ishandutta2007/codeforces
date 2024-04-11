#include <map>
#include <stack>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 200000;
const ll INF = ll(1E15);

struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	struct node{
		int le, ri;
		ll mn, tg;
	}t[4*MAXN + 5];
	void pushup(int x) {
		t[x].mn = min(t[x<<1].mn, t[x<<1|1].mn);
	}
	void build(int x, int l, int r) {
		t[x].le = l, t[x].ri = r, t[x].tg = 0;
		if( l == r ) {
			t[x].mn = l;
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		pushup(x);
	}
	void update(int x, ll k) {
		t[x].mn += k, t[x].tg += k;
	}
	void pushdown(int x) {
		if( t[x].tg ) {
			update(lch, t[x].tg), update(rch, t[x].tg);
			t[x].tg = 0;
		}
	}
	void modify(int x, int l, int r, ll d) {
		if( l > t[x].ri || t[x].le > r )
			return ;
		if( l <= t[x].le && t[x].ri <= r ) {
			update(x, d);
			return ;
		}
		pushdown(x);
		modify(lch, l, r, d);
		modify(rch, l, r, d);
		pushup(x);
	}
	int query(int x, int k) {
		if( t[x].le == t[x].ri ) return t[x].le;
		pushdown(x);
		if( t[lch].mn <= k ) return query(lch, k);
		else return query(rch, k);
	}
}T;

map<int, int>lst;
int a[MAXN + 5], b[MAXN + 5], r[MAXN + 5];
stack<pii>s1, s2;
int main() {
	int n, k, d; scanf("%d%d%d", &n, &k, &d);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	if( d == 0 ) {
		int ansl = 1, ansr = 1, le = 1;
		for(int i=2;i<=n;i++) {
			if( a[i] != a[le] ) le = i;
			if( i - le > ansr - ansl )
				ansl = le, ansr = i;
		}
		printf("%d %d\n", ansl, ansr);
	}
	else {
		for(int i=1;i<=n;i++)
			r[i] = (a[i] % d + d) % d, b[i] = (a[i] - r[i]) / d;
		int ansl = 1, ansr = 1, le = 1;
		T.build(1, 1, n), T.update(1, -k);
		s1.push(mp(1, 1)), s2.push(mp(1, 1));
		lst[a[1]] = 1;
		for(int i=2;i<=n;i++) {
			pii p = mp(i, i);
			while( !s1.empty() && b[s1.top().se] < b[i] ) {
				p = mp(s1.top().fi, i);
				T.modify(1, s1.top().fi, s1.top().se, -b[s1.top().se]), s1.pop();
			}
			T.modify(1, p.fi, p.se, b[p.se]), s1.push(p);
			p = mp(i, i);
			while( !s2.empty() && b[s2.top().se] > b[i] ) {
				p = mp(s2.top().fi, i);
				T.modify(1, s2.top().fi, s2.top().se, b[s2.top().se]), s2.pop();
			}
			T.modify(1, p.fi, p.se, -b[p.se]), s2.push(p);
			if( r[i] != r[i-1] )
				T.modify(1, le, i - 1, INF), le = i;
			int x = lst[a[i]] + 1;
			if( le < x )
				T.modify(1, le, x - 1, INF), le = x;
			lst[a[i]] = i;
			int j = T.query(1, i);
			if( i - j > ansr - ansl )
				ansl = j, ansr = i;
		}
		printf("%d %d\n", ansl, ansr);
	}
}
/*
r - l + 1 + k >= max - min + 1

r >= max - min + l - k
*/