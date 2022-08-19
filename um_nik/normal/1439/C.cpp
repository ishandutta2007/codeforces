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

const int N = 1 << 18;
struct Node {
	int l, r;
	ll sum, mx, mn;
	ll toSet;

	Node() : l(), r(), sum(0), mx(0), mn(0), toSet(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), sum(0), mx(0), mn(0), toSet(-1) {}

	void set(ll x) {
		toSet = x;
		mx = mn = x;
		sum = x * (r - l);
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
	if (tree[v].toSet == -1) return;
	for (int u = 2 * v; u < 2 * v + 2; u++)
		tree[u].set(tree[v].toSet);
	tree[v].toSet = -1;
}
void update(int v) {
	assert(v < N);
	tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
	tree[v].mx = max(tree[2 * v].mx, tree[2 * v + 1].mx);
	tree[v].mn = min(tree[2 * v].mn, tree[2 * v + 1].mn);
}

void setOnSegm(int v, int l, int r, ll x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].set(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		setOnSegm(u, l, r, x);
	}
	update(v);
}

int getFirstLower(int v, int l, ll x) {
	if (l >= tree[v].r) return N;
	if (x >= tree[v].mx) return max(l, tree[v].l);
	if (v >= N) return N;
	push(v);
	if (tree[2 * v + 1].mx > x)
		return getFirstLower(2 * v + 1, l, x);
	int res = getFirstLower(2 * v, l, x);
	if (res == N)
		return getFirstLower(2 * v + 1, l, x);
	else
		return res;
}

void goRight(int v, int l, int r, ll &sum, int &cnt) {
	if (tree[v].mn > sum) return;
	if (l >= tree[v].r || tree[v].l >= r) return;
	if (l <= tree[v].l && tree[v].r <= r && tree[v].sum <= sum) {
		sum -= tree[v].sum;
		cnt += tree[v].r - tree[v].l;
		return;
	}
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		goRight(u, l, r, sum, cnt);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		setOnSegm(1, i, i + 1, x);
	}
	while(q--) {
		int t, x;
		ll y;
		scanf("%d%d%lld", &t, &x, &y);
		if (t == 1) {
			int l = getFirstLower(1, 0, y);
			if (l < x)
				setOnSegm(1, l, x, y);
		} else {
			x--;
			int cnt = 0;
			goRight(1, x, n, y, cnt);
			printf("%d\n", cnt);
		}
	}

	return 0;
}