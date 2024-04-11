#include <bits/stdc++.h>

typedef std::pair<int, int> pii;
#define fi first
#define se second
#define pr std::make_pair

const int N = 500000;

std::vector<int>G[N + 5]; int n;
void adde(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}

namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5], mx[4*N + 5];
	
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r;
		if( l == r ) {mx[x] = (int)G[l].size(); return ;}
		
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		mx[x] = std::max(mx[lch], mx[rch]);
	}
	void add(int x, int p, int d) {
		if( le[x] == ri[x] ) {mx[x] += d; return ;}
		
		int m = (le[x] + ri[x]) >> 1;
		if( p <= m ) add(lch, p, d); else add(rch, p, d);
		mx[x] = std::max(mx[lch], mx[rch]);
	}
	pii find(int x) {
		if( le[x] == ri[x] ) return pr(le[x], mx[x]);
		else return find(mx[lch] == mx[x] ? lch : rch);
	}
}

int lst[N + 5], nxt[N + 5];
void erase(int x) {
	lst[nxt[x]] = lst[x], nxt[lst[x]] = nxt[x];
	segtree::add(1, x, -n);
	for(auto to : G[x]) segtree::add(1, to, -1);
}
int find1(int i) {
	int pos = 0;
	for(int j=nxt[0];j!=n+1;j=nxt[j]) {
		while( pos < (int)G[i].size() && G[i][pos] < j ) pos++;
		if( pos >= (int)G[i].size() || G[i][pos] != j ) return j;
	}
	return -1;
}
pii find2(int i) {
	int x = -1, pos = 0;
	for(int j=nxt[0];j!=n+1;j=nxt[j]) {
		while( pos < (int)G[i].size() && G[i][pos] < j ) pos++;
		if( pos >= (int)G[i].size() || G[i][pos] != j ) {
			if( x == -1 ) x = j;
			else return pr(x, j);
		}
	}
	return pr(-1, -1);
}

int p[N + 5], q[N + 5];
bool sgn(int x) {return x < 0;}
void solve() {
	int m; scanf("%d%d", &n, &m);
	for(int i=0;i<=n+1;i++) lst[i] = i - 1, nxt[i] = i + 1, G[i].clear();
	for(int i=1,l,r;i<=m;i++) scanf("%d%d", &l, &r), adde(l, r);
	for(int i=1;i<=n;i++) std::sort(G[i].begin(), G[i].end());
	segtree::build(1, 1, n);
	
	int k = 0;
	while( true ) {
		pii x = segtree::find(1);
		if( x.se < 0 ) break; else erase(x.fi);
		if( x.se == n - k - 1 ) {
			p[x.fi] = q[x.fi] = (++k);
		} else if( x.se == n - k - 2 ) {
			std::vector<int>v; v.push_back(x.fi);
			int y = find1(x.fi), tmp = 1; erase(y);
			while( true ) {
				x = segtree::find(1);
				if( x.se < 0 || x.se != n - k - 2 - tmp ) break;
				erase(x.fi), v.push_back(x.fi), tmp++;
			}
			p[y] = k + 1;
			for(auto t : v) q[t] = (++k), p[t] = k + 1;
			q[y] = (++k);
		} else if( x.se == n - k - 3 ) {
			pii y = find2(x.fi); erase(y.fi);
			if( segtree::find(1).se == n - k - 3 ) {
				erase(y.se);
				p[y.fi] = q[x.fi] = (++k), p[y.se] = q[y.fi] = (++k), p[x.fi] = q[y.se] = (++k);	
			} else {
				p[y.fi] = q[x.fi] = (++k), p[x.fi] = q[y.fi] = (++k);	
			}
		} else {
			int y = find1(x.fi); erase(y);
			p[y] = q[x.fi] = (++k), p[x.fi] = q[y] = (++k);
		}
	}
	
	for(int i=1;i<=n;i++) printf("%d ", p[i]); puts("");
	for(int i=1;i<=n;i++) printf("%d ", q[i]); puts("");
	
	for(int i=1;i<=n;i++) assert( (int)G[i].size() == n - 1 || p[i] != q[i] );
	for(int i=1;i<=n;i++) for(auto to : G[i]) assert( sgn(p[i] - p[to]) == sgn(q[i] - q[to]) );
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}