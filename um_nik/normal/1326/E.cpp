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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}


struct SegTreeNode {
	int l, r;
	pii val;
	int toAdd;

	SegTreeNode() : l(-1), r(-1), val(), toAdd(0) {}
	SegTreeNode(int _l, int _r) : l(_l), r(_r), val(mp(0, _l)), toAdd(0) {}

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

const int N = 300300;
int n;
pii a[N];
int ans;

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	ans = n;
	SegmentTree tree = SegmentTree(n);
	for (int i = 0; i < n; i++) {
		while(min(0, tree.getMin(1, 0, n).first) >= (n - ans) - i) {
			ans--;
			tree.addOnSegm(1, a[ans].second, n, 1);
		}
		printf("%d ", ans + 1);
		int x;
		scanf("%d", &x);
		x--;
		tree.addOnSegm(1, x, n, -1);
	}
	printf("\n");

	return 0;
}