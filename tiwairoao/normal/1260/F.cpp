#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define pr make_pair

const int N = 100000;
const int P = int(1E9) + 7;

inline int add(int x, int y) {x += y; return x >= P ? x - P : x;}
inline int sub(int x, int y) {x -= y; return x < 0 ? x + P : x;}
inline int mul(int x, int y) {return (int) (1LL * x * y % P);}
int mpow(int b, int p) {
	int r; for(r=1;p;p>>=1,b=mul(b,b))
		if( p & 1 ) r = mul(r, b);
	return r;
}

struct edge{
	int to; edge *nxt;
}edges[2*N + 5], *adj[N + 5], *ecnt = edges;
void adde(int u, int v) {
	edge *p = (++ecnt), *q = (++ecnt);
	(*p) = (edge){v, adj[u]}, adj[u] = p;
	(*q) = (edge){u, adj[v]}, adj[v] = q;
}
#define repG(x) for(edge *p=adj[x];p;p=p->nxt)

bool vis[N + 5]; int siz[N + 5], hvy[N + 5];
int get_size(int x, int f) {
	siz[x] = 1;
	repG(x) if( p->to != f && !vis[p->to] )
		siz[x] += get_size(p->to, x);
	return siz[x];
}
int getG(int x, int f, const int &S) {
	int ret = -1; hvy[x] = S - siz[x];
	repG(x) if( p->to != f && !vis[p->to] ) {
		int t = getG(p->to, x, S);
		if( ret == -1 || hvy[ret] > hvy[t] ) ret = t;
		hvy[x] = max(hvy[x], siz[p->to]);
	}
	if( ret == -1 || hvy[ret] > hvy[x] ) ret = x;
	return ret;
}

int fa[N + 5], dis[20][N + 5], dep[N + 5];
void get_dist(int x, int f, int k, const int &d) {
	dis[d][x] = k;
	repG(x) if( p->to != f && !vis[p->to] )
		get_dist(p->to, x, k + 1, d);
}
void divide(int x) {
	int d = dep[x]; vis[x] = true;
	get_dist(x, 0, 0, d);
	
	repG(x) if( !vis[p->to] ) {
		int g = getG(p->to, x, get_size(p->to, x));
		fa[g] = x, dep[g] = dep[x] + 1, divide(g);
	}
}

pii f[N + 5], g[N + 5]; int a[N + 5], nw;
int get(const pii &x, int d) {return add(mul(x.fi, d), x.se);}
pii add(const pii &x, const pii &y) {return pr(add(x.fi, y.fi), add(x.se, y.se));}
pii sub(const pii &x, const pii &y) {return pr(sub(x.fi, y.fi), sub(x.se, y.se));}
void modify(int x, int k) {
	int del1 = mul(a[x], get(f[x], dis[dep[x]][x]));
	pii del2 = pr(a[x], mul(dis[dep[x]][x], a[x]));
	nw = (k == 1 ? add(nw, del1) : sub(nw, del1));
	f[x] = (k == 1 ? add(f[x], del2) : sub(f[x], del2));
	
	for(int i=fa[x],j=x;i;j=i,i=fa[i]) {
		del1 = mul(a[x], get(sub(f[i], g[j]), dis[dep[i]][x]));
		del2 = pr(a[x], mul(dis[dep[i]][x], a[x]));
		nw = (k == 1 ? add(nw, del1) : sub(nw, del1));
		f[i] = (k == 1 ? add(f[i], del2) : sub(f[i], del2));
		g[j] = (k == 1 ? add(g[j], del2) : sub(g[j], del2));
	}
}

vector<int>v1[N + 5], v2[N + 5];
int main() {
	int n; scanf("%d", &n);
	
	int le = N, ri = 0, coef = 1;
	for(int i=1,l,r;i<=n;i++) {
		scanf("%d%d", &l, &r), r++;
		le = min(le, l), v1[l].push_back(i);
		ri = max(ri, r), v2[r].push_back(i);
		coef = mul(coef, r - l), a[i] = mpow(r - l, P - 2);
	}
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d", &u, &v), adde(u, v);
	divide(getG(1, 0, get_size(1, 0)));
	
	int ans = 0;
	for(int i=le;i<=ri;i++) {
		for(auto x : v1[i]) modify(x, 1);
		for(auto x : v2[i]) modify(x, -1);
		ans = add(ans, nw);
	}
	printf("%d\n", mul(ans, coef));
}