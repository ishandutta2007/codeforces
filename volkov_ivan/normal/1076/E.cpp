#include <iostream>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
//#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
//#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
//#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
//#define int long long
#pragma GCC optisdfklkjikmize("Ofast")
#include <set>

using namespace std;

struct Node{
	long long s = 0, d = 0;
	Node() {}
	Node (long long s) {
		this->s = s;
		d = 0;
	}
};

const int MAX_N = 1 << 19;
Node t[2 * MAX_N];
vector <int> g[MAX_N];
long long pluss[MAX_N], minuss[MAX_N];
vector <pair <long long, int>> add[MAX_N];
long long now_add;
vector <int> all_v[MAX_N];
long long ans[MAX_N];

void relax(int pos) {
	t[pos].s = t[2 * pos].s + t[2 * pos + 1].s;
}

void full(int pos, int l, int r, long long x) {
	t[pos].s += x * (r - l + 1);
	//cout << x << ' ' << t[pos].s << ' ' << l << ' ' << r << endl;
	t[pos].d += x;
}

void print() {
	for (int i = 1; i < 2 * MAX_N; i++) cout << t[i].s << ' ' << t[i].d << endl;
}

void push(int pos, int l, int r) {
	int m = (l + r) / 2;
	full(2 * pos, l, m, t[pos].d);
	full(2 * pos + 1, m + 1, r, t[pos].d);
	t[pos].d = 0;
}

void update(int pos, int l, int r, int a, int b, long long x) {
	if (a > r || l > b) return;
	if (a <= l && r <= b) {
		full(pos, l, r, x);
		return;
	}
	push(pos, l, r);
	int m = (l + r) / 2;
	update(2 * pos, l, m, a, b, x);
	update(2 * pos + 1, m + 1, r, a, b, x);
	relax(pos);
}

long long find(int pos, int l, int r, int a, int b) {
	if (a > r || l > b) return 0;
	if (a <= l && r <= b) return t[pos].s; 
	push(pos, l, r);
	int m = (l + r) / 2;
	return find(2 * pos, l, m, a, b) + find(2 * pos + 1, m + 1, r, a, b);
}

int dfs_left(int v, int pr = -1, int d = 1) {
	for (pair <long long, long long> elem : add[v]) {
		//cout << d << ' ' << d + elem.second << endl;
		update(1, 1, MAX_N, d, d + elem.second, elem.first);
	}
	//cout << 72 << endl;
//	if (v == 2) print();
//	cout << endl;
//	cout << endl;
	pluss[v] = find(1, 1, MAX_N, d, d);
	//cout << pluss[v] << endl;
	update(1, 1, MAX_N, d, d, -pluss[v]);
	int max_d = d;
	all_v[d].push_back(v);
	for (int u : g[v]) {
		//cout << 82 << endl;
		if (u != pr) max_d = max(max_d, dfs_left(u, v, d + 1));
	}
	for (pair <long long, long long> elem : add[v]) {
		if (d + elem.second > max_d) update(1, 1, MAX_N, max_d + 1, d + elem.second, -elem.first);
	}
	return max_d;
}

int dfs_right(int v, int pr = -1, int d = 1) {
	for (pair <long long, long long> elem : add[v]) {
		//cout << "!" << elem.first << ' ' << elem.second << endl;
		update(1, 1, MAX_N, d, d + elem.second, elem.first);
	}
	minuss[v] = find(1, 1, MAX_N, d, d);
	update(1, 1, MAX_N, d, d, -minuss[v]);
	int max_d = d;
	//all_v[d].push_back(v);
	for (int i = (int) g[v].size() - 1; i >= 0; i--) {
		int u = g[v][i];
		if (u != pr) max_d = max(max_d, dfs_right(u, v, d + 1));
	}
	for (pair <long long, long long> elem : add[v]) {
		if (d + elem.second > max_d) update(1, 1, MAX_N, max_d + 1, d + elem.second, -elem.first);
	}
	return max_d;
}

void init() {
	for (int i = 1; i < 2 * MAX_N; i++) t[i] = Node(0);
}

signed main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	//ios_base :: sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n, m, v, u;
	//cin >> n;
	scanf("%d\n", &n);
	//cout << n << endl;
	for (int i = 1; i < n; i++) {
		//cin >> v >> u;
		scanf("%d %d\n", &v, &u);	
		//cout << 122 << v << ' ' << u << endl;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d\n", &m);
	//cin >> m;
	int x, d;
	for (int i = 0; i < m; i++) {
		//cin >> v >> d >> x;
		scanf("%d %d %d\n", &v, &d, &x);
		add[v].push_back({x, d});
	}
	init();
	dfs_left(1);
	init();
	dfs_right(1);
	for (int dd = 1; dd < MAX_N; dd++) {
		long long s = 0;
		for (int i = 0; i < all_v[dd].size(); i++) {
			s += pluss[all_v[dd][i]];
			ans[all_v[dd][i]] = s;
			s -= minuss[all_v[dd][i]];
		//	cout << pluss[all_v[dd][i]] << ' ' << minuss[all_v[dd][i]]  << endl;
		}
	}
	for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
	//cout << endl;
	return 0;
}