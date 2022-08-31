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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1 << 14;
struct Node {
	int l, r;
	vector<int> a;

	Node() : l(), r(), a() {}
	Node(int _l, int _r) : l(_l), r(_r), a() {}
};
Node tree[2 * N + 5];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void addSegm(int v, int l, int r, int x) {
	if (l <= tree[v].l && tree[v].r <= r) {
		tree[v].a.push_back(x);
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	addSegm(2 * v, l, r, x);
	addSegm(2 * v + 1, l, r, x);
}

const int M = (int)1e4 + 3;
bitset<M> st[M];
int sz;
bitset<M> ans;
int n;

void dfs(int v) {
	int old = sz;
	for (int x : tree[v].a) {
		st[sz + 1] = st[sz] | (st[sz] << x);
		sz++;
	}
	if (v >= N) {
		ans |= st[sz];
	} else {
		dfs(2 * v);
		dfs(2 * v + 1);
	}
	sz = old;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();

	int q;
	scanf("%d%d", &n, &q);
	while(q--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		l--;
		addSegm(1, l, r, x);
	}
	st[0][0] = 1;
	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (ans[i])
			cnt++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
		if (ans[i])
			printf("%d ", i);
	printf("\n");

	return 0;
}