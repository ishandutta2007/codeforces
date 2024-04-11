#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LOG = 18;
const int N = 1 << LOG;
vector<int> g[N + 7];
int t[N + 7][2];
int T;
int h[N + 7];
int par[N + 7][LOG];
int n;
int a[N + 7];

void dfs(int v) {
	t[v][0] = T++;
	for (int u : g[v]) {
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[u][k];
			if (w == -1)
				par[u][k + 1] = -1;
			else
				par[u][k + 1] = par[w][k];
		}
		dfs(u);
	}
	t[v][1] = T;
}

int up(int v, int dh) {
	for (int k = LOG - 1; k >= 0; k--) {
		if (dh < (1 << k)) continue;
		dh -= 1 << k;
		v = par[v][k];
	}
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k] == par[u][k]) continue;
		v = par[v][k];
		u = par[u][k];
	}
	return par[v][0];
}

struct Item {
	int t;
	int v, u, w;

	Item() : t(-1), v(), u(), w() {}
	Item(int _t, int _v, int _u, int _w) : t(_t), v(_v), u(_u), w(_w) {}

	void eprint() {
		eprintf("(%d %d %d %d)\n", t, v, u, w);
	}
};

bool isAnc(int v, int u) {
	return t[v][0] <= t[u][0] && t[u][1] <= t[v][1];
}

int getLowest(int v, int u) {
	if (isAnc(v, u)) return u;
	if (isAnc(u, v)) return v;
	return -1;
}

Item merge(Item A, Item B) {
	if (A.t == -1 || B.t == -1) return Item(-1, 0, 0, 0);
	if (A.t == 0) return B;
	if (B.t == 0) return A;
	if (A.t < B.t) swap(A, B);
	if (A.t == 1) {
		int v = getLowest(A.v, B.v);
		if (v == -1) return Item(2, LCA(A.v, B.v), A.u, B.u);
		if (v == A.v) swap(A, B);
		int u = getLowest(A.u, B.u);
		if (u != -1) return Item(1, A.v, u, 0);
		u = LCA(A.u, B.u);
		if (u == A.v) return Item(2, A.v, A.u, B.u);
		return Item(-1, 0, 0, 0);
	} else if (B.t == 1) {
		int v = A.v;
		if (!isAnc(v, B.v)) return Item(-1, 0, 0, 0);
		int z = getLowest(A.u, B.u);
		if (z != -1) return Item(2, v, z, A.w);
		z = getLowest(A.w, B.u);
		if (z != -1) return Item(2, v, A.u, z);
		return Item(-1, 0, 0, 0);
	} else {
		if (A.v != B.v) return Item(-1, 0, 0, 0);
		int v = getLowest(A.u, B.u), u = getLowest(A.w, B.w);
		if (v != -1 && u != -1) return Item(2, A.v, v, u);
		v = getLowest(A.u, B.w);
		u = getLowest(A.w, B.u);
		if (v != -1 && u != -1) return Item(2, A.v, v, u);
		return Item(-1, 0, 0, 0);
	}
}

struct Node {
	int l, r;
	Item I;

	Node () : l(), r(), I() {}
	Node(int _l, int _r) : l(_l), r(_r), I() {}
};
Node tree[2 * N + 7];

void buildTree() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void treeSet(int v, int x) {
	v += N;
	tree[v].I = Item(1, x, x, 0);
	while(v > 1) {
		v >>= 1;
		tree[v].I = merge(tree[2 * v].I, tree[2 * v + 1].I);
	}
}

Item getOnSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].I;
	if (l >= tree[v].r || tree[v].l >= r)
		return Item(0, 0, 0, 0);
	return merge(getOnSegm(2 * v, l, r), getOnSegm(2 * v + 1, l, r));
}

int getAns(int v, Item &I) {
	Item I2 = merge(I, tree[v].I);
	if (I2.t != -1) {
		I = I2;
		return tree[v].r;
	}
	if (v >= N) return tree[v].l;
	int u = 2 * v;
	int ans = getAns(u, I);
	if (ans != tree[u].r) return ans;
	return getAns(u + 1, I);
}

int answer() {
	Item I = Item(0, 0, 0, 0);
	return getAns(1, I);
}

void printAll() {
	for (int i = 0; i < n; i++) {
		eprintf("%d : ", i + 1);
		getOnSegm(1, 0, i + 1).eprint();
	}
	eprintf("----------\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		g[v].push_back(i);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LOG; j++)
			par[i][j] = -1;
	dfs(0);
	buildTree();
	for (int i = 0; i < n; i++)
		treeSet(a[i], i);
//	printAll();
	int q;
	scanf("%d", &q);
	while(q--) {
		int z;
		scanf("%d", &z);
		if (z == 1) {
			int v, u;
			scanf("%d%d", &v, &u);
			v--;u--;
			treeSet(a[v], u);
			treeSet(a[u], v);
			swap(a[v], a[u]);
		} else
			printf("%d\n", answer());
//		printAll();
	}

	return 0;
}