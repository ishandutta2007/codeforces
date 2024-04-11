#include <cstdio>
#include <vector>

const int N = 200000;
int n, k, up[N], in[N], out[N], ord[N], add[N << 1], dep[N];
std::vector<int> g[N];
bool u[N];
std::pair<int, int> t[N << 1];

void build(int v = 0, int tl = 0, int tr = n) 
{
	if (tr - tl == 1) t[v] = std::make_pair(dep[ord[tl]] + 1, ord[tl]);
	else {
		int m = tl + tr >> 1;
		build(v + 1, tl, m);
		build(v + (tr - tl & ~1), m, tr);
		t[v] = std::max(t[v + 1], t[v + (tr - tl & ~1)]);
	}
}

void update(int l, int r, int x, int v = 0, int tl = 0, int tr = n) 
{
	if (!(tl >= r || tr <= l)) {
		if (tl >= l && tr <= r) {
			t[v].first += x;
			add[v] += x;
		} else {
			int m = tl + tr >> 1;
			update(l, r, x, v + 1, tl, m);
			update(l, r, x, v + (tr - tl & ~1), m, tr);
			t[v] = std::max(t[v + 1], t[v + (tr - tl & ~1)]);
			t[v].first += add[v];
		}
	}
}

void dfs(int v) 
{
	static int dt = 0;
	ord[dt] = v;
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != up[v]) {
		dep[g[v][i]] = dep[v] + 1;
		up[g[v][i]] = v;
		dfs(g[v][i]);
	}
	out[v] = dt;
}

int main() 
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	dfs(0);
	build();
	long long x = (long long)(n >> 1) * (n + 1 >> 1), ans = -x;
	int amt = 0;
	for (int i = 1; i <= k; ++i) {
		if (t[0].first) {
			amt += t[0].first;
			int cur = t[0].second;
			while (!u[cur]) {
				u[cur] = 1;
				update(in[cur], out[cur], -1);
				cur = up[cur];
			}
		}
		ans = std::max(ans, (long long)i * (n - i) - (n - amt >= n >> 1 ? x : (long long)(n - amt) * amt));
	}
	printf("%lld\n", ans);
	return 0;
}