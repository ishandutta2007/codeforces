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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

struct SegTreeNode {
	int l, r;
	pii val;
	int toAdd;

	SegTreeNode() : l(-1), r(-1), val(), toAdd(0) {}
	SegTreeNode(int _l, int _r) : l(_l), r(_r), val(mp(_l, _l)), toAdd(0) {}

	void apply(int x) {
		val.first += x;
		toAdd += x;
	}
};
struct SegmentTree {
	vector<SegTreeNode> tree;
	int L;

	SegmentTree() : tree(), L(-1) {}
	SegmentTree(int _L) {
		L = _L;
		while(L & (L - 1)) L++;
		tree.resize(2 * L);
		for (int i = 0; i < L; i++)
			tree[L + i] = SegTreeNode(i, i + 1);
		for (int i = L - 1; i > 0; i--)
			tree[i] = SegTreeNode(tree[2 * i].l, tree[2 * i + 1].r);
	}

	void push(int v) {
		for (int u = 2 * v; u < 2 * v + 2; u++) {
			tree[u].apply(tree[v].toAdd);
		}
		tree[v].toAdd = 0;
	}
	void update(int v) {
		tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
	}

	void addOnSegm(int v, int l, int r, int x) {
		if (l <= tree[v].l && tree[v].r <= r) {
			tree[v].apply(x);
			return;
		}
		if (l >= tree[v].r || tree[v].l >= r) return;
		push(v);
		for (int u = 2 * v; u < 2 * v + 2; u++)
			addOnSegm(u, l, r, x);
		update(v);
	}
	pii getMin(int v, int l, int r) {
		if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
		if (l >= tree[v].r || tree[v].l >= r) return mp((int)1e9, -1);
		push(v);
		return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
	}
};

const int N = 500500;
int n, Z;
int a[N];
int b[N][2];
vector<int> ev[N];

void solve() {
	eprintf("solve\n");
	scanf("%d", &n);
	Z = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) Z++;
	}
	for (int i = 0; i < n; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	for (int i = 1; i <= n; i++)
		b[i][0] = b[i][1] = 0;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			bal++;
		} else {
			if (bal <= Z - bal)
				b[a[i]][0] = max(b[a[i]][0], bal);
			else
				b[a[i]][1] = max(b[a[i]][1], Z - bal);
		}
	}
	Z /= 2;
	if (Z == 0) {
		printf("0\n");
		return;
	}
	SegmentTree tree = SegmentTree(2 * Z + 1);
	int ans = 0;
	for (int i = 0; i <= 2 * Z; i++)
		ev[i].clear();
	for (int i = 1; i <= n; i++) {
		if (b[i][0] == 0 && b[i][1] == 0) continue;
		eprintf("have %d %d\n", b[i][0], b[i][1]);
		ev[2 * Z - b[i][1] + 1].push_back(b[i][0]);
		tree.addOnSegm(1, 0, b[i][0], 1);
	}
	for (int r = 0; r <= 2 * Z; r++) {
		for (int x : ev[r]) tree.addOnSegm(1, x, 2 * Z + 1, 1);
		int w = tree.getMin(1, 0, r).first;
		eprintf("check %d %d\n", r, w);
		ans = max(ans, r - tree.getMin(1, 0, r).first);
	}
	printf("%d\n", min(Z, 2 * Z - ans));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}