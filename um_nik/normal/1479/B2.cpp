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

const int N = 1 << 17;
struct Node {
	int l, r;
	int val;
	int addTo;

	Node() : l(), r(), val(N), addTo(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(N), addTo(0) {}

	void add(int x) {
		val += x;
		addTo += x;
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
	assert(v < N);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].add(tree[v].addTo);
	tree[v].addTo = 0;
}
void update(int v) {
	assert(v < N);
	tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
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
int getMin(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return N;
	push(v);
	return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}
void setP(int v, int p, int x) {
	if (p < tree[v].l || tree[v].r <= p) return;
	if (v >= N) {
		tree[v].val = x;
		return;
	}
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		setP(u, p, x);
	update(v);
}

int a[N + 5];
int n;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build();
	setP(1, 0, 1);
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int y = a[i - 1];
		int w = getMin(1, 0, n + 1) + 1;
		w = min(w, getMin(1, x, x + 1));
		if (x != y) addOnSegm(1, 0, n + 1, 1);
		w = min(w, getMin(1, y, y + 1));
		setP(1, y, w);
	}
	printf("%d\n", getMin(1, 0, n + 1));

	return 0;
}