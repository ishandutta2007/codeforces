#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100010;
int n, m, k, ans, E[maxn][3];
bool p[maxn];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	ans = -1;
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &E[i][0], &E[i][1], &E[i][2]);
	for (int i = 1; i <= k; ++i) {
		int u; scanf("%d", &u);
		p[u] = true;
	}
	for (int i = 1; i <= m; ++i) {
		int u = E[i][0], v = E[i][1];
		if (p[u] != p[v]) 
			if (ans == -1 || E[i][2] < ans) ans = E[i][2];
	}
	printf("%d\n", ans);
}