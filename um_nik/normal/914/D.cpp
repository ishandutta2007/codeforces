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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

const int N = 1 << 19;
const int NN = N + 5;
int n;

struct Node {
	int l, r;
	int x;

	Node() : l(), r(), x() {}
	Node(int _l, int _r) : l(_l), r(_r), x(0) {}
};
Node tree[2 * NN];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

void changeVal(int v, int x) {
	v += N;
	tree[v].x = x;
	while(v > 1) {
		v >>= 1;
		tree[v].x = gcd(tree[2 * v].x, tree[2 * v + 1].x);
	}
}

int solveL(int v, int l, int x) {
	if (tree[v].r <= l) return -1;
	if (tree[v].x % x == 0) return -1;
	if (v >= N) return v - N;
	int res = solveL(2 * v, l, x);
	if (res != -1) return res;
	return solveL(2 * v + 1, l, x);
}
int solveR(int v, int r, int x) {
	if (r < tree[v].l) return -1;
	if (tree[v].x % x == 0) return -1;
	if (v >= N) return v - N;
	int res = solveR(2 * v + 1, r, x);
	if (res != -1) return res;
	return solveR(2 * v, r, x);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	build();
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		changeVal(i, x);
	}
	//printf("%d\n", tree[1].x);
	int q;
	scanf("%d", &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--;
			r--;
			l = solveL(1, l, x);
			r = solveR(1, r, x);
		//	printf("l = %d, r = %d\n", l, r);
			if (l != -1 && r != -1 && l < r)
				printf("NO\n");
			else
				printf("YES\n");
		} else {
			int v, x;
			scanf("%d%d", &v, &x);
			v--;
			changeVal(v, x);
		}
	}

	return 0;
}