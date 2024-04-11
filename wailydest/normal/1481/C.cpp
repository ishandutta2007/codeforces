#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

const int N = 100000;
int t, n, m, a[N], p[N], u[N], c[N];
std::vector<int> f[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
		}
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			--v;
			if (a[i] != v) f[v].push_back(i);
			u[v] = i + 1;
		}
		bool ok = true;
		for (int i = 0; i < m; ++i) {
			scanf("%d", c + i);
			--c[i];
		}
		std::vector<std::pair<int, int> > ov;
		for (int i = m - 1; i >= 0; --i) {
			if (!f[c[i]].empty()) {
				ov.push_back(std::make_pair(i, f[c[i]].back()));
				p[i] = f[c[i]].back();
				f[c[i]].pop_back();
			}
			else if (u[c[i]]) {
				ov.push_back(std::make_pair(i, u[c[i]] - 1));
				p[i] = u[c[i]] - 1;
			}
		}
		std::reverse(ov.begin(), ov.end());
		for (int i = 0, j = 0; i < m; ++i) {
			if (j >= (int)ov.size() || ov[j].first != i) {
				if (u[c[i]]) p[i] = u[c[i]] - 1;
				else {
					if (j >= (int)ov.size()) ok = false;
					else p[i] = ov[j].second;
				}
			}
			else ++j;
		}
		for (int i = 0; i < n; ++i) if (!f[i].empty()) {
			f[i].clear();
			ok = false;
		}
		if (ok) {
			printf("YES\n");
			for (int i = 0; i < m; ++i) printf("%d ", p[i] + 1);
		}
		else printf("NO");
		printf("\n");
		memset(u, 0, 4 * n);
	}
	return 0;
}