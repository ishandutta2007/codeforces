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

pii merge(pii v, pii u) {
	if (v.first == u.first) {
		return mp(v.first, v.second + u.second);
	} else {
		if (v.second > u.second)
			return mp(v.first, v.second - u.second);
		else
			return mp(u.first, u.second - v.second);
	}
}

struct Node {
	int l, r;
	pii val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r) : l(_l), r(_r), val() {}
};
const int N = 1 << 19;
Node tree[2 * N + 5];
int a[N + 5];
int n;
vector<int> pos[N + 5];

void build() {
	for (int i = 0; i < N; i++) {
		tree[N + i] = Node(i, i + 1);
		tree[N + i].val = mp(a[i], 1);
	}
	for (int i = N - 1; i > 0; i--) {
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		tree[i].val = merge(tree[2 * i].val, tree[2 * i + 1].val);
	}
}

pii getSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return mp(0, 0);
	return merge(getSegm(2 * v, l, r), getSegm(2 * v + 1, l, r));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	build();
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		pii val = getSegm(1, l, r);
		int c = val.first;
		int occ = lower_bound(all(pos[c]), r) - lower_bound(all(pos[c]), l);
		int ans = max(1, 2 * occ - (r - l));
		printf("%d\n", ans);
	}

	return 0;
}