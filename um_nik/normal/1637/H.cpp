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
const int INF = (int)1e7;
struct Node {
	int l, r;
	pii val;

	Node() : l(), r(), val(mp(INF, 0)) {}
	Node(int _l, int _r) : l(_l), r(_r), val(mp(INF, _l)) {}
};
Node tree[2][2 * N + 5];
int L;
void build(int n) {
	L = max(n, 2);
	while(L & (L - 1)) L++;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < L; i++)
			tree[k][L + i] = Node(i, i + 1);
		for (int i = L - 1; i > 0; i--)
			tree[k][i] = Node(tree[k][2 * i].l, tree[k][2 * i + 1].r);
	}
}
void setPoint(int k, int v, int x) {
	v += L;
	tree[k][v].val.first = x;
	while(v > 1) {
		v >>= 1;
		tree[k][v].val = min(tree[k][2 * v].val, tree[k][2 * v + 1].val);
	}
}
pii getMin(int k, int v, int l, int r) {
	if (l <= tree[k][v].l && tree[k][v].r <= r) return tree[k][v].val;
	if (l >= tree[k][v].r || tree[k][v].l >= r) return mp(INF, 0);
	return min(getMin(k, 2 * v, l, r), getMin(k, 2 * v + 1, l, r));
}


struct Fenwick {
	vector<int> fenv;

	Fenwick() : fenv() {}
	Fenwick(int n) : fenv(vector<int>(n, 0)) {}

	void add(int p, int x) {
		for(; p < (int)fenv.size(); p |= p + 1)
			fenv[p] += x;
	}
	int get(int r) {
		int res = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += fenv[r];
		return res;
	}
	int getSum(int l, int r) {
		if (l >= r) return 0;
		return get(r - 1) - get(l - 1);
	}
} F1, F2;


int n;
int p[N + 5];
int initInv[N + 5];
bool act[N + 5];
set<int> active;

int getScore(int v, int it) {
	int y = F2.get(p[v]) - F1.get(v);
	int res = v - 2 * initInv[v] + 2 * y;
	//eprintf("getScore %d %d = %d\n", v, it, res);
	return res;
}
void activate(int l, int it) {
	while(true) {
		l++;
		pii t = getMin(1, 1, l, n);
		if (t.first >= INF) break;
		l = t.second;
		if (act[l]) break;
		//eprintf("activate %d\n", l);
		act[l] = 1;
		active.insert(l);
		setPoint(0, l, getScore(l, it));
	}
}

void solve() {
	//eprintf("SOLVE\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	build(n);
	F1 = Fenwick(n);
	F2 = Fenwick(n);
	ll ANS = 0;
	for (int i = 0; i < n; i++) {
		initInv[i] = i - F1.get(p[i]);
		F1.add(p[i], 1);
		ANS += initInv[i];
	}
	printf("%lld", ANS);
	for (int i = 0; i < n; i++) {
		act[i] = 0;
		setPoint(1, i, p[i]);
	}
	active.clear();
	active.insert(-1);
	F1 = Fenwick(n);
	activate(-1, 0);
	for (int it = 1; it <= n; it++) {
		pii t = getMin(0, 1, 0, n);
		ANS += t.first - it + 1;
		printf(" %lld", ANS);
		int v = t.second;
		//printf("move %d\n", v);
		setPoint(0, v, INF);
		auto itt = active.lower_bound(v);
		assert(itt != active.end() && *itt == v);
		int l = *prev(itt);
		active.erase(v);
		setPoint(1, v, INF);
		F1.add(v, 1);
		F2.add(p[v], 1);
		activate(l, it);
	}
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}