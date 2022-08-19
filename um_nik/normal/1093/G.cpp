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

#define set htnrtbdgrsfd

const int N = 1 << 18;
const int M = 33;
int k, m;

struct Node {
	int l, r;
	int a[M];

	Node() : l(-1), r(-1), a() {}
	Node(int _l, int _r) : l(_l), r(_r), a() {}
};
Node tree[2 * N + 7];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

Node merge(Node L, Node R) {
	if (L.l == -1) return R;
	if (R.l == -1) return L;
	Node A = Node(L.l, R.r);
	for (int i = 0; i < m; i++)
		A.a[i] = max(L.a[i], R.a[i]);
	return A;
}

void set(int v) {
	int b[6];
	for (int i = 0; i < k; i++)
		scanf("%d", &b[i]);
	v += N;
	for (int mask = 0; mask < (1 << k); mask++) {
		int x = 0;
		for (int i = 0; i < k; i++)
			if ((mask >> i) & 1)
				x += b[i];
			else
				x -= b[i];
		tree[v].a[mask] = x;
	}
	while(v > 1) {
		v >>= 1;
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
}

Node getSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v];
	if (l >= tree[v].r || tree[v].l >= r) return Node();
	return merge(getSegm(2 * v, l, r), getSegm(2 * v + 1, l, r));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	int n;
	scanf("%d%d", &n, &k);
	m = 1 << k;
	for (int i = 0; i < n; i++)
		set(i);
	int q;
	scanf("%d", &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int v;
			scanf("%d", &v);
			v--;
			set(v);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			Node A = getSegm(1, l, r);
			int ans = 0;
			for (int mask = 0; mask < m; mask++)
				ans = max(ans, A.a[mask] + A.a[(m - 1) ^ mask]);
			printf("%d\n", ans);
		}
	}

	return 0;
}