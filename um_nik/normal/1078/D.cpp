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

const int LOG = 17;
const pii INF = mp((int)1e8, -(int)1e8);
const int N = 1 << LOG;

struct Node {
	int l, r;
	pii val;

	Node() : l(), r(), val(INF) {}
	Node(int _l, int _r) : l(_l), r(_r), val(INF) {}
};
Node tree[LOG][2 * N + 5];

pii merge(pii a, pii b) {
	return mp(min(a.first, b.first), max(a.second, b.second));
}

void build() {
	for (int k = 0; k < LOG; k++) {
		for (int i = 0; i < N; i++)
			tree[k][N + i] = Node(i, i + 1);
		for (int i = N - 1; i > 0; i--)
			tree[k][i] = Node(tree[k][2 * i].l, tree[k][2 * i + 1].r);
	}
}

void setPoint(int k, int v, pii x) {
	v += N;
	tree[k][v].val = x;
	while(v > 1) {
		v >>= 1;
		tree[k][v].val = merge(tree[k][2 * v].val, tree[k][2 * v + 1].val);
	}
}

pii getVal(int k, int v, int l, int r) {
	if (l <= tree[k][v].l && tree[k][v].r <= r)
		return tree[k][v].val;
	if (l >= tree[k][v].r || tree[k][v].l >= r)
		return INF;
	return merge(getVal(k, 2 * v, l, r), getVal(k, 2 * v + 1, l, r));
}

int n;

pii getSegm(int k, int L, int R) {
	int l = L, r = R - 1;
	pii t;
	if (L < 0) {
		t = getVal(k, 1, L + n, n);
		l = min(l, t.first - n);
		r = max(r, t.second - n);
	}
	t = getVal(k, 1, max(0, L), min(n, R));
	l = min(l, t.first);
	r = max(r, t.second);
	if (R > n) {
		t = getVal(k, 1, 0, R - n);
		l = min(l, t.first + n);
		r = max(r, t.second + n);
	}
	return mp(l, r);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();

	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int l = i - x, r = i + x;
		setPoint(0, i, mp(l, r));
	}
	for (int k = 0; k < LOG - 1; k++) {
		for (int i = 0; i < n; i++) {
			pii t = getVal(k, 1, i, i + 1);
			int L = t.first, R = t.second + 1;
			if (R - L >= n) {
				setPoint(k + 1, i, t);
				continue;
			}
			t = getSegm(k, L, R);
			setPoint(k + 1, i, t);
		}
	}
	for (int i = 0; i < n; i++) {
		int ans = 0;
		int L = i, R = i + 1;
		for (int k = LOG - 1; k >= 0; k--) {
			pii cur = getSegm(k, L, R);
			int LL = cur.first, RR = cur.second + 1;
			if (RR - LL < n) {
				L = LL;
				R = RR;
				ans += 1 << k;
			}
		}
		printf("%d ", ans + 1);
	}
	printf("\n");

	return 0;
}