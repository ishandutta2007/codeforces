#include <cstdio>
#include <algorithm>
#include <vector>

struct p {
	int val, ind;
	long long pos, neg;
};
bool operator<(p &a, p &b) 
{
	return a.val < b.val;
}

const int N = 200000;
int t, n, a[N], d[N], pr[N];
long long ans[N];
std::vector<std::vector<int> > l;
std::vector<int> g[N];

void dfs(int v) 
{
	if ((int)l.size() == d[v]) l.push_back(std::vector<int>());
	l[d[v]].push_back(v);
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i] != pr[v]) {
		pr[g[v][i]] = v;
		d[g[v][i]] = d[v] + 1;
		dfs(g[v][i]);
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i < n; ++i) {
			int x;
			scanf("%d", &x);
			g[i].push_back(x - 1);
			g[x - 1].push_back(i);
		}
		for (int i = 1; i < n; ++i) scanf("%d", a + i);
		dfs(0);
		long long ov = 0;
		for (int i = 1; i < (int)l.size(); ++i) {
			int len = (int)l[i].size();
			std::vector<p> v;
			for (int j = 0; j < len; ++j) v.push_back({a[l[i][j]], l[i][j], ans[pr[l[i][j]]] + a[l[i][j]], ans[pr[l[i][j]]] - a[l[i][j]]});
			std::sort(v.begin(), v.end());
			std::vector<long long> posmx(len), negmx(len);
			posmx[len - 1] = v[len - 1].pos;
			for (int i = len - 2; i >= 0; --i) posmx[i] = std::max(posmx[i + 1], v[i].pos);
			negmx[0] = v[0].neg;
			for (int i = 1; i < len; ++i) negmx[i] = std::max(negmx[i - 1], v[i].neg);
			for (int i = 0; i < len; ++i) {
				ans[v[i].ind] = std::max(v[i].val + negmx[i], posmx[i] - v[i].val);
				ans[v[i].ind] = std::max(ans[v[i].ind], std::max(ans[pr[v[i].ind]] + v[len - 1].val - a[v[i].ind], ans[pr[v[i].ind]] - v[0].val + a[v[i].ind]));
				ov = std::max(ov, ans[v[i].ind]);
			}
		}
		printf("%lld\n", ov);
		l.clear();
		for (int i = 0; i < n; ++i) g[i].clear();
	}
	return 0;
}