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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<ll, int> pli;

const ll INF = (ll)1e18;
const int N = 1 << 20;
struct Node {
	int l, r;
	pli minVal;
	ll toAdd;
	ll cnt;

	Node() : l(), r(), minVal(mp(INF, 10101010)), toAdd(0), cnt(0) {}
	Node(int _l, int _r) : l(_l), r(_r), minVal(mp(INF, _l)), toAdd(0), cnt(0) {}
};
Node tree[2 * N + 7];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void push(int v) {
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].minVal.first += tree[v].toAdd;
		tree[u].toAdd += tree[v].toAdd;
	}
	tree[v].toAdd = 0;
}
void update(int v) {
	if (v >= N) throw;
	tree[v].minVal = min(tree[2 * v].minVal, tree[2 * v + 1].minVal);
}

void setCnt(int v, ll x) {
	v += N;
	tree[v].cnt = x;
	while(v > 1) {
		v >>= 1;
		tree[v].cnt = tree[2 * v].cnt + tree[2 * v + 1].cnt;
	}
}
void addSegm(int v, int l, int r, ll x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].minVal.first += x;
		tree[v].toAdd += x;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	addSegm(2 * v, l, r, x);
	addSegm(2 * v + 1, l, r, x);
	update(v);
}
pli getMin(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].minVal;
	if (l >= tree[v].r || tree[v].l >= r)
		return mp(INF, 10101010);
	push(v);
	return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}
ll getCnt(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].cnt;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	return getCnt(2 * v, l, r) + getCnt(2 * v + 1, l, r);
}

struct Event {
	int l, r;
	ll c, p;

	Event() : l(), r(), c(), p() {}

	void scan() {
		scanf("%d%d%lld%lld", &l, &r, &c, &p);
		l--;
	}

	bool operator < (const Event &e) const {
		return p < e.p;
	}
};

Event ev[N + 5];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	int n, m;
	ll k;
	scanf("%d%lld%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
		setCnt(i, 1);
	addSegm(1, 0, n, k - INF);
	ll ans = 0;
	for (int i = 0; i < m; i++)
		ev[i].scan();
	sort(ev, ev + m);
	for (int i = 0; i < m; i++) {
		int l = ev[i].l, r = ev[i].r;
		ll c = ev[i].c, p = ev[i].p;
		while(true) {
			pli t = getMin(1, l, r);
			if (t.first >= c) break;
			ans += p * t.first;
			setCnt(t.second, 0);
			addSegm(1, t.second, t.second + 1, INF);
		}
		ans += getCnt(1, l, r) * c * p;
		addSegm(1, l, r, -c);
	}
	printf("%lld\n", ans);

	return 0;
}