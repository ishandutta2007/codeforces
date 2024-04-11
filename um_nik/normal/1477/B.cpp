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
	int sum;
	int setTo;

	Node() : l(), r(), sum(0), setTo(-1) {}
	Node(int _l, int _r) : l(_l), r(_r), sum(0), setTo(-1) {}

	void set(int x) {
		setTo = x;
		sum = x * (r - l);
	}
};
Node tree[2 * N + 5];
int L;

void build(int n) {
	L = max(n, 2);
	while(L & (L - 1)) L++;
	for (int i = 0; i < L; i++)
		tree[L + i] = Node(i, i + 1);
	for (int i = L - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void push(int v) {
	assert(v < L);
	if (tree[v].setTo == -1) return;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[u].set(tree[v].setTo);
	}
	tree[v].setTo = -1;
}
void update(int v) {
	assert(v < L);
	tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
}

void setOnSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].set(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		setOnSegm(u, l, r, x);
	update(v);
}
int getSum(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].sum;
	if (l >= tree[v].r || tree[v].l >= r)
		return 0;
	push(v);
	return getSum(2 * v, l, r) + getSum(2 * v + 1, l, r);
}

int n, q;
char a[N + 5], b[N + 5];
int c[N + 5][2];

bool solve() {
	scanf("%d%d", &n, &q);
	build(n);
	scanf("%s", a);
	scanf("%s", b);
	for (int i = 0; i < n; i++)
		setOnSegm(1, i, i + 1, (int)(b[i] - '0'));
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &c[i][0], &c[i][1]);
		c[i][0]--;
	}
	for (int i = q - 1; i >= 0; i--) {
		int sum = getSum(1, c[i][0], c[i][1]);
		if (2 * sum == c[i][1] - c[i][0]) return false;
		if (2 * sum < c[i][1] - c[i][0])
			setOnSegm(1, c[i][0], c[i][1], 0);
		else
			setOnSegm(1, c[i][0], c[i][1], 1);
	}
	for (int i = 0; i < n; i++)
		if (getSum(1, i, i + 1) != (int)(a[i] - '0'))
			return false;
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}