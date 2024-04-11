#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 300005;
int t, n, m, a[N];
std::pair<int, int> b[N];
bool bad[N];
std::vector<int> g[N], famt[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		int amt, num;
		std::vector<int> amts;
		for (int i = 0, j = 0; i < n; ++j) {
			b[j].first = a[i];
			b[j].second = 0;
			do {
				++b[j].second;
				++i;
			} while (i < n && a[i] == a[i - 1]);
			amts.push_back(b[j].second);
			famt[b[j].second].push_back(j);
			num = j + 1;
		}
		std::sort(amts.begin(), amts.end());
		amts.resize(std::unique(amts.begin(), amts.end()) - amts.begin());
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			x = std::lower_bound(b, b + num, std::make_pair(x, 0)) - b;
			y = std::lower_bound(b, b + num, std::make_pair(y, 0)) - b;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		long long ans = 0;
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) bad[g[i][j]] = 1;
			for (int j = 0; j < (int)amts.size(); ++j) {
				int k, cur = amts[j];
				for (k = (int)famt[cur].size() - 1; k >= 0 && (bad[famt[cur][k]] || famt[cur][k] == i); --k);
				if (k >= 0) ans = std::max(ans, (long long)(b[i].first + b[famt[cur][k]].first) * (b[i].second + cur));
			}
			for (int j = 0; j < (int)g[i].size(); ++j) bad[g[i][j]] = 0;
		}
		printf("%lld\n", ans);
		for (int i = 0; i <= n; ++i) {
			famt[i].clear();
			g[i].clear();
		}
	}
	return 0;
}