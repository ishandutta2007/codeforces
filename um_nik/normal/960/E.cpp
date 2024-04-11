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

const int N = 200200;
int n;
vector<int> g[N];
int a[N];
int sz[N];
int b[N];
int h[N];
int ans;

void dfs(int v, int par) {
	sz[v] = 1;
	b[v] = 1;
	ans = add(ans, mult(n, a[v]));
	for (int u : g[v]) {
		if (u == par) continue;
		h[u] = h[v] ^ 1;
		dfs(u, v);
		sz[v] += sz[u];
		b[v] = sub(b[v], b[u]);
		ans = sub(ans, mult(a[v], mult(n - sz[u], b[u])));
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] < 0) a[i] += MOD;
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	for (int v = 1; v < n; v++) {
		int x = b[0];
		if (h[v]) x = sub(0, x);
		x = sub(x, b[v]);
		ans = add(ans, mult(a[v], mult(sz[v], x)));
	}
	printf("%d\n", ans);

	return 0;
}