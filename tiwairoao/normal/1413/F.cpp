#include <bits/stdc++.h>

const int N = 500000;

std::vector<std::pair<int, int> >G[N + 5];
void adde(int u, int v, int w) {
	G[u].push_back(std::make_pair(v, w));
	G[v].push_back(std::make_pair(u, w));
}

int a[N + 5];

int dl[N + 5], dr[N + 5], dfn[N + 5], dcnt;
int dep[N + 5], fir[N + 5], arr[2*N + 5], cnta;
void dfs1(int x, int fa) {
	dep[x] = dep[fa] + 1, dfn[dl[x] = (++dcnt)] = x, arr[fir[x] = (++cnta)] = x;
	for(auto to : G[x]) if( to.first != fa )
		a[to.first] = a[x] ^ to.second, dfs1(to.first, x), arr[++cnta] = x;
	dr[x] = dcnt;
}

int st[22][2*N + 5], lg[2*N + 5];
void build() {
	for(int i=2;i<=cnta;i++) lg[i] = lg[i >> 1] + 1;
	for(int i=1;i<=cnta;i++) st[0][i] = arr[i];
	for(int j=1;j<22;j++) {
		int t = (1 << (j - 1));
		for(int i=1;i+t<=cnta;i++)
			st[j][i] = (dep[st[j - 1][i]] < dep[st[j - 1][i + t]] ? st[j - 1][i] : st[j - 1][i + t]);
	}
}
int lca(int u, int v) {
	u = fir[u], v = fir[v]; if( u > v ) std::swap(u, v);
	int p = lg[v - u + 1], q = (1 << p);
	return dep[st[p][u]] < dep[st[p][v - q + 1]] ? st[p][u] : st[p][v - q + 1];
}
int dist(int u, int v) {return dep[u] + dep[v] - 2*dep[lca(u, v)];}

struct type{
	int u, v;
	friend type operator + (const type &a, const type &b) {
		if( a.u == -1 ) return b; if( b.u == -1 ) return a;
		
		int t[4] = {a.u, a.v, b.u, b.v}, mx = 0, p = 0, q = 0;
		for(int i=0;i<4;i++) for(int j=i+1;j<4;j++)
			if( dist(t[i], t[j]) > mx ) mx = dist(t[i], t[j]), p = t[i], q = t[j];
		return (type){p, q};
	}
};

namespace segtree{
	#define lch (x << 1)
	#define rch (x << 1 | 1)
	
	int le[4*N + 5], ri[4*N + 5];
	bool tag[4*N + 5]; type mx[4*N + 5][2];
	
	void addtag(int x) {tag[x] ^= 1, std::swap(mx[x][0], mx[x][1]);}
	void pushup(int x) {mx[x][0] = mx[lch][0] + mx[rch][0], mx[x][1] = mx[lch][1] + mx[rch][1];}
	void pushdown(int x) {if( tag[x] ) addtag(lch), addtag(rch); tag[x] = 0;}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tag[x] = 0;
		if( l == r ) {
			mx[x][a[dfn[l]]] = (type){dfn[l], dfn[l]};
			mx[x][!a[dfn[l]]] = (type){-1, -1};
			return ;
		}
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r), pushup(x);
	}
	void rev(int x, int ql, int qr) {
		if( ql <= le[x] && ri[x] <= qr ) {
			addtag(x);
			return ;
		}
		if( le[x] > qr || ri[x] < ql ) return ;
		pushdown(x), rev(lch, ql, qr), rev(rch, ql, qr), pushup(x);
	}
	
	int ans() {
		return std::max(dist(mx[1][0].u, mx[1][0].v), dist(mx[1][1].u, mx[1][1].v));
	}
}

#define gc if(++ip==ie)fread(ip=buf,1,SZ,stdin)
const int SZ=1<<19;
char buf[SZ],*ie=buf+SZ,*ip=ie-1;
inline int read(){
    gc;while(*ip<'-')gc;
    bool f=*ip=='-';if(f)gc;
    int x=*ip&15;gc;
    while(*ip>'-'){x*=10;x+=*ip&15;gc;}
    return f?-x:x;
}

int u[N + 5], v[N + 5];
int main() {
	int n = read();
	for(int i=1,w;i<n;i++) u[i] = read(), v[i] = read(), w = read(), adde(u[i], v[i], w);
	dfs1(1, 0), build(), segtree::build(1, 1, n);
	
	int m = read();
	for(int i=1,x;i<=m;i++) {
		x = read();
		x = (dep[u[x]] < dep[v[x]] ? v[x] : u[x]);
		segtree::rev(1, dl[x], dr[x]);
		printf("%d\n", segtree::ans());
	}
}