#include <cstdio>
#include <vector>

const int md = 1000000007;
inline int add(int a, int b) {
	return a + b >= md ? a + b - md : a + b;
}
inline int sub(int a, int b) {
	return a - b < 0 ? a - b + md : a - b;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}
int po(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
inline int inv(int a) {
	return po(a, md - 2);
}

const int N = 200005;
int n, k, size[N], d[N], d1[N], sum[N], ans, fact[N];
std::vector<int> g[N];

inline int ncr(int n, int r) {
	return mul(fact[n], inv(mul(fact[r], fact[n - r])));
}

int fun(int s) {
	if (s < k) return 0;
	return ncr(s, k);
}

void dfs(int v, int pr = -1) {
	size[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		dfs(g[v][i], v);
		size[v] += size[g[v][i]];
		sum[v] = add(sum[v], fun(size[g[v][i]]));
	}
	d[v] = sub(fun(size[v]), sum[v]);
}

void dfs1(int v, int pr = -1) {
	ans = add(ans, mul(size[v], mul(n - size[v], d[v])));
	if (pr != -1) sum[v] = add(sum[v], d1[pr]);
	ans = add(ans, mul(n, sub(fun(n), sum[v])));
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr) {
		d1[v] = fun(n - size[g[v][i]]);
		ans = add(ans, mul(n - size[g[v][i]], mul(size[g[v][i]], sub(fun(n - size[g[v][i]]), sub(sum[v], fun(size[g[v][i]]))))));
		dfs1(g[v][i], v);
	}
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i) fact[i] = mul(fact[i - 1], i);
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs(0);
	dfs1(0);
	printf("%d\n", ans);
	return 0;
}