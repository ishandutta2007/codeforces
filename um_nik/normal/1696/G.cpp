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

const double INF = 1e20;
const int N = (1 << 18);
double X, Y;
int a[N + 5];
int n;
struct Node {
	int l, r;
	double val[3][3];

	Node() : l(-1), r(-1) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				val[i][j] = -INF;
	}
	Node(int _l, int _r) : l(_l), r(_r) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				val[i][j] = -INF;
	}

	void assign(double x) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				val[i][j] = -INF;
		val[0][0] = 0;
		val[1][1] = x / (X + Y);
		val[2][2] = x / Y;
	}
};
Node tree[2 * N + 5];

Node merge(Node L, Node R) {
	if (L.l == -1) return R;
	if (R.l == -1) return L;
	Node A = Node(L.l, R.r);
	for (int x1 = 0; x1 < 3; x1++)
		for (int y1 = 0; y1 < 3; y1++)
			for (int x2 = 0; x2 + y1 < 3; x2++)
				for (int y2 = 0; y2 < 3; y2++) {
					A.val[x1][y2] = max(A.val[x1][y2], L.val[x1][y1] + R.val[x2][y2]);
				}
	return A;
}

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}

Node getSegm(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r) return tree[v];
	if (l >= tree[v].r || tree[v].l >= r) return Node();
	return merge(getSegm(2 * v, l, r), getSegm(2 * v + 1, l, r));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d%d", &n, &q);
	build();
	scanf("%lf%lf", &X, &Y);
	if (X > Y) swap(X, Y);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		tree[N + i].assign(a[i]);
	}
	for (int i = N - 1; i > 0; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	while(q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int p;
			scanf("%d", &p);
			p--;
			scanf("%d", &a[p]);
			tree[N + p].assign(a[p]);
			p += N;
			while(p > 1) {
				p >>= 1;
				tree[p] = merge(tree[2 * p], tree[2 * p + 1]);
			}
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			Node A = getSegm(1, l, r);
			double ans = -INF;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					ans = max(ans, A.val[i][j]);
			printf("%.13lf\n", ans);
		}
	}

	return 0;
}