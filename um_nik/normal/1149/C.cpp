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

const int N = 1 << 18;
struct Node {
	int l, r;
	int toAdd;
	int minAll, maxAll;
	int toLeft, toRight;
	int ans;

	Node() : l(-1), r(-1), toAdd(0), minAll(N), maxAll(0), toLeft(-N), toRight(-N), ans(0) {}
	Node(int _l, int _r) : l(_l), r(_r), toAdd(0), minAll(0), maxAll(0), toLeft(0), toRight(0), ans(0) {}

	void add(int x) {
		toAdd += x;
		minAll += x;
		maxAll += x;
		toLeft -= x;
		toRight -= x;
	}
};
Node tree[2 * N + 5];

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
	A.minAll = min(L.minAll, R.minAll);
	A.maxAll = max(L.maxAll, R.maxAll);
	A.toLeft = max(max(L.toLeft, R.toLeft), R.maxAll - 2 * L.minAll);
	A.toRight = max(max(L.toRight, R.toRight), L.maxAll - 2 * R.minAll);
	A.ans = max(max(L.ans, R.ans), max(L.toRight + R.maxAll, L.maxAll + R.toLeft));
	return A;
}
void push(int v) {
	if (v >= N) throw;
	if (tree[v].toAdd == 0) return;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].add(tree[v].toAdd);
	}
	tree[v].toAdd = 0;
}

void addOnSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].add(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addOnSegm(u, l, r, x);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}
Node get(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v];
	if (l >= tree[v].r || tree[v].l >= r) return Node();
	push(v);
	return merge(get(2 * v, l, r), get(2 * v + 1, l, r));
}

char s[N + 5];
int n, q;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d%d", &n, &q);
	n = 2 * (n - 1) + 1;
	scanf("%s", s);
	for (int i = 0; i < n - 1; i++) {
		addOnSegm(1, i + 1, n, (s[i] == '(' ? 1 : -1));
	}
	printf("%d\n", get(1, 0, n).ans);
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		if (s[x] == ')') swap(x, y);
		if (s[x] != s[y]) {
			addOnSegm(1, x + 1, n, -2);
			addOnSegm(1, y + 1, n, 2);
		}
		swap(s[x], s[y]);
		printf("%d\n", get(1, 0, n).ans);
	}

	return 0;
}