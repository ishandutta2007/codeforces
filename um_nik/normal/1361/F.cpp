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
//mt19937_64 rng(0);

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

const int C = (int)1e9;
struct Node {
	int L, R;
	int x, y;
	int sz;

	Node() : L(-1), R(-1), x(), y(myRand(C)), sz(0) {}
	Node(int _x) : L(-1), R(-1), x(_x), y(myRand(C)), sz(1) {}
};
#ifdef LOCAL
	const int S = (int)1e3;
#else
	const int S = (int)20e6;
#endif
Node tree[S];
int freeNodes[S];
int freeSz;

int newNode(int x) {
	assert(freeSz > 0);
	freeSz--;
	int v = freeNodes[freeSz];
	tree[v] = Node(x);
	return v;
}
void deleteNode(int v) {
	freeNodes[freeSz++] = v;
}

int getSize(int v) {
	return v == -1 ? 0 : tree[v].sz;
}
int update(int v) {
	tree[v].sz = 1 + getSize(tree[v].L) + getSize(tree[v].R);
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
void split(int v, int x, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	if (tree[v].x < x) {
		split(tree[v].R, x, tree[v].R, R);
		L = update(v);
	} else {
		split(tree[v].L, x, L, tree[v].L);
		R = update(v);
	}
}

const int N = 200200;
int p[N];
int ord[N];
vector<pii> forPos[N];
ll ans[N][2];
ll ANS;
int roots[N][2];
int n;

void addNum(int pos, int x) {
	//eprintf("addNum %d %d\n", pos, x);
	for (pii t : forPos[pos]) {
		int id = t.first;
		int q = t.second;
		ANS -= min(ans[id][0], ans[id][1]);
		int L, R;
		split(roots[id][q ^ 1], x, L, R);
		ans[id][q] += getSize(L);
		roots[id][q ^ 1] = merge(L, R);
		split(roots[id][q], x, L, R);
		roots[id][q] = merge(L, merge(newNode(x), R));
		ans[id][q ^ 1] = (ll)getSize(roots[id][q]) * getSize(roots[id][q ^ 1]) - ans[id][q];
		ANS += min(ans[id][0], ans[id][1]);
	}
}
void delNum(int pos, int x) {
	//eprintf("delNum %d %d\n", pos, x);
	for (pii t : forPos[pos]) {
		int id = t.first;
		int q = t.second;
		ANS -= min(ans[id][0], ans[id][1]);
		int L, R;
		split(roots[id][q ^ 1], x, L, R);
		ans[id][q] -= getSize(L);
		roots[id][q ^ 1] = merge(L, R);
		split(roots[id][q], x, L, R);
		int M;
		split(R, x + 1, M, R);
		roots[id][q] = merge(L, R);
		assert(M != -1);
		deleteNode(M);
		ans[id][q ^ 1] = (ll)getSize(roots[id][q]) * getSize(roots[id][q ^ 1]) - ans[id][q];
		ANS += min(ans[id][0], ans[id][1]);
	}
}

void eprintTree(int v) {
	if (v == -1) return;
	eprintTree(tree[v].L);
	eprintf("%d ", tree[v].x);
	eprintTree(tree[v].R);
}

void eprintAll() {
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 2; j++) {
			eprintf("[%d %d]\n", i, j);
			eprintTree(roots[i][j]);
			eprintf("\n-----------\n");
		}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < S; i++)
		freeNodes[freeSz++] = S - 1 - i;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i < n; i++) {
		int x;
		scanf("%d", &x);
		ord[x] = i;
	}
	set<pii> segms;
	for (int i = 0; i < n; i++)
		segms.insert(mp(i, i + 1));
	for (int i = n - 1; i > 0; i--) {
		auto it = segms.lower_bound(mp(ord[i], -1));
		assert(it != segms.end());
		assert(it != segms.begin());
		pii R = *it;
		it--;
		pii L = *it;
		segms.erase(L);
		segms.erase(R);
		for (int x = L.first; x < L.second; x++)
			forPos[x].push_back(mp(i, 0));
		for (int x = R.first; x < R.second; x++)
			forPos[x].push_back(mp(i, 1));
		segms.insert(mp(L.first, R.second));
	}
	for (int i = 1; i < n; i++)
		roots[i][0] = roots[i][1] = -1;
	for (int i = 0; i < n; i++)
		addNum(i, p[i]);

	eprintf("%lld\n", ANS);
//	eprintAll();

	int q;
	scanf("%d", &q);
	while(q--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		if (v != u) {
			delNum(v, p[v]);
			delNum(u, p[u]);
			//eprintAll();
			swap(p[v], p[u]);
			addNum(v, p[v]);
			addNum(u, p[u]);
		}
		printf("%lld\n", ANS);
		//eprintAll();
	}

	return 0;
}