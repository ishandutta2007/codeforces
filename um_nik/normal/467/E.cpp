#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
	int l, r, val;

	Node() : l(), r(), val(N) {}
	Node(int _l, int _r) : l(_l), r(_r), val(N) {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void setPoint(int v, int x) {
	v += N;
	tree[v].val = x;
	while(v > 1) {
		v >>= 1;
		tree[v].val = min(tree[2 * v].val, tree[2 * v + 1].val);
	}
}

int getLeftMostLower(int v, int l, int r, int x) {
	if (tree[v].val >= x) return N;
	if (r <= tree[v].l || tree[v].r <= l) return N;
	if (v >= N) return v - N;
	int res = getLeftMostLower(2 * v, l, r, x);
	if (res != N) return res;
	return getLeftMostLower(2 * v + 1, l, r, x);
}

int a[N + 5];
int n;
int xs[N + 5];
int xsSz;
int bestFromHere[N + 5];
pii www[N + 5];
int bestOnSuf[N + 5];
int lst[N + 5];
int nxt[N + 5];
int ans[N + 5];
int ansSz;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		xs[i] = a[i];
	}
	sort(xs, xs + n);
	xsSz = unique(xs, xs + n) - xs;
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(xs, xs + xsSz, a[i]) - xs;
	}
	build();
	for (int i = 0; i < xsSz; i++)
		lst[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		bestFromHere[i] = n;
		nxt[i] = lst[x];
		lst[x] = i;
	}
	nxt[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		if (nxt[i] == n) continue;
		int p = nxt[i];
		int zz = nxt[nxt[p]];
		if (zz < n) {
			bestFromHere[i] = zz;
			www[i] = mp(a[i], a[i]);
		}
		int q = getLeftMostLower(1, p + 1, n, p);
		if (q < bestFromHere[i]) {
			bestFromHere[i] = q;
			www[i] = mp(a[i], a[q]);
		}
		setPoint(p, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		bestOnSuf[i] = bestFromHere[i];
		if (i + 1 < n && bestOnSuf[i] > bestOnSuf[i + 1]) {
			bestOnSuf[i] = bestOnSuf[i + 1];
			www[i] = www[i + 1];
		}
	}

	int x = 0;
	while(x < n && bestOnSuf[x] < n) {
		ans[ansSz++] = xs[www[x].first];
		ans[ansSz++] = xs[www[x].second];
		ans[ansSz++] = xs[www[x].first];
		ans[ansSz++] = xs[www[x].second];
		x = bestOnSuf[x] + 1;
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}