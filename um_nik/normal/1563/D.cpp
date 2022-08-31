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


const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 400200;
ll f[N], rf[N];

struct Node {
	int x, y;
	int L, R;
	int sz;
	int addTo;

	Node() : x(), y(myRand(MOD)), L(-1), R(-1), sz(1), addTo(0) {}
	Node(int _x) : x(_x), y(myRand(MOD)), L(-1), R(-1), sz(1), addTo(0) {}

	void add(int d) {
		x += d;
		addTo += d;
	}
};
Node tree[N];
int treeSz;


void addTree(int v, int d) {
	if (v == -1) return;
	tree[v].add(d);
}

int getSize(int v) {
	return v == -1 ? 0 : tree[v].sz;
}
int update(int v) {
	tree[v].sz = 1 + getSize(tree[v].L) + getSize(tree[v].R);
	return v;
}
void push(int v) {
	addTree(tree[v].L, tree[v].addTo);
	addTree(tree[v].R, tree[v].addTo);
	tree[v].addTo = 0;
}

void split(int v, int x, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	push(v);
	if (tree[v].x < x) {
		split(tree[v].R, x, tree[v].R, R);
		L = update(v);
	} else {
		split(tree[v].L, x, L, tree[v].L);
		R = update(v);
	}
}
int merge(int L, int R) {
	if (L == -1) return R;
	if (R == -1) return L;
	push(L);
	push(R);
	if (tree[L].y > tree[R].y) {
		tree[L].R = merge(tree[L].R, R);
		return update(L);
	} else {
		tree[R].L = merge(L, tree[R].L);
		return update(R);
	}
}


void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n == 1) {
		printf("1\n");
		return;
	}
	treeSz = 0;
	int root = -1;
	while(m--) {
		int x;
		scanf("%d", &x);
		scanf("%d", &x);
		int L, M, R;
		split(root, x, L, M);
		split(M, x + 1, M, R);
		if (M == -1) {
			tree[treeSz] = Node(x);
			M = treeSz++;
		}
		M = merge(M, R);
		addTree(M, 1);
		root = merge(L, M);
	}
	m = n - 1 - getSize(root);
	eprintf("%d %d\n", m, n);
	printf("%lld\n", mult(f[n + m], mult(rf[n], rf[m])));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}