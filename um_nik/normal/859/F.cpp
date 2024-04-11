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

const ll INF = (ll)1e16;
const int N = 1 << 18;
const int M = 2 * N + 7;
struct Node {
	int l, r;
	ll val;

	Node() : l(), r(), val(-INF) {}
	Node(int _l, int _r) : l(_l), r(_r), val(-INF) {}
};
Node tree[M];

void build() {
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
}
void setVal(int p, ll x) {
	p += N;
	tree[p].val = x;
	while(p > 1) {
		p >>= 1;
		tree[p].val = max(tree[2 * p].val, tree[2 * p + 1].val);
	}
}
ll getMax(int v, int l, int r) {
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (l >= tree[v].r || tree[v].l >= r)
		return -INF;
	return max(getMax(2 * v, l, r), getMax(2 * v + 1, l, r));
}

int n;
ll C;
ll a[M];
ll b[M];
ll dp[M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	build();
	scanf("%d%lld", &n, &C);
	for (int i = 0; i < 2 * n - 1; i++) {
		scanf("%lld", &a[i]);
		b[i + 1] = b[i] + a[i];
	}
	dp[0] = 0;
	setVal(0, dp[0] - b[0]);
	for (int i = 1; i <= n; i++) {
		int l = -1, r = i;
		while(r - l > 1) {
			int mid = (l + r) / 2;
			ll w = b[2 * i - 1] - b[2 * mid];
			if (w <= C)
				r = mid;
			else
				l = mid;
		}
		dp[i] = getMax(1, r, i) + b[2 * i - 1];
		if (l >= 0)
			dp[i] = max(dp[i], dp[l] + C);
		if (i < n)
			setVal(i, dp[i] - b[2 * i]);
	}
	printf("%lld\n", dp[n]);

	return 0;
}