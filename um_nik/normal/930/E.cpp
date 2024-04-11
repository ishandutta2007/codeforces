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
int bin_pow(int x, int p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}

const int N = 400400;

/*
struct Node {
	int l, r;
	int val;
	bool allZeroes;

	Node() : l(), r(), val(), allZeroes() {}
	Node(int _l, int _r) : l(_l), r(_r), val(0), allZeroes(false) {}
};
Node tree[2][2 * N + 5];

void build() {
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N; i++)
			tree[k][N + i] = Node(i, i + 1);
		for (int i = N - 1; i > 0; i--)
			tree[k][i] = Node(tree[k][2 * i].l, tree[k][2 * i + 1].r);
	}
}

void push(int k, int v) {
	if (v >= N) throw;
	if (!tree[k][v].allZeroes)
		return;
	for (int u = 2 * v; u < 2 * v + 2; u++) {
		tree[k][u].allZeroes = true;
		tree[k][u].val = 0;
	}
	tree[k][v].allZeroes = false;
}
void update(int k, int v) {
	if (v >= N) throw;
	tree[k][v].val = add(tree[k][2 * v].val, tree[k][2 * v + 1].val);
}

void setInPos(int k, int v, int pos, int val) {
	if (v >= N) {
		tree[k][v].val = val;
		return;
	}
	push(k, v);
	if (pos < tree[k][2 * v].r)
		setInPos(k, 2 * v, pos, val);
	else
		setInPos(k, 2 * v + 1, pos, val);
	update(k, v);
}
void zeroesOnSegm(int k, int v, int l, int r) {
	if (l <= tree[k][v].l && tree[k][v].r <= r) {
		tree[k][v].allZeroes = true;
		tree[k][v].val = 0;
		return;
	}
	if (l >= tree[k][v].r || tree[k][v].l >= r) return;
	push(k, v);
	zeroesOnSegm(k, 2 * v, l, r);
	zeroesOnSegm(k, 2 * v + 1, l, r);
	update(k, v);
}

int getSum(int k, int v, int l, int r) {
	if (l <= tree[k][v].l && tree[k][v].r <= r)
		return tree[k][v].val;
	if (l >= tree[k][v].r || tree[k][v].l >= r)
		return 0;
	push(k, v);
	return add(getSum(k, 2 * v, l, r), getSum(k, 2 * v + 1, l, r));
}
*/

int n, m, k;
int xs[N + 5];
int a[N + 5][2], b[N + 5][2];
int bord[2][N + 5];
int dp[2][N + 5];
int sum0 = 0, sum1 = 0;
int lst;
int pt1 = 0, pt2 = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	k = 3;
	xs[0] = -1;
	xs[1] = 0;
	scanf("%d%d%d", &xs[2], &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][0]--;
		xs[k++] = a[i][0];
		xs[k++] = a[i][1];
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &b[i][0], &b[i][1]);
		b[i][0]--;
		xs[k++] = b[i][0];
		xs[k++] = b[i][1];
	}
	sort(xs, xs + k);
	k = unique(xs, xs + k) - xs;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(xs, xs + k, a[i][0]) - xs;
		int r = lower_bound(xs, xs + k, a[i][1]) - xs;
		r--;
		bord[0][r] = max(bord[0][r], l);
	}
	for (int i = 0; i < m; i++) {
		int l = lower_bound(xs, xs + k, b[i][0]) - xs;
		int r = lower_bound(xs, xs + k, b[i][1]) - xs;
		r--;
		bord[1][r] = max(bord[1][r], l);
	}
/*
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
		printf("%d ", xs[i]);
	printf("\n");
	for (int i = 0; i < k - 1; i++)
		printf("%d ", bord[0][i]);
	printf("\n");
	for (int i = 0; i < k - 1; i++)
		printf("%d ", bord[1][i]);
	printf("\n");
*/

	lst = 1;
	for (int i = 1; i < k - 1; i++) {
		int ways = bin_pow(2, xs[i + 1] - xs[i]);
		ways = sub(ways, 2);
		//printf("%d ", ways);
		int nlst = mult(ways, add(add(sum0, sum1), lst));
		dp[0][i - 1] = add(sum1, lst);
		dp[1][i - 1] = add(sum0, lst);
		sum0 = add(sum0, dp[0][i - 1]);
		sum1 = add(sum1, dp[1][i - 1]);
		lst = nlst;
		while(pt1 < bord[0][i]) {
			sum0 = sub(sum0, dp[0][pt1]);
			pt1++;
		}
		while(pt2 < bord[1][i]) {
			sum1 = sub(sum1, dp[1][pt2]);
			pt2++;
		}
	}
/*
	printf("DP:\n");
	for (int i = 0; i < k - 1; i++)
		printf("%d ", dp[0][i]);
	printf("\n");
	for (int i = 0; i < k - 1; i++)
		printf("%d ", dp[1][i]);
	printf("\n");
*/
	printf("%d\n", add(add(sum0, sum1), lst));

	return 0;
}