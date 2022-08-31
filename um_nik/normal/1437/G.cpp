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

struct SegTreeNode {
	int l, r;
	int val;

	SegTreeNode() : l(-1), r(-1), val(-1) {}
	SegTreeNode(int _l, int _r) : l(_l), r(_r), val(-1) {}
};
struct SegmentTree {
	vector<SegTreeNode> tree;
	int L;

	SegmentTree() : tree(), L(-1) {}
	SegmentTree(int _L) {
		L = _L;
		while(L & (L - 1)) L++;
		tree.resize(2 * L);
		for (int i = 0; i < L; i++)
			tree[L + i] = SegTreeNode(i, i + 1);
		for (int i = L - 1; i > 0; i--)
			tree[i] = SegTreeNode(tree[2 * i].l, tree[2 * i + 1].r);
	}

	void putInPoint(int v, int x) {
		v += L;
		tree[v].val = x;
		while(v > 1) {
			v >>= 1;
			tree[v].val = max(tree[2 * v].val, tree[2 * v + 1].val);
		}
	}
	int getMax(int v, int l, int r) {
		if (l <= tree[v].l && tree[v].r <= r) return tree[v].val;
		if (l >= tree[v].r || tree[v].l >= r) return -1;
		return max(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
	}
};

const int N = 300300;
const int A = 26;
int n, q;
int go[N][A];
int suffLink[N];
int m;
char s[N];
int a[N];
int myVert[N];
multiset<int> setik[N];
vector<int> g[N];
int Q[N];
int topQ;
int sz[N];
int info[N][2];
int treeSz[N];
int treePar[N];
SegmentTree trees[N];

void dfsSz(int v) {
	sz[v] = 1;
	for (int u : g[v]) {
		dfsSz(u);
		sz[v] += sz[u];
	}
}

void dfsHLD(int v, int id, int p) {
	info[v][0] = id;
	info[v][1] = p;
	treeSz[id] = max(treeSz[id], p + 1);
	int big = -1;
	for (int u : g[v]) {
		if (big == -1 || sz[big] < sz[u])
			big = u;
	}
	for (int u : g[v]) {
		if (u == big) {
			dfsHLD(u, id, p + 1);
		} else {
			treePar[m] = v;
			m++;
			dfsHLD(u, m - 1, 0);
		}
	}
}

void prepare() {
	dfsSz(0);
	m = 1;
	treePar[0] = -1;
	dfsHLD(0, 0, 0);
	for (int i = 0; i < m; i++)
		trees[i] = SegmentTree(treeSz[i]);
}

void setVertex(int v, int x) {
	int id = info[v][0];
	trees[id].putInPoint(info[v][1], x);
}
int getVertex(int v) {
	int ans = -1;
	while(v != -1) {
		int id = info[v][0];
		ans = max(ans, trees[id].getMax(1, 0, info[v][1] + 1));
		v = treePar[id];
	}
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	m = 1;
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int L = strlen(s);
		int v = 0;
		for (int j = 0; j < L; j++) {
			int c = (int)(s[j] - 'a');
			if (go[v][c] == 0) go[v][c] = m++;
			v = go[v][c];
		}
		myVert[i] = v;
	}
	Q[topQ++] = 0;
	suffLink[0] = -1;
	for (int i = 0; i < topQ; i++) {
		int v = Q[i];
		for (int c = 0; c < A; c++) {
			if (go[v][c] == 0) continue;
			int u = go[v][c];
			int w = suffLink[v];
			while(w != -1 && go[w][c] == 0) w = suffLink[w];
			if (w == -1)
				w = 0;
			else
				w = go[w][c];
			suffLink[u] = w;
			g[w].push_back(u);
			Q[topQ++] = u;
		}
	}
	prepare();
	for (int i = 0; i < n; i++) {
		int v = myVert[i];
		setik[v].insert(0);
		setVertex(v, 0);
	}
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int p, v, x;
			scanf("%d%d", &p, &x);
			p--;
			v = myVert[p];
			setik[v].erase(setik[v].find(a[p]));
			a[p] = x;
			setik[v].insert(x);
			setVertex(v, *setik[v].rbegin());
		} else {
			scanf("%s", s);
			int L = strlen(s);
			int v = 0;
			int ans = -1;
			for (int i = 0; i < L; i++) {
				int c = (int)(s[i] - 'a');
				while(v != -1 && go[v][c] == 0) v = suffLink[v];
				if (v == -1)
					v = 0;
				else
					v = go[v][c];
				ans = max(ans, getVertex(v));
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}