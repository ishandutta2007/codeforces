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

const int N = (1 << 17);
struct Node {
	int l, r;
	int val;

	Node() : l(), r(), val(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), val(-1) {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void setInPoint(int p, int x) {
	p += N;
	tree[p].val = x;
	while(p > 1) {
		p >>= 1;
		tree[p].val = min(tree[2 * p].val, tree[2 * p + 1].val);
	}
}
int minOnSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r) return N;
	return min(minOnSegm(2 * v, l, r), minOnSegm(2 * v + 1, l, r));
}

int n;
int a[N + 5];
int lst[N + 5];
bool ans[N + 5];

int getMex(int l) {
	int v = 1;
	while(v < N) {
		assert(tree[v].val < l);
		v *= 2;
		if (tree[v].val >= l) v++;
	}
	return v - N;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int i = 0; i < n; i++)
		lst[i] = -1;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		int l = lst[x];
		if (l + 1 < i) {
			//eprintf("%d %d\n", l + 1, i);
			ans[getMex(l + 1)] = 1;
		}
		setInPoint(x, i);
		lst[x] = i;
	}
	ans[getMex(0)] = 1;
	for (int x = 0; x < n; x++)
		if (lst[x] + 1 < n)
			ans[getMex(lst[x] + 1)] = 1;
	int x = 0;
	while(ans[x]) x++;
	printf("%d\n", x + 1);

	return 0;
}