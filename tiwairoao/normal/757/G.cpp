#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

typedef long long ll;
typedef pair<ll, int> pli;
#define rep(x) for(edge *p=adj[x];p;p=p->nxt)

struct edge{
	int to, dis;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = v, p->dis = w, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->dis = w, p->nxt = adj[v], adj[v] = p;
}

int siz[MAXN + 5], hvy[MAXN + 5];
bool vis[MAXN + 5];
int get_size(int x, int f) {
	siz[x] = 1;
	rep(x) {
		if( !vis[p->to] && p->to != f )
			siz[x] += get_size(p->to, x);
	}
	return siz[x];
}
int get_mid(int x, int f, int tot) {
	int ret = -1;
	hvy[x] = tot - siz[x];
	rep(x) {
		if( vis[p->to] || p->to == f ) continue;
		int t = get_mid(p->to, x, tot);
		if( ret == -1 || hvy[ret] > hvy[t] )
			ret = t;
		hvy[x] = max(hvy[x], siz[p->to]);
	}
	if( ret == -1 || hvy[ret] > hvy[x] )
		ret = x;
	return ret;
}
ll dis[20][MAXN + 5];
void get_dis(int dep, int x, int f, ll d) {
	dis[dep][x] = d;
	rep(x) {
		if( vis[p->to] || p->to == f ) continue;
		get_dis(dep, p->to, x, d + p->dis);
	}
}
int b[MAXN + 5];
struct node{
	int id, key; ll s;
	node(int _i=0, int _k=0, ll _s=0) : id(_i), key(_k), s(_s) {}
	friend bool operator < (node a, node b) {
		return a.key < b.key;
	}
};
vector<node>arr[2][MAXN + 5];
void get_arr(int rt, int x, int f, ll d, int type) {
	arr[type][rt].push_back(node(x, b[x], d));
	rep(x) {
		if( vis[p->to] || p->to == f ) continue;
		get_arr(rt, p->to, x, d + p->dis, type);
	}
}
int pos[2][20][MAXN + 5];
int fa[MAXN + 5], dep[MAXN + 5];
void divide(int x, int d) {
	dep[x] = d, vis[x] = true;
	get_dis(d, x, 0, 0);
	arr[0][x].push_back(node(0, -1, 0)), get_arr(x, x, 0, 0, 0);
	sort(arr[0][x].begin(), arr[0][x].end());
	for(int i=1;i<arr[0][x].size();i++) {
		arr[0][x][i].s += arr[0][x][i-1].s;
		pos[0][d][arr[0][x][i].id] = i;
	}
	rep(x) {
		if( vis[p->to] ) continue;
		int G = get_mid(p->to, 0, get_size(p->to, 0));
		arr[1][G].push_back(node(0, -1, 0)), get_arr(G, p->to, x, p->dis, 1);
		sort(arr[1][G].begin(), arr[1][G].end());
		for(int i=1;i<arr[1][G].size();i++) {
			arr[1][G][i].s += arr[1][G][i-1].s;
			pos[1][d][arr[1][G][i].id] = i;
		}
		fa[G] = x, divide(G, d + 1);
	}
}

pli get(int type, int x, int lim) {
	int p = upper_bound(arr[type][x].begin(), arr[type][x].end(), node(0, lim, 0)) - arr[type][x].begin() - 1;
	return make_pair(arr[type][x][p].s, p);
}
ll query(int x, int lim) {
	ll ans = get(0, x, lim).first;
	for(int i=x;fa[i];i=fa[i]) {
		int f = fa[i]; ll d = dis[dep[f]][x];
		pli p = get(0, f, lim), q = get(1, i, lim);
		ans += d * (p.second - q.second) + (p.first - q.first);
	}
	return ans;
}

void exchange(int t, int x, int p) {
	int d = (t == 0 ? dep[x] : dep[fa[x]]);
	pos[t][d][arr[t][x][p].id] = p + 1;
	pos[t][d][arr[t][x][p + 1].id] = p;
	ll k1 = arr[t][x][p].s, k2 = arr[t][x][p + 1].s;
	swap(arr[t][x][p], arr[t][x][p + 1]);
	arr[t][x][p].s = k2 - k1 + arr[t][x][p - 1].s, arr[t][x][p + 1].s = k2;
}
void change(int t, int rt, int x, int del) {
	int d = (t == 0 ? dep[rt] : dep[fa[rt]]), p = pos[t][d][x];
	arr[t][rt][p].key += del;
	if( p + 1 < arr[t][rt].size() && arr[t][rt][p].key > arr[t][rt][p+1].key )
		exchange(t, rt, p);
	else if( arr[t][rt][p].key < arr[t][rt][p-1].key )
		exchange(t, rt, p-1);
}
void modify(int x, int del) {
	b[x] += del;
	change(0, x, x, del);
	for(int i=x;fa[i];i=fa[i]) {
		int f = fa[i];
		change(0, f, x, del), change(1, i, x, del);
	}
}

int a[MAXN + 5];
int main() {
	int n, q; scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]), b[a[i]] = i;
	for(int i=1;i<n;i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	divide(get_mid(1, 0, get_size(1, 0)), 0);
	ll ans = 0;
	for(int i=1;i<=q;i++) {
		int t; scanf("%d", &t);
		if( t == 1 ) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			int l = (ans % (1<<30)) ^ a;
			int r = (ans % (1<<30)) ^ b;
			int v = (ans % (1<<30)) ^ c;
			ans = query(v, r) - query(v, l - 1);
//			printf("! %d %d %d\n", l, r, v);
			printf("%lld\n", ans);
		}
		else {
			int A; scanf("%d", &A);
			int x = (ans % (1<<30)) ^ A;
			modify(a[x], 1), modify(a[x + 1], -1);
//			printf("? %d\n", x);
			swap(a[x], a[x + 1]);
		}
	}
}