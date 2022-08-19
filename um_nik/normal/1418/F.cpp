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
	pii val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(N, _l)) {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void mySet(int p, int x) {
	tree[p + N].val = mp(x, p);
	p += N;
	while(p > 1) {
		p >>= 1;
		tree[p].val = min(tree[2 * p].val, tree[2 * p + 1].val);
	}
}
pii getMin(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp(N, N);
	return min(getMin(2 * v, l, r), getMin(2 * v + 1, l, r));
}

int n, m;
ll L, R;
vector<int> ANS[N + 5];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%lld%lld", &n, &m, &L, &R);
	build();
	for (int d = max(n, m); d >= 1; d--) {
		for (int x = d; x <= n; x += d) {
			ll l = (L + x - 1) / x, r = R / x;
			r = min(r, (ll)m) + 1;
			if (l >= r) continue;
			pii val = getMin(1, l, r);
			if (val.first == N) continue;
			int y1 = val.second;
			ll x2 = (ll)x / d * val.first;
			if (x2 <= n) {
				ANS[x] = {x, y1, (int)x2, (int)((ll)x * y1 / x2)};
			}
		}
		for (int y = d; y <= m; y += d)
			mySet(y, d);
	}
	for (int x = 1; x <= n; x++) {
		if (ANS[x].empty()) {
			printf("-1\n");
		} else {
			printf("%d %d %d %d\n", ANS[x][0], ANS[x][1], ANS[x][2], ANS[x][3]);
		}
	}

	return 0;
}