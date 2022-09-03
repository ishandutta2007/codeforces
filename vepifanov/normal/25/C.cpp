#include <cstdio>
#include <algorithm>

using namespace std;

int g[300][300];

int main() {
	int n, m;
	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &g[i][j]);
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		long long s = 0;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				g[j][k] = min (g[j][k], g[j][a] + g[b][k] + c);
				g[j][k] = min (g[j][k], g[j][b] + g[a][k] + c);
				s += g[j][k];
			}
		printf ("%I64d ", s / 2);
	}
	printf ("\n");
	return 0;
}