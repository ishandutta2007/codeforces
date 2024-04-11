#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define dp std::pair<int, int>

const int md = 998244353;

inline int add(int a, int b) {
	return a + b < md ? a + b : a + b - md;
}
inline int sub(int a, int b) {
	return a - b < 0 ? a - b + md : a - b;
}
inline int mul(int a, int b) {
	return (long long)a * b % md;
}

const int N = 200005;
const int LG = 18;
int n, pr[N], in[N], out[N], up[LG][N], dep[N], ans;
bool active[N];
std::vector<int> g[N], a[N];
dp d[N][2];

void dfs(int v) {
	static int dt = 0;
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != up[0][v]) {
		up[0][g[v][i]] = v;
		dep[g[v][i]] = dep[v] + 1;
		dfs(g[v][i]);
	}
	out[v] = dt;
}

bool cmp(int a, int b) {
	return in[a] < in[b];
}

bool par(int a, int b) {
	return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int a, int b) {
	if (par(a, b)) return a;
	for (int i = LG - 1; i >= 0; --i) if (!par(up[i][a], b)) a = up[i][a];
	return up[0][a];
}

dp operator+(dp a, dp b) {
	return dp(add(a.first, b.first), add(a.second, b.second));
}

dp operator-(dp a, dp b) {
	return dp(sub(a.first, b.first), sub(a.second, b.second));
}

dp operator*(dp a, dp b) {
	return dp(add(mul(a.first, b.second), mul(a.second, b.first)), mul(a.second, b.second));
}

void operator*=(dp &d, int k) {
	d.first = add(d.first, mul(k, d.second));
}

void dfs1(int v, int k = 0) {
	d[v][0] = dp();
	d[v][1] = dp();
	if (active[v]) d[v][0].second = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		int to = g[v][i];
		dfs1(to, dep[to] - dep[v]);
		ans = add(ans, (d[to][1] * d[v][0]).first);
		ans = add(ans, (d[to][0] * d[v][1]).first);
		d[v][1] = d[v][1] + d[to][1] + d[v][0] * d[to][0];
		d[v][0] = d[v][0] + d[to][0];
	}
	d[v][0] *= k;
	d[v][1] *= k;
}

void clear(int v) {
	for (int i = 0; i < (int)g[v].size(); ++i) clear(g[v][i]);
	g[v].clear();
}

int main() {
	for (int i = 2; i < N; ++i) if (!pr[i]) for (int j = i; j < N; j += i) pr[j] = i;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		while (x > 1) {
			int k = pr[x];
			a[k].push_back(i);
			do {
				x /= k;
			} while (!(x % k));
		}
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs(0);
	for (int j = 1; j < LG; ++j) 
		for (int i = 0; i < n; ++i) 
			up[j][i] = up[j - 1][up[j - 1][i]];
	for (int i = 0; i < n; ++i) g[i].clear();
	for (int p = 2; p < N; ++p) if (a[p].size() > 2) {
		std::vector<int> &b = a[p];
		std::sort(b.begin(), b.end(), cmp);
		for (int i = 0; i < b.size(); ++i) active[b[i]] = 1;
		std::vector<int> vec;
		vec.push_back(0);
		for (int i = (b.front() ? 0 : 1); i < (int)b.size(); ++i) {
			while (vec.size() > 1 && !par(vec[vec.size() - 2], b[i])) {
				g[vec[vec.size() - 2]].push_back(vec.back());
				vec.pop_back();
			}
			if (!par(vec.back(), b[i])) {
				int l = lca(vec.back(), b[i]);
				g[l].push_back(vec.back());
				vec.pop_back();
				if (vec.back() != l) vec.push_back(l);
			}
			vec.push_back(b[i]);
		}
		while (vec.size() > 1) {
			g[vec[vec.size() - 2]].push_back(vec.back());
			vec.pop_back();
		}
		dfs1(0);
		clear(0);
		for (int i = 0; i < b.size(); ++i) active[b[i]] = 0;
	}
	printf("%d\n", ans);
	return 0;
}