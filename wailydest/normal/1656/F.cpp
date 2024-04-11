#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 200000;
const int X = 101000;
int t, n, a[N], up[N], sz[N];

int find(int v) {
	if (up[v] == -1) return v;
	return up[v] = find(up[v]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	if (sz[u] < sz[v]) std::swap(u, v);
	up[v] = u;
	sz[u] += sz[v];
	return 1;
}

std::vector<std::pair<long long, std::pair<int, int> > > e;

void add(int u, int v, int t) {
	e.push_back(std::make_pair((long long)a[u] * a[v] + (long long)(a[u] + a[v]) * t, std::make_pair(u, v)));
}

long long w(int u, int v, int t) {
	return (long long)a[u] * a[v] + (long long)(a[u] + a[v]) * t;
}

void add(int v, int t) {
	for (int i = 0; i < n; ++i) if (v != i) add(v, i, t);
}

long long f(int t) {
	for (int i = 0; i < (int)e.size(); ++i) e[i].first = w(e[i].second.first, e[i].second.second, t);
	std::sort(e.begin(), e.end());
	for (int i = 0; i < n; ++i) {
		up[i] = -1;
		sz[i] = 1;
	}
	long long ans = 0;
	for (int i = 0; i < (int)e.size(); ++i) ans += e[i].first * merge(e[i].second.first, e[i].second.second);
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		e.clear();
		add(0, 0);
		add(n - 1, 0);
		int i;
		if (f(X) < f(X + 1) || f(-X) < f(-X - 1)) printf("INF\n");
		else {
			int l = -X, r = X;
			while (l <= r) {
				int m = l + r >> 1;
				if (f(m) <= f(m + 1)) l = m + 1;
				else r = m - 1;
			}
			printf("%lld\n", f(l));
		}
	}
	return 0;
}