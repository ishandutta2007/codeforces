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
	pii val;
	int addTo;

	Node() : l(), r(), val(mp(N, N)), addTo(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(0, _l)), addTo(0) {}

	void add(int x) {
		val.first += x;
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
pii getMin(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp(N, N);
	push(v);
	return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}


struct Fenwick {
	vector<int> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<int>(n, 0)) {}

	void add(int p, int x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	int get(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	int getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} fenv;


int n, q;
int ans[N + 5];
vector<pii> Q[N + 5];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	build();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x = i + 1 - x;
		if (x < 0) x = N;
		addOnSegm(1, i, i + 1, x);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		r = n - r;
		Q[l].push_back(mp(r, i));
	}
	fenv = Fenwick(n);
	for (int l = n - 1; l >= 0; l--) {
		while(true) {
			pii p = getMin(1, l, n);
			if (p.first > 0) break;
			int pos = p.second;
			addOnSegm(1, pos, n, -1);
			addOnSegm(1, pos, pos + 1, N);
			fenv.add(pos, 1);
		}
		for (pii p : Q[l]) {
			ans[p.second] = fenv.getSum(l, p.first);
		}
	}
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}