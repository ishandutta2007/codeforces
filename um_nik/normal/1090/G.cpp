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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int S = (int)20e6;
//const int S = 1000;

const int INF = (int)1e7;

struct Node {
	int l, r;
	pii segm;
	int y;

	Node() : l(-1), r(-1), segm(), y() {}
	Node(pii s) : l(-1), r(-1), segm(s), y(rng()) {}
};
Node tree[S];
int treeSz;

int newNode(pii s) {
	if (treeSz == S) throw;
	tree[treeSz] = Node(s);
	return treeSz++;
}
int clone(int v) {
	if (v == -1) return -1;
	if (treeSz == S) throw;
	tree[treeSz] = tree[v];
	return treeSz++;
}

int merge(int L, int R) {
	if (L == -1) return R;
	if (R == -1) return L;
	if (tree[L].y > tree[R].y) {
		L = clone(L);
		tree[L].r = merge(tree[L].r, R);
		return L;
	} else {
		R = clone(R);
		tree[R].l = merge(L, tree[R].l);
		return R;
	}
}
void split(int v, int x, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	v = clone(v);
	if (x < tree[v].segm.second) {
		split(tree[v].l, x, L, tree[v].l);
		R = v;
	} else {
		split(tree[v].r, x, tree[v].r, R);
		L = v;
	}
}

pii my_upperbound(int v, int x) {
	if (v == -1) return mp(INF, INF);
	if (x >= tree[v].segm.first) {
		if (x < tree[v].segm.second) return tree[v].segm;
		return my_upperbound(tree[v].r, x);
	}
	pii res = my_upperbound(tree[v].l, x);
	if (res.first != INF) return res;
	return tree[v].segm;
}
int insert(int v, pii segm) {
	int L, R;
	split(v, segm.first, L, R);
	return merge(merge(L, newNode(segm)), R);
}
int erase(int v, pii segm) {
	int L, M, R;
	split(v, segm.first, L, M);
	split(M, segm.second, M, R);
	return merge(L, R);
}

const int N = 250200;
int dead[N];
int att[N], def[N];
int roots[N];
int n, m;

int apply(int root, int x) {
	pii t = my_upperbound(root, x);
	if (t.first == x + 1) {
		pii tt = my_upperbound(root, x - 1);
		if (tt.first >= x) {
			root = erase(root, t);
			root = insert(root, mp(x, t.second));
		} else {
			root = erase(root, t);
			root = erase(root, tt);
			root = insert(root, mp(tt.first, t.second));
		}
		return root;
	}
	int l, r;
	if (t.first <= x) {
		root = erase(root, t);
		if (t.second > x + 1)
			root = insert(root, mp(x + 1, t.second));
		l = t.first - 1;
		r = t.first;
	} else {
		l = x;
		r = x + 1;
	}
	t = my_upperbound(root, l - 1);
	if (t.first > l - 1) {
		return insert(root, mp(l, r));
	}
	root = erase(root, t);
	return insert(root, mp(t.first, r));
}

void apply(int v, int x, int T) {
	if (x <= 0) {
		dead[v] = T;
		return;
	}
	roots[v] = apply(roots[v], x);
	pii t = my_upperbound(roots[v], 0);
	if (t.first <= 0) dead[v] = T;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int T = 1; T <= n; T++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			roots[m] = -1;
			att[m] = 0;
			def[m] = 0;
			dead[m] = -1;
			m++;
		} else if (t == 2) {
			int v;
			scanf("%d", &v);
			v--;
			att[v]++;
		} else if (t == 3) {
			int v;
			scanf("%d", &v);
			v--;
			def[v]++;
		} else if (t == 4) {
			int v;
			scanf("%d", &v);
			v--;
			dead[m] = dead[v];
			if (dead[v] != -1) {
				dead[m] = T;
				m++;
				continue;
			}
			roots[m] = clone(roots[v]);
			att[m] = att[v];
			def[m] = def[v];
			m++;
		} else if (t == 5) {
			int v, u;
			scanf("%d%d", &v, &u);
			v--;u--;
			if (dead[v] != -1 || dead[u] != -1) continue;
			apply(v, def[v] - att[u], T);
			apply(u, def[u] - att[v], T);
		} else throw;
	}
	printf("%d\n", m);
	for (int i = 0; i < m; i++)
		printf("%d ", dead[i]);
	printf("\n");

	return 0;
}