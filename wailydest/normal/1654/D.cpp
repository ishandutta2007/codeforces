#include <cstdio>
#include <algorithm>
#include <vector>

const int md = 998244353;
inline int add(int a, int b) {
	a += b;
	if (a >= md) a -= md;
	return a;
}
inline int sub(int a, int b) {
	a -= b;
	if (a < 0) a += md;
	return a;
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
inline int di(int a, int b) {
	return mul(a, inv(b));
}

const int N = 200005;
int t, n, lp[N], sum, amt[N], mx[N];
std::vector<std::pair<int, std::pair<int, int> > > g[N];
std::vector<int> view;

void dfs(int v, int val = 1, int nu_ = 1, int de_ = 1, int pr = -1) {
	int nu = nu_, de = de_;
	val = mul(val, nu);
	val = di(val, de);
	sum = add(sum, val);
	while (nu > 1) {
		view.push_back(lp[nu]);
		--amt[lp[nu]];
		nu /= lp[nu];
	}
	while (de > 1) {
		view.push_back(lp[de]);
		++amt[lp[de]];
		mx[lp[de]] = std::max(mx[lp[de]], amt[lp[de]]);
		de /= lp[de];
	}
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].first != pr) dfs(g[v][i].first, val, g[v][i].second.second, g[v][i].second.first, v);
	nu = nu_;
	while (nu > 1) {
		++amt[lp[nu]];
		nu /= lp[nu];
	}
	de = de_;
	while (de > 1) {
		--amt[lp[de]];
		de /= lp[de];
	}
}

int main() {
	for (int i = 2; i < N; ++i) if (!lp[i]) for (int j = i; j < N; j += i) lp[j] = i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) {
			int a, b, x, y;
			scanf("%d%d%d%d", &a, &b, &x, &y);
			--a;
			--b;
			g[a].push_back(std::make_pair(b, std::make_pair(x, y)));
			g[b].push_back(std::make_pair(a, std::make_pair(y, x)));
		}
		sum = 0;
		view.clear();
		dfs(0);
		std::sort(view.begin(), view.end());
		for (int i = 0; i < (int)view.size(); ++i) if (!i || view[i] != view[i - 1]) {
			int cur = view[i];
			for (int j = 0; j < mx[cur]; ++j) sum = mul(sum, cur);
			mx[cur] = 0;
			amt[cur] = 0;
		}
		printf("%d\n", sum);
		for (int i = 0; i < n; ++i) g[i].clear();
	}
}