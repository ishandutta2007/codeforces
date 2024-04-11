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

const int N = (1 << 19);
int n, m;
int a[N];
bool flp[20];
struct Node {
	int l, r, val;

	Node() : l(), r(), val(0) {}
	Node(int _l, int _r) : l(_l), r(_r), val(0) {}
};
Node tree[2 * N];
void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void addPoint(int v, int i) {
	tree[v].val++;
	if (tree[v].l + 1 == tree[v].r) return;
	if (i < tree[2 * v].r) addPoint(2 * v, i);
	else addPoint(2 * v + 1, i);
}
int walk(int v, int d) {
	if (tree[v].l + 1 == tree[v].r) return tree[v].l;
	int x = 2 * v, y = 2 * v + 1, b = 0;
	if (flp[d]) swap(x, y), b = (1 << d);
	if (tree[x].val == tree[x].r - tree[x].l) return walk(y, d - 1) ^ b;
	else return walk(x, d - 1) ^ b;
}

int main()
{
	startTime = clock();

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	build();
	sort(a, a + n);
	for (int i = 0; i < n; i++) 
		if (i == 0 || a[i] != a[i - 1])
			addPoint(1, a[i]);
	for (int i = 0; i < 20; i++)
		flp[i] = false;
	while(m--) {
		int x;
		scanf("%d", &x);
		for (int i = 0; i < 20; i++)
			if ((x >> i) & 1)
				flp[i] = !flp[i];
		printf("%d\n", walk(1, 18));
	}

	return 0;
}