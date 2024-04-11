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
	int addTo;

	Node() : l(), r(), val(mp(0, 0)), addTo() {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(0, _r - _l)), addTo(0) {}

	void add(int x) {
		val.first += x;
		addTo += x;
	}
};
Node tree[2 * N + 5];
int L;
void build() {
	for (int i = 0; i < L; i++)
		tree[L + i] = Node(i, i + 1);
	for (int i = L - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	assert(v < L);
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].add(tree[v].addTo);
	}
	tree[v].addTo = 0;
}
pii merge(pii v, pii u) {
	if (v.first != u.first) return min(v, u);
	return mp(v.first, v.second + u.second);
}
void update(int v) {
	assert(v < L);
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

void addInVertex(int v, int x) {
	addOnSegm(1, tree[v].l, tree[v].r, x);
}

int n;
char s[N + 5];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);


	scanf("%d %s", &n, s + 1);
	L = 1 << n;
	build();
//	printf("%d\n", tree[1].val.second);
	reverse(s + 1, s + (1 << n));
	for (int i = 1; i < (1 << n); i++) {
		if (s[i] != '?')
			addInVertex(2 * i + (int)(s[i] - '0'), 1);
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int p;
		char c;
		scanf("%d %c", &p, &c);
		p = (1 << n) - p;
		if (s[p] != '?')
			addInVertex(2 * p + (int)(s[p] - '0'), -1);
		s[p] = c;
		if (s[p] != '?')
			addInVertex(2 * p + (int)(s[p] - '0'), 1);
		printf("%d\n", tree[1].val.second);
//		eprintf("%s\n", s + 1);
	}


	return 0;
}