#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>

const int N = 1000;
int n, m, a[N], b[N], sz, mt[N];
bool u[N], done[N];
std::vector<int> g[N];

bool dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (mt[g[v][i]] == -1 || !u[mt[g[v][i]]] && dfs(mt[g[v][i]])) {
		mt[g[v][i]] = v;
		done[v] = 1;
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (a[i] <= m / 3) {
			b[sz++] = a[i];
			--n;
			--i;
		}
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < sz; ++j) if (!(a[i] % b[j]) && a[i] * 2 + b[j] <= m) g[i].push_back(j);
	memset(mt, -1, sz << 2);
	bool any;
	int ans = 0;
	do {
		memset(u, 0, n);
		any = 0;
		for (int i = 0; i < n; ++i) if (!u[i] && !done[i] && dfs(i)) {
			any = 1;
			++ans;
		}
	} while (any);
	if (ans == n) {
		std::vector<std::pair<int, int> > res;
		for (int i = 0; i < sz; ++i) {
			if (mt[i] != -1) res.push_back(std::make_pair(b[i] + a[mt[i]], a[mt[i]] * 2 + b[i]));
			else res.push_back(std::make_pair(3 * b[i], 2 * b[i]));
		}
		printf("%d\n", (int)res.size());
		for (int i = 0; i < (int)res.size(); ++i) printf("%d %d\n", res[i].first, res[i].second);
	} else printf("-1\n");
	return 0;
}