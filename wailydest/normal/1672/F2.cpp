#include <cstdio>
#include <set>
#include <cstring>
#include <vector>

const int N = 200000;
int t, n, a[N], b[N], amt[N];
std::vector<int> g[N];
int u[N];

bool dfs(int v) {
	u[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (u[g[v][i]] == 1 || !u[g[v][i]] && !dfs(g[v][i])) return 0;
	u[v] = 2;
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int mx = 0, ind = 0;
		memset(amt, 0, n << 2);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			++amt[a[i]];
			if (amt[a[i]] > mx) {
				ind = a[i];
				mx = amt[a[i]];
			}
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			--b[i];
			if (a[i] != ind && b[i] != ind) g[a[i]].push_back(b[i]);
		}
		bool ok = 1;
		memset(u, 0, n << 2);
		for (int i = 0; i < n; ++i) if (!u[i] && !dfs(i)) ok = 0;
		for (int i = 0; i < n; ++i) g[i].clear();
		if (!ok) printf("WA\n");
		else printf("AC\n");
	}
	return 0;
}