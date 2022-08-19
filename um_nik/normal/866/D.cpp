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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1 << 19;
struct Node {
	int l, r;
	int minBal, endBal;

	Node() : l(-1), r(-1), minBal(), endBal() {}
	Node(int _l, int _r) : l(_l), r(_r), minBal(0), endBal(0) {}
};
Node tree[2 * N];
pii a[N];
int n;

Node merge(Node L, Node R) {
	if (L.l == -1) return R;
	if (R.l == -1) return L;
	Node A = Node(L.l, R.r);
	if (L.endBal + R.minBal < 0) {
		A.minBal = L.minBal + L.endBal + R.minBal;
		A.endBal = R.endBal;
	} else {
		A.minBal = L.minBal;
		A.endBal = R.endBal + L.endBal + R.minBal;
	}
	return A;
}

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void setNode(int v, int type) {
	v += N;
	if (type == 1) {
		tree[v].minBal = 0;
		tree[v].endBal = 1;
	} else {
		tree[v].minBal = -1;
		tree[v].endBal = 0;
	}
	while(v > 1) {
		v >>= 1;
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
}

Node getVal(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v];
	if (l >= tree[v].r || tree[v].l >= r)
		return Node();
	return merge(getVal(2 * v, l, r), getVal(2 * v + 1, l, r));
}

ll res = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);

	build();
	for (int i = 0; i < n; i++)
		setNode(i, -1);
	for (int i = 0; i < n - 1; i++) {
		setNode(a[i].second, 1);
		//Node U = getVal(1, 0, n);
		//printf("%d %d\n", U.minBal, U.endBal);
		res += (ll)(a[i + 1].first - a[i].first) * (i + 1 - getVal(1, 0, n).endBal);
	}

	printf("%lld\n", res);

	return 0;
}