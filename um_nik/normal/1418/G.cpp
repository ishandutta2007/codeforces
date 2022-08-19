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

const int INF = (int)1e8;
const int N = 1 << 19;
struct Node {
	int l, r;
	pii val;
	int addAll;

	Node() : l(), r(), val(), addAll(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(0, _r - _l)), addAll(0) {}

	void add(int x) {
		addAll += x;
		val.first += x;
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
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].add(tree[v].addAll);
	}
	tree[v].addAll = 0;
}
pii merge(pii v, pii u) {
	if (v.first != u.first) return min(v, u);
	return mp(v.first, v.second + u.second);
}
void update(int v) {
	assert(v < N);
	tree[v].val = merge(tree[2 * v].val, tree[2 * v + 1].val);
}
void addSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].add(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addSegm(u, l, r, x);
	update(v);
}
pii getMin(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp(INF, 0);
	push(v);
	return merge(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}

const int M = 500500;
int n;
int a[N];
vector<int> forX[N];
int b[N];
int lst[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		forX[a[i]].push_back(i);
	}
	for (int i = 0; i <= n; i++)
		b[i] = n;
	for (int x = 0; x < n; x++) {
		for (int i = 3; i < (int)forX[x].size(); i++) {
			b[forX[x][i - 3]] = min(b[forX[x][i - 3]], forX[x][i]);
		}
	}
	for (int i = n - 1; i >= 0; i--)
		b[i] = min(b[i], b[i + 1]);

//	for (int i = 0; i <= n; i++)
//		eprintf("%d ", b[i]);
//	eprintf("\n");

	build();
	for (int i = 0; i <= n; i++)
		addSegm(1, i, i + 1, -i);
	ll ans = 0;
	for (int x = 0; x < n; x++)
		lst[x] = n;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		addSegm(1, i + 1, lst[x] + 1, 3);
		lst[x] = i;
		pii val = getMin(1, i + 1, b[i] + 1);
//		eprintf("%d %d %d\n", i, val.first, val.second);
		if (val.first == -i) ans += val.second;
	}
	printf("%lld\n", ans);

	return 0;
}