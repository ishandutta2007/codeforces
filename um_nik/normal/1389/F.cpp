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

const int N = 1 << 19;
struct Node {
	int l, r;
	int val;
	int addAll;

	Node() : l(-1), r(-1), val(0), addAll(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), addAll(0) {}

	void add(int x) {
		val += x;
		addAll += x;
	}
};
Node tree[2][2 * N + 5];

void build() {
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N; i++)
			tree[k][N + i] = Node(i, i + 1);
		for (int i = N - 1; i > 0; i--)
			tree[k][i] = Node(tree[k][2 * i].l, tree[k][2 * i + 1].r);
	}
}
void push(int k, int v) {
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[k][u].add(tree[k][v].addAll);
	}
	tree[k][v].addAll = 0;
}
void update(int k, int v) {
	tree[k][v].val = max(tree[k][2 * v].val, tree[k][2 * v + 1].val);
}

void setPoint(int k, int v, int p, int x) {
	if (p < tree[k][v].l || tree[k][v].r <= p) return;
	if (v >= N) {
		tree[k][v].val = max(tree[k][v].val, x);
		return;
	}
	push(k, v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		setPoint(k, u, p, x);
	update(k, v);
}
void addSegm(int k, int v, int l, int r, int x) {
	if (l <= tree[k][v].l && tree[k][v].r <= r) {
		tree[k][v].add(x);
		return;
	}
	if (l >= tree[k][v].r || tree[k][v].l >= r) return;
	push(k, v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addSegm(k, u, l, r, x);
	update(k, v);
}
int getMax(int k, int v, int l, int r) {
	if (l <= tree[k][v].l && tree[k][v].r <= r) return tree[k][v].val;
	if (l >= tree[k][v].r || tree[k][v].l >= r) return 0;
	push(k, v);
	return max(getMax(k, 2 * v, l, r), getMax(k, 2 * v + 1, l, r));
}

int n;
int seg[N][3];
int xs[N];
int xsSz;
vector<pii> a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &seg[i][0], &seg[i][1], &seg[i][2]);
		seg[i][2]--;
		xs[xsSz++] = seg[i][0];
		xs[xsSz++] = seg[i][1];
	}
	xs[xsSz++] = -1;
	sort(xs, xs + xsSz);
	xsSz = unique(xs, xs + xsSz) - xs;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(xs, xs + xsSz, seg[i][0]) - xs;
		int r = lower_bound(xs, xs + xsSz, seg[i][1]) - xs;
		int t = seg[i][2];
		a[r].push_back(mp(l, t));
	}
	int ans = 0;
	for (int x = 0; x < xsSz; x++) {
		for (pii s : a[x]) {
			addSegm(s.second, 1, 0, s.first, 1);
		}
		for (int t = 0; t < 2; t++) {
			int val = getMax(t, 1, 0, x);
			ans = max(ans, val);
			setPoint(t ^ 1, 1, x, val);
		}
	}
	printf("%d\n", ans);

	return 0;
}