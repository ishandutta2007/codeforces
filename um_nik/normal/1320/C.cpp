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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)1e18;
const int N = (1 << 18);

struct Node {
	int l, r;
	ll toAdd;
	ll val;

	Node() : l(), r(), toAdd(0), val(-INF) {}
	Node(int _l, int _r) : l(_l), r(_r), toAdd(0), val(-INF) {}

	void add(ll x) {
		toAdd += x;
		val += x;
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
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].add(tree[v].toAdd);
	}
	tree[v].toAdd = 0;
}
void update(int v) {
	if (v >= N) throw;
	tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
}

void addSegm(int v, int l, int r, ll x) {
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

ll ans = -INF;
pll a[N + 5];

struct Event {
	int t;
	ll x, y, z;

	Event() : t(), x(), y(), z() {}
	Event(int _t, ll _x, ll _y, ll _z) : t(_t), x(_x), y(_y), z(_z) {}

	bool operator < (const Event &e) const {
		if (x != e.x) return x < e.x;
		return t < e.t;
	}
};
Event ev[2 * N + 5];
int evSz;


int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		addSegm(1, i, i + 1, INF - a[i].second);

	for (int i = 0; i < m; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ev[evSz++] = Event(0, x, x, y);
	}
	for (int i = 0; i < k; i++) {
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		ev[evSz++] = Event(1, y, x, z);
	}
	sort(ev, ev + evSz);
	ans = -INF;
	for (int i = 0; i < evSz; i++) {
		if (ev[i].t == 0) {
			ans = max(ans, tree[1].val - ev[i].z);
		} else {
			int p = lower_bound(a, a + n, mp(ev[i].y, INF)) - a;
			addSegm(1, p, n, ev[i].z);
		}
	}
	printf("%lld\n", ans);

	return 0;
}