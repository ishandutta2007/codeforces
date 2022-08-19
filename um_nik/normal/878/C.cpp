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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int myRand() {
	return (rand() << 15) ^ rand();
}
struct Node {
	int x, y;
	int l, r;
	int sz;
	int toAdd;

	Node() : x(), y(), l(-1), r(-1), sz(0), toAdd(0) {}
	Node(int _x) : x(_x), y(myRand()), l(-1), r(-1), sz(1), toAdd(0) {}
};
const int K = 10;
const int N = 100100;
Node tree[N];
int treeSz;

int a[K][N];
int xs[N];
int fenv[K][N];
int n, k;

int root;
int res[3];
int resSz;

void fenvAdd(int t, int r, int x) {
	for(; r < n; r |= r + 1)
		fenv[t][r] += x;
}
int fenvGet(int t, int r) {
	int sum = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		sum += fenv[t][r];
	return sum;
}

int makeNode(int x) {
	int v = treeSz++;
	tree[v] = Node(x);
	return v;
}

int getSize(int v) {
	if (v == -1) return 0;
	return tree[v].sz;
}
int update(int v) {
	tree[v].sz = 1 + getSize(tree[v].l) + getSize(tree[v].r);
	return v;
}
void addNode(int v, int x) {
	if (v == -1) return;
	tree[v].toAdd += x;
	tree[v].x += x;
}
void push(int v) {
	addNode(tree[v].l, tree[v].toAdd);
	addNode(tree[v].r, tree[v].toAdd);
	tree[v].toAdd = 0;
}

int merge(int L, int R) {
	if (L == -1) return R;
	if (R == -1) return L;
	push(L);
	push(R);
	if (tree[L].y > tree[R].y) {
		tree[L].r = merge(tree[L].r, R);
		return update(L);
	} else {
		tree[R].l = merge(L, tree[R].l);
		return update(R);
	}
}
void split(int v, int x, int &L, int &R) {
	if (v == -1) {
		L = R = -1;
		return;
	}
	push(v);
	if (tree[v].x <= x) {
		split(tree[v].r, x, tree[v].r, R);
		L = update(v);
	} else {
		split(tree[v].l, x, L, tree[v].l);
		R = update(v);
	}
}

void dfs(int v) {
	if (v == -1) return;
	if (resSz >= 2) return;
	push(v);
	dfs(tree[v].r);
	if (resSz < 2) {
		res[resSz++] = tree[v].x;
		dfs(tree[v].l);
	}
}

int solve(int l, int r) {
	//printf("solve %d %d\n", l, r);
	int L, M, R;
	if (l == r) {
		split(root, l - 1, L, M);
		split(M, l, M, R);
		addNode(R, 1);
		if (M == -1) {
			root = merge(L, R);
		} else {
			root = merge(merge(L, M), merge(makeNode(l + 1), R));
		}
	} else {
		split(root, l, L, M);
		split(M, r - 1, M, R);
		addNode(R, 1);
		root = merge(L, R);
	}
	resSz = 0;
	dfs(root);
	if (resSz < 2) throw;
	return res[1];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			scanf("%d", &a[j][i]);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			xs[j] = a[i][j];
		sort(xs, xs + n);
		for (int j = 0; j < n; j++)
			a[i][j] = lower_bound(xs, xs + n, a[i][j]) - xs;
	}

	root = makeNode(0);
	for (int i = 0; i < n; i++) {
		int l = i + 1, r = 0;
		for (int j = 0; j < k; j++) {
			int z = fenvGet(j, a[j][i]);
			l = min(l, z);
			r = max(r, z);
			fenvAdd(j, a[j][i], 1);
		}
		printf("%d\n", i + 1 - solve(l, r));
	}

	return 0;
}