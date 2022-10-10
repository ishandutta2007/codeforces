#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m;
vector<pair<int, int>> g[N];
int eu[N], ev[N], et[N];

int in[N], out[N], rin[N], dfst;

int start[N], tour[2*N], id[2*N], dfs_time;

int dn[2*N][20];
inline int fn(int i, int j){
	if(j == 0) return tour[i];
	if(~dn[i][j]) return dn[i][j];
	return dn[i][j] = min(fn(i, j-1), fn(i + (1 << (j-1)), j-1));
}
inline int lg(int x) {
	return 31 - __builtin_clz(x);
}
inline int getmn(int l, int r){ // [l, r]
	int lz = lg(r - l + 1);
	return min(fn(l, lz), fn(r - (1 << lz) + 1, lz));
}
inline int LCA(int u, int v) {
	if(start[u] > start[v]) swap(u, v);
	return id[getmn(start[u], start[v])];
}
int val[N], lvl[N];
inline void dfs(int u, int p) {
	start[u] = dfs_time;
	id[dfs_time] = u;
	tour[dfs_time++] = start[u];
	in[u] = ++dfst;
	rin[ in[u] ] = u;
	for(auto [v, w] : g[u]) if(v != p) {
		val[v] = val[u] ^ w;
		lvl[v] = lvl[u] + 1;
		dfs(v, u);
		id[dfs_time] = u;
		tour[dfs_time++] = start[u];
	}
	out[u] = dfst;
}

struct Diam {
	int a = -1, b = -1;
	int len = 0;
	Diam(int l = -1, int r = -1) : a(l), b(r) {
		if(a != -1 and b != -1) {
			len = lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
		}
		else if(a == -1 and b == -1) {
			len = -1;
		}
	}
	Diam operator+(const Diam &o) const {
		Diam ans = max(*this, o);
		if(a != -1 and o.a != -1) ans = max(ans, Diam(a, o.a));
		if(a != -1 and o.b != -1) ans = max(ans, Diam(a, o.b));
		if(b != -1 and o.a != -1) ans = max(ans, Diam(b, o.a));
		if(b != -1 and o.b != -1) ans = max(ans, Diam(b, o.b));
		return ans;
	}
	bool operator<(const Diam &o) const {
		return len < o.len;
	}
	void print() const {
		printf("a = %d; b = %d; len = %d\n", a, b, len);
	}
};

Diam st[4*N][2];
int lz[4*N];
inline void prop(int p, int L, int R) {
	if(lz[p]) {
		swap(st[p][0], st[p][1]);
		if(L < R) {
			lz[2 * p] ^= 1;
			lz[2 * p + 1] ^= 1;
		}
		lz[p] = 0;
	}
}
inline void upd(int p, int L, int R, int i, int j) {
	prop(p, L, R);
	if(i > R or j < L) return;
	if(L >= i and R <= j) {
		lz[p] = 1;
		prop(p, L, R);
		return;
	}
	int mid = (L + R) / 2;
	upd(2 * p, L, mid, i, j);
	upd(2 * p + 1, mid + 1, R, i, j);
	st[p][0] = st[2 * p][0] + st[2 * p + 1][0];
	st[p][1] = st[2 * p][1] + st[2 * p + 1][1];
}
inline void build(int p, int L, int R) {
	if(L == R) {
		int u = rin[L];
		st[p][val[u]] = Diam(u);
		return;
	}
	int mid = (L + R) / 2;
	build(2 * p, L, mid);
	build(2 * p + 1, mid + 1, R);
	st[p][0] = st[2 * p][0] + st[2 * p + 1][0];
	st[p][1] = st[2 * p][1] + st[2 * p + 1][1];
}
inline void print(int p, int L, int R) {
	printf("p = %d; L = %d; R = %d\n", p, L, R);
	st[p][0].print(), st[p][1].print();
	printf("\n");
	if(L == R) {
		return;
	}
	int mid = (L + R) / 2;
	print(2 * p, L, mid);
	print(2 * p + 1, mid + 1, R);
}

int main() {
	memset(dn, -1, sizeof dn);

	scanf("%d", &n);

	for(int i = 1; i < n; i++) {
		scanf("%d %d %d", eu + i, ev + i, et + i);
		g[ eu[i] ].emplace_back(ev[i], et[i]);
		g[ ev[i] ].emplace_back(eu[i], et[i]);
	}

	dfs(1, 1);

	build(1, 1, n);

	scanf("%d", &m);
	while(m--) {
		int i;
		scanf("%d", &i);
		int u = lvl[ eu[i] ] < lvl[ ev[i] ] ? ev[i] : eu[i];
		upd(1, 1, n, in[u], out[u]);
		printf("%d\n", max(st[1][0].len, st[1][1].len));
	}

}