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


struct Change {
	int* pos;
	int val;

	Change() : pos(), val() {}
	Change(int* _pos, int _val) : pos(_pos), val(_val) {}

	void apply() const {
		*pos = val;
	}
};
struct StackChanges {
	vector<Change> st;

	StackChanges() : st() {}

	void makeChange(int* pos, int val) {
		st.push_back(Change(pos, *pos));
		*pos = val;
	}
	void undo(int sz) {
		while((int)st.size() > sz) {
			st.back().apply();
			st.pop_back();
		}
	}
} changes;
struct DSU {
	vector<int> sz, par;

	DSU() : sz(), par() {}
	DSU(int n) {
		sz = vector<int>(n, 1);
		par = vector<int>(n, -1);
	}

	int getPar(int v) {
		while(par[v] != -1) v = par[v];
		return v;
	}
	bool unite(int v, int u) {
		v = getPar(v);
		u = getPar(u);
		if (v == u) return false;
		if (sz[v] < sz[u]) swap(v, u);
		changes.makeChange(&par[u], v);
		changes.makeChange(&sz[v], sz[v] + sz[u]);
		return true;
	}
} dsu;

const int N = 1 << 19;
const int NN = N + 5;
struct Node {
	int l, r;
	vector<pii> ed;

	Node() : l(), r(), ed() {}
	Node(int _l, int _r) : l(_l), r(_r), ed() {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void addEdge(int v, int l, int r, pii e) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].ed.push_back(e);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	for (int u = 2 * v; u < 2 * v + 2; u++)
		addEdge(u, l, r, e);
}

int n, m, k;
int day;
int p;
int dayEnd[2 * NN];
int Q[NN][3];
int V[NN];

void dfs(int v) {
	int oldSz = (int)changes.st.size();
	for (pii e : tree[v].ed)
		dsu.unite(e.first, e.second);
	if (v >= N) {
		if (v < N + p)
			printf("%d\n", dsu.sz[dsu.getPar(V[v - N])]);
	} else {
		for (int u = 2 * v; u < 2 * v + 2; u++)
			dfs(u);
	}
	changes.undo(oldSz);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	dsu = DSU(n);
	day = 0;
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		Q[i][0] = t;
		if (t == 1) {
			int v, u;
			scanf("%d%d", &v, &u);
			v--;u--;
			Q[i][1] = v;
			Q[i][2] = u;
		} else if (t == 2) {
			int v;
			scanf("%d", &v);
			v--;
			Q[i][1] = v;
			V[p++] = v;
		} else {
			dayEnd[day++] = p;
		}
	}
	for (int i = day; i < 2 * N; i++)
		dayEnd[i] = p;

//	eprintf("%d %d\n", day, p);

	build();
	day = p = 0;
	for (int i = 0; i < m; i++) {
		if (Q[i][0] == 1) {
			int v = Q[i][1], u = Q[i][2];
			addEdge(1, p, dayEnd[day + k - 1], mp(v, u));
		} else if (Q[i][0] == 2) {
			p++;
		} else {
			day++;
		}
	}

//	eprintf("%d %d\n", day, p);

	dfs(1);

	return 0;
}