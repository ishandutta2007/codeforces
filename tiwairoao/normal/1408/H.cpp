#include <bits/stdc++.h>

const int N = 500000;

namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5], mn[4*N + 5], s[4*N + 5];
	
	void pushup(int x) {s[x] = s[lch] + s[rch], mn[x] = std::min(mn[rch], mn[lch] + s[rch]);}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, mn[x] = s[x] = 0;
		if( l == r ) return ;
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
	}
	void add(int x, int p, int k) {
		if( le[x] == ri[x] ) {
			s[x] += k, mn[x] = std::min(0, s[x]);
			return ;
		}
		
		int m = (le[x] + ri[x]) >> 1;
		if( p <= m ) add(lch, p, k); else add(rch, p, k);
		pushup(x);
	}
}

bool vis[N + 5]; int b[N + 5], a[N + 5], n;
int work(int p) {
//	printf("%d\n", p);
	for(int i=1;i<=n;i++) b[i] = 0, vis[i] = false;
	
	int ret = 0, cnt0 = 0; segtree::build(1, 1, p);
	for(int i=p;i>=1;i--) {
		if( a[i] == 0 ) cnt0++, segtree::add(1, i, -1);
		else if( !vis[a[i]] ) vis[a[i]] = true, segtree::add(1, b[a[i]] = i, 1);
	}
	int tmp = segtree::mn[1]; ret = cnt0 + tmp;
	
	std::priority_queue<int, std::vector<int>, std::greater<int> >que;
	for(int i=1;i<=n;i++) vis[i] = false;
	for(int i=p+1,tot=0;i<=n;i++) {
		if( a[i] == 0 ) {
			if( tot ) tot--, ret++;
			else {
				while( !que.empty() ) {
					int x = que.top(); que.pop();
					segtree::add(1, x, -1);
					if( segtree::mn[1] < tmp ) segtree::add(1, x, 1);
					else {ret++; break;}
				}
			}
		} else if( !vis[a[i]] ) {
			vis[a[i]] = true;
			if( b[a[i]] ) que.push(b[a[i]]);
			else tot++;
		}
	}
//	printf("? %d\n", ret);
	return ret;
}
int solve() {
	int s = 0; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=n;i++) s += (a[i] == 0);
	if( s == 0 ) return 0;
	
	for(int i=1,t=0;i<=n;i++) {
		t += (a[i] == 0);
		if( t == ((s + 1) >> 1) ) return std::min(s >> 1, work(i));
	}
	return -1;
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) printf("%d\n", solve());
}