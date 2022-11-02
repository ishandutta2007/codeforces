#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 200009;
int n, m;
int a[MAX], loc[2][MAX], start[2][MAX], endd[2][MAX], loc_inv[MAX];
int tempo[2];
vector<int> adj[MAX];
int seen[MAX];
int typ[MAX];
void dfs(int u, int d) {
	seen[u] = 1;
	typ[u] = d;
	loc[d][tempo[d]] = u;
	loc_inv[u] = tempo[d]++;
	start[0][u] = tempo[0];
	start[1][u] = tempo[1];
	for(int v : adj[u])
		if(!seen[v])
			dfs(v, !d);
	endd[0][u] = tempo[0];
	endd[1][u] = tempo[1];
}

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }
int tree[2][MAX << 2], lazy[2][MAX << 2];
int ti;
void unlaze(int i, int from, int to) {
	if(!lazy[ti][i]) return;
	if(from == to) {
		tree[ti][i] += lazy[ti][i];
	} else {
		lazy[ti][l(i)] += lazy[ti][i];
		lazy[ti][r(i)] += lazy[ti][i];
	}
	lazy[ti][i] = 0;
}

void build_tree(int i, int from, int to) {
	lazy[ti][i] = 0;
	if(from == to) {
		tree[ti][i] = a[loc[ti][from]];
		return;
	}
	int mid = (from + to) / 2;
	build_tree(l(i), from, mid);
	build_tree(r(i), mid + 1, to);
}

void update_tree(int i, int from, int to, int ql, int qr, int val) {
	unlaze(i, from, to);
	if(ql > to || qr < from) return;
	if(from >= ql && to <= qr) {
		lazy[ti][i] = val;
		unlaze(i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	update_tree(l(i), from, mid, ql, qr, val);
	update_tree(r(i), mid + 1, to, ql, qr, val);
}

int query_tree(int i, int from, int to, int ind) {
	unlaze(i, from, to);
	if(from == to) return tree[ti][i];
	int mid = (from + to) / 2;
	if(ind <= mid) return query_tree(l(i), from, mid, ind);
	else return query_tree(r(i), mid + 1, to, ind);
}

void query_1(int x, int val) {
	ti = typ[x];
	update_tree(1, 0, tempo[ti] - 1, loc_inv[x], loc_inv[x], val);
	if(start[ti][x] != endd[ti][x])
		update_tree(1, 0, tempo[ti] - 1, start[ti][x], endd[ti][x] - 1, val);
	ti = !ti;
	if(tempo[ti] && start[ti][x] != endd[ti][x])
		update_tree(1, 0, tempo[ti] - 1, start[ti][x], endd[ti][x] - 1, -val);
}


int main() {
	int i, op, x, y;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < (n - 1); i++) {
		scanf("%d %d", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	tempo[0] = tempo[1] = 0;
	dfs(0, 0);
	ti = 0;
	if(tempo[0])
		build_tree(1, 0, tempo[0] - 1);
	ti = 1;
	if(tempo[1])
		build_tree(1, 0, tempo[1] - 1);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &op, &x); x--;
		if(op == 1) {
			scanf("%d", &y);
			query_1(x, y);
		} else {
			ti = typ[x];
			printf("%d\n", query_tree(1, 0, tempo[ti] - 1, loc_inv[x]));
		}
	}
	return 0;
}