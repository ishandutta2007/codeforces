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
#include <array>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = (1 << 21);
struct Node {
	int l, r;
	ll add;
	pair<ll, int> val;

	Node() : l(0), r(0), val({0ll, 0}), add(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val({0ll, _l}), add(0) {}

	void addVal(ll x) {
		val.fi += x;
		add += x;
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
		if (u < 2 * N)
			tree[u].addVal(tree[v].add);
	tree[v].add = 0;
}
void rangeAdd(int v, int l, int r, int x) {
	assert(v < 2 * N);
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].addVal(x);
		push(v);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	rangeAdd(2 * v, l, r, x);
	rangeAdd(2 * v + 1, l, r, x);
	tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
}
pair<ll, int> get(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp((ll)(-1e15), l);
	push(v);
	tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
	return max(get(2 * v, l, r), get(2 * v + 1, l, r));
}

const int M = 500050;
int n;
int x[M];
int y[M];
int c[M];
vector<int> Qs[M * 2];

int main()
{
	startTime = clock();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
	vector<int> xs;
	for (int i = 0; i < n; i++) {
		xs.pb(x[i]);
		xs.pb(y[i]);
	}
	sort(all(xs));
	xs.erase(unique(all(xs)), xs.end());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(all(xs), x[i]) - xs.begin();
		y[i] = lower_bound(all(xs), y[i]) - xs.begin();
		Qs[min(x[i], y[i])].pb(i);
	}
	build();
	for (int i = 0; i < xs.size(); i++)
		rangeAdd(1, i, i + 1, -xs[i]);
	for (int i = 0; i < n; i++)
		rangeAdd(1, max(x[i], y[i]), xs.size(), c[i]);	
	int l = 1e9 + 5, r = 1e9 + 5;
	ll ans = 0;
	for (int i = 0; i < xs.size(); i++) {
		auto best = get(1, i, xs.size());
		if (best.fi + xs[i] > ans) {
			ans = best.fi + xs[i];
			l = xs[i];
			r = xs[best.se];
		}
		for (int j : Qs[i]) rangeAdd(1, max(x[j], y[j]), xs.size(), -c[j]);
	}
	printf("%lld\n%d %d %d %d", ans, l, l, r, r);
	return 0;
}