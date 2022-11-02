#include <bits/stdc++.h>

const int P = int(1E9) + 7;
const int N = 2000;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int)(1ll * x * y % P);}

int dy[N + 5], cy;

namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5], mx[4*N + 5], cvr[4*N + 5];
	int ans[4*N + 5];
	
	void pushup(int x) {
		mx[x] = mx[rch], ans[x] = add(ans[lch], ans[rch]);
	}
	void addtag(int x, int t) {
		cvr[x] = mx[x] = t, ans[x] = mul(dy[ri[x] + 1] - dy[le[x]], t);
	}
	void pushdown(int x) {
		if( cvr[x] != -1 ) addtag(lch, cvr[x]), addtag(rch, cvr[x]);
		cvr[x] = -1;
	}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, cvr[x] = -1;
		if( l == r ) {
			ans[x] = mul(dy[ri[x] + 1] - dy[le[x]], mx[x] = cvr[x] = dy[l]);
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
		pushup(x);
	}
	void cover(int x, int l, int r, int t) {
		if( l > ri[x] || r < le[x] ) return ;
		if( l <= le[x] && ri[x] <= r ) {addtag(x, t); return ;}
		pushdown(x);
		cover(lch, l, r, t), cover(rch, l, r, t);
		pushup(x);
	}
	int find(int x, int k) {
		if( le[x] == ri[x] ) return le[x];
		else return find(mx[lch] < k ? rch : lch, k);
	}
	void func(int l, int r, int k) {
		if( mx[1] < k ) return ;
		
		int p = find(1, k);
		if( p <= r ) cover(1, std::max(l, p), r, k);
	} // x = min(x, k)
	void print(int x) {
		if( le[x] == ri[x] ) {
			printf("(%d, %d) ", mx[x], ans[x]);
			return ;
		}
		pushdown(x), print(lch), print(rch);
	}
}

struct point{int x, y, c;}p[N + 5];
std::vector<int>v[N + 5], v1[N + 5];

int nxt[3*N + 5], lst[3*N + 5];
void link(int x, int y) {nxt[x] = y, lst[y] = x;}
void erase(int x) {lst[nxt[x]] = lst[x], nxt[lst[x]] = nxt[x];}

int dx[N + 5], cx;
int main() {
	int n, k, L; scanf("%d%d%d", &n, &k, &L);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c), p[i].x++, p[i].y++;
		dx[++cx] = p[i].x, dy[++cy] = p[i].y, v[p[i].c].push_back(i);
	}
	dx[++cx] = dy[++cy] = 0, dx[++cx] = dy[++cy] = L + 1;
	std::sort(dx + 1, dx + cx + 1), cx = std::unique(dx + 1, dx + cx + 1) - dx - 1;
	std::sort(dy + 1, dy + cy + 1), cy = std::unique(dy + 1, dy + cy + 1) - dy - 1;
	for(int i=1;i<=k;i++) {
		for(auto t : v[i]) {
			p[t].x = std::lower_bound(dx + 1, dx + cx + 1, p[t].x) - dx;
			p[t].y = std::lower_bound(dy + 1, dy + cy + 1, p[t].y) - dy;
			v1[p[t].x].push_back(t);
		}
		std::sort(v[i].begin(), v[i].end(), [] (int x, int y) {
			return p[x].y == p[y].y ? p[x].x < p[y].x : p[x].y < p[y].y;
		});
	}
	
	int ans = 0;
	for(int i=1;i<cx;i++) {
		segtree::build(1, 1, cy - 1);
		for(int j=1;j<=k;j++) {
			int l = n + j;
			for(auto t : v[j]) if( p[t].x > i ) link(l, t), l = t;
			link(l, n + k + j), nxt[n + k + j] = -1;
			
			for(int s=n+j,t=nxt[s];t!=-1;s=t,t=nxt[t]) {
				int l1 = (s > n ? 1 : p[s].y), r1 = (t > n ? cy : p[t].y);
				segtree::func(l1, r1 - 1, dy[l1]);
			}
		}
		
		for(int j=cx;j>i;j--) {
			for(auto t : v1[j]) {
				int lt = lst[t], nt = nxt[t];
				int l1 = (lt > n ? 1 : p[lt].y), r1 = (nt > n ? cy : p[nt].y);
				erase(t), segtree::func(p[t].y, r1 - 1, dy[l1]);
			}
//			segtree::print(1); puts("");
			int coef = mul(dx[j] - dx[j - 1], dx[i + 1] - dx[i]);
			ans = add(ans, mul(coef, segtree::ans[1]));
//			printf("%d %d\n", coef, segtree::ans[1]);
		}
	}
	printf("%d\n", ans);
}