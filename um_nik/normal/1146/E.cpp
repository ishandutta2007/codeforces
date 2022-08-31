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

const int N = 1 << 17;
struct Item {
	int a[2];

	Item() {
		a[0] = 0;
		a[1] = 1;
	}

	Item operator * (const Item &I) const {
		Item R = Item();
		R.a[0] = I.a[a[0]];
		R.a[1] = I.a[a[1]];
		return R;
	}
};
struct Node {
	int l, r;
	Item val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].val = tree[u].val * tree[v].val;
	}
	tree[v].val = Item();
}
void applySegm(int v, int l, int r, Item I) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].val = tree[v].val * I;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		applySegm(u, l, r, I);
}

int a[N + 5];
int n, q;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while(q--) {
		char t;
		int x;
		scanf(" %c %d", &t, &x);
		Item I = Item();
		if (t == '>') {
			if (x > 0) {
				I.a[0] = 0;
				I.a[1] = 0;
				applySegm(1, x + 1, N, I);
			} else {
				I.a[0] = 1;
				I.a[1] = 0;
				applySegm(1, 0, abs(x), I);
				I.a[0] = 0;
				applySegm(1, abs(x), N, I);
			}
		} else {
			if (x > 0) {
				I.a[0] = 1;
				I.a[1] = 0;
				applySegm(1, 0, x, I);
				I.a[1] = 1;
				applySegm(1, x, N, I);
			} else {
				I.a[0] = 1;
				I.a[1] = 1;
				applySegm(1, abs(x) + 1, N, I);
			}
		}
	}
	for (int i = 1; i < N; i++)
		push(i);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		Item I = tree[N + abs(x)].val;
		if (x > 0) {
			if (I.a[1] == 0) x *= -1;
		} else {
			if (I.a[0] == 1) x *= -1;
		}
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}