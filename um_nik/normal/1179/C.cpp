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

const int N = 1 << 20;
struct Node {
	int l, r;
	int toAdd;
	int val;

	Node() : l(), r(), toAdd(0), val(0) {}
	Node(int _l, int _r) : l(_l), r(_r), toAdd(0), val(0) {}

	void add(int x) {
		toAdd += x;
		val += x;
	}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].add(tree[v].toAdd);
	tree[v].toAdd = 0;
}
void update(int v) {
	tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
}

void addSegm(int v, int l, int r, int dx) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].add(dx);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addSegm(u, l, r, dx);
	update(v);
}

int getRight(int v) {
	if (tree[v].val <= 0) return -1;
	if (v >= N) return v - N;
	push(v);
	int res = getRight(2 * v + 1);
	if (res != -1) return res;
	return getRight(2 * v);
}

const int M = 300100;
int n, m, q;
int a[M];
int b[M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		addSegm(1, 0, a[i] + 1, 1);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		addSegm(1, 0, b[i] + 1, -1);
	}
	scanf("%d", &q);
	while(q--) {
		int t, p, x;
		scanf("%d%d%d", &t, &p, &x);
		p--;
		if (t == 1) {
			addSegm(1, 0, a[p] + 1, -1);
			a[p] = x;
			addSegm(1, 0, a[p] + 1, 1);
		} else {
			addSegm(1, 0, b[p] + 1, 1);
			b[p] = x;
			addSegm(1, 0, b[p] + 1, -1);
		}
		//printf("!!%d\n", tree[1].val);
		printf("%d\n", getRight(1));
	}

	return 0;
}