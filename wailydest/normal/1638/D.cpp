#include <cstdio>
#include <vector>
#include <utility>

const int N = 1005;
int n, m, a[N][N], ans;
bool u[N][N];
std::vector<std::pair<std::pair<int, int>, int> > res;

void dfs(int x, int y) {
	if (x >= 0 && x + 1 < n && y >= 0 && y + 1 < m) {
		int c = -1;
		bool ok = 1;
		for (int i = 0; i <= 1; ++i) for (int j = 0; j <= 1; ++j) {
			int x0 = x + i, y0 = y + j;
			if (!u[x0][y0]) {
				if (a[x0][y0] != c && c != -1) ok = 0;
				c = a[x0][y0];
			}
		}
		if (ok && c != -1) {
			res.push_back(std::make_pair(std::make_pair(x, y), c));
			for (int i = 0; i <= 1; ++i) for (int j = 0; j <= 1; ++j) {
				ans += !u[x + i][y + j];
				u[x + i][y + j] = 1;
			}
			for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j) dfs(x + i, y + j);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[i] + j);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dfs(i, j);
	if (ans == n * m) {
		printf("%d\n", (int)res.size());
		for (int i = (int)res.size() - 1; i >= 0; --i) printf("%d %d %d\n", res[i].first.first + 1, res[i].first.second + 1, res[i].second);
	} else printf("-1\n");
	return 0;
}