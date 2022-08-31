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
	int val, toAdd;

	Node() : l(), r(), val(), toAdd() {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), toAdd(0) {}

	void add(int x) {
		val += x;
		toAdd += x;
	}
};
Node tree[2 * N + 3];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].add(tree[v].toAdd);
	tree[v].toAdd = 0;
}
void update(int v) {
	if (v >= N) throw;
	tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
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
	update(v);
}

int a[N + 5][4];
int xs[N + 5];
int xsSz;
int n, r;

struct Event {
	int t, x, y1, y2;

	Event() : t(), x(), y1(), y2() {}
	Event(int _t, int _x, int _y1, int _y2) : t(_t), x(_x), y1(_y1), y2(_y2) {}

	bool operator < (const Event &e) const {
		if (x != e.x) return x < e.x;
		return false;
	}
};
Event ev[N + 5];
int evSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d%d", &n, &r);
	r = 2 * r + 1;
	for (int i = 0; i < n; i++) {
		int _x, _y, x, y;
		scanf("%d%d", &_x, &_y);
		x = _x + _y;
		y = _x - _y;
		a[i][0] = x;
		a[i][1] = x + r;
		a[i][2] = y;
		a[i][3] = y + r;
	}
	for (int i = 0; i < n; i++) {
		xs[xsSz++] = a[i][2];
		xs[xsSz++] = a[i][3];
	}
	sort(xs, xs + xsSz);
	xsSz = unique(xs, xs + xsSz) - xs;
	for (int i = 0; i < n; i++) {
		a[i][2] = lower_bound(xs, xs + xsSz, a[i][2]) - xs;
		a[i][3] = lower_bound(xs, xs + xsSz, a[i][3]) - xs;
		ev[evSz++] = Event(1, a[i][0], a[i][2], a[i][3]);
		ev[evSz++] = Event(-1, a[i][1], a[i][2], a[i][3]);
	}
	sort(ev, ev + evSz);
	int ans = 0;
	int l = 0;
	while(l < evSz) {
		int r = l;
		while(r < evSz && ev[r].x == ev[l].x) {
			addOnSegm(1, ev[r].y1, ev[r].y2, ev[r].t);
			r++;
		}
		l = r;
		ans = max(ans, tree[1].val);
	}
	printf("%d\n", ans);

	return 0;
}