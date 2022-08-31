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

const int N = 1 << 19;
struct Node {
	int l, r;
	pii val;
	int toAdd;

	Node() : l(-1), r(-1), val(mp(N, 1)), toAdd(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(N, _r - _l)), toAdd(0) {}

	void add(int x) {
		toAdd += x;
		val.first += x;
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
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].add(tree[v].toAdd);
	}
	tree[v].toAdd = 0;
}
pii merge(pii v, pii u) {
	pii res;
	res.first = min(v.first, u.first);
	res.second = 0;
	if (res.first == v.first) res.second += v.second;
	if (res.first == u.first) res.second += u.second;
	return res;
}
void update(int v) {
	if (v >= N) throw;
	tree[v].val = merge(tree[2 * v].val, tree[2 * v + 1].val);
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
pii getVal(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp(N, 0);
	push(v);
	return merge(getVal(2 * v, l, r), getVal(2 * v + 1, l, r));
}

int n;
int a[N + 5];
int lst[N + 5];
int st[N + 5][2];
int stSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; i++)
		lst[i] = -1;
	build();
	st[stSz][0] = N;
	st[stSz][1] = -1;
	stSz++;
	ll ans = 0;
	int L = 0;
	for (int r = 1; r <= n; r++) {
		int x = a[r - 1];
		L = max(L, lst[x] + 1);
		lst[x] = r - 1;
		int p = r - 1;
		while(st[stSz - 1][0] < x) {
			stSz--;
			addOnSegm(1, st[stSz][1], p, -st[stSz][0]);
			p = st[stSz][1];
		}
		addOnSegm(1, p, r, x);
		st[stSz][0] = x;
		st[stSz][1] = p;
		stSz++;
		addOnSegm(1, r - 1, r, r - 1 - N);
		pii val = getVal(1, L, r);
//		printf("%d %d %d %d\n", L, r, val.first, val.second);
		if (val.first == r)
			ans += val.second;
	}
	printf("%lld\n", ans);

	return 0;
}