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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 300300;
ll p2[N], rp2[N];

struct Item {
	int len;
	int lVal, rVal, ans;

	Item() : len(0), lVal(0), rVal(0), ans(0) {}
	Item(int x) : len(1), lVal(x), rVal(x), ans(0) {}
	Item(int _len, int _lVal, int _rVal, int _ans) : len(_len), lVal(_lVal), rVal(_rVal), ans(_ans) {}

	Item operator + (const Item &I) const {
		int nlVal = mult(I.lVal, p2[len]);
		int nrVal = mult(I.rVal, rp2[len]);
		return Item(len + I.len, add(lVal, nlVal), add(rVal, nrVal), add(add(ans, I.ans), mult(lVal, nrVal)));
	}
};

struct Node {
	pii x;
	int y;
	int L, R;
	Item val;

	Node() : x(), y((ll)rng()), L(-1), R(-1), val() {}
	Node(pii _x) : x(_x), y((ll)rng()), L(-1), R(-1), val(Item(_x.first)) {}
};
Node tree[N];

int update(int v) {
	if (v == -1) return -1;
	Item I = Item(tree[v].x.first);
	if (tree[v].L != -1) I = tree[tree[v].L].val + I;
	if (tree[v].R != -1) I = I + tree[tree[v].R].val;
	tree[v].val = I;
	return v;
}

int merge(int L, int R) {
	if (L == -1) return R;
	if (R == -1) return L;
	if (tree[L].y > tree[R].y) {
		tree[L].R = merge(tree[L].R, R);
		return update(L);
	} else {
		tree[R].L = merge(L, tree[R].L);
		return update(R);
	}
}
void split(int v, pii x, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	if (tree[v].x >= x) {
		split(tree[v].L, x, L, tree[v].L);
		R = update(v);
	} else {
		split(tree[v].R, x, tree[v].R, R);
		L = update(v);
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < N; i++)
		p2[i] = add(p2[i - 1], p2[i - 1]);
	rp2[0] = 1;
	for (int i = 1; i < N; i++) {
		rp2[i] = rp2[i - 1];
		if (rp2[i] & 1) rp2[i] += MOD;
		rp2[i] /= 2;
	}

	int n;
	scanf("%d", &n);
	//n = 300000;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		//x = abs((int)rng()) % MOD;
		tree[i] = Node(mp(x, i));
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		int L, R;
		split(root, tree[i].x, L, R);
		root = merge(merge(L, i), R);
	}
//	printTree(root);
	printf("%d\n", mult(tree[root].val.ans, rp2[1]));
	int q;
	scanf("%d", &q);
//	q = 300000;
	while(q--) {
		int L, M, R;
		int p;
		ll x;
		scanf("%d%lld", &p, &x);
		//p = 1 + abs((int)rng()) % n;
		//x = abs((int)rng()) % MOD;
		p--;
		pli t = tree[p].x;
		split(root, t, L, M);
		t.second++;
		split(M, t, M, R);
		root = merge(L, R);
		tree[p] = Node(mp(x, p));
		split(root, mp(x, p), L, R);
		root = merge(merge(L, p), R);
		printf("%d\n", mult(tree[root].val.ans, rp2[1]));
//		printTree(root);
	}

	return 0;
}