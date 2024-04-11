#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
int Case;
int n, m, a[N][N];
int main() {
	scanf("%d", &Case);
	while (Case--) {
		vector<pii> g;
		scanf("%d%d", &n, &m);
		for (int i = 1, x; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				a[i][j] = 0;
				scanf("%d", &x);
				g.push_back(pii(x, i << 10 | j));
			}
		sort(g.begin(), g.end());
		for (int i = 0; i < m; ++i) {
			pii u = g[i];
			int x = u.second >> 10, y = u.second & 1023;
			a[x][i + 1] = u.first;
		}
		for (int i = m; i < (int)g.size(); ++i) {
			pii u = g[i];
			int x = u.second >> 10, y = u.second & 1023;
			for (int j = 1; j <= m; ++j) {
				if (!a[x][j]) { a[x][j] = u.first; break; }
			}
		}
		for (int i = 1; i <= n; puts(""), ++i)
			for (int j = 1; j <= m; ++j) printf("%d ", a[i][j]);
	}
	return 0;
}