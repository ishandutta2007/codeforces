#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int a[N][N], b[N][N], c[N][N];

int sell[102], p[102];
int main() {
	int i, j, g, n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++) {
		scanf("%*s");
		for(j = 0; j < m; j++)
			scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
	}
	int mx = 0;
	for(i = 0; i < n; i++) {
		for(g = 0; g < n; g++) {
			if(g == i) continue;
			for(j = 0; j < m; j++) {
				p[j] = j;
				sell[j] = b[g][j];
			}
			sort(p, p + m, [&](int p, int q) { return (sell[p] - a[i][p]) > (sell[q] - a[i][q]); });
			int left = k;
			int prof = 0;
			for(j = 0; left && j < m && (sell[p[j]] - a[i][p[j]]) > 0; j++) {
				int buy = min(left, c[i][p[j]]);
				prof += (sell[p[j]] - a[i][p[j]]) * buy;
				left -= buy;
			}
			mx = max(mx, prof);
		}
	}
	printf("%d\n", mx);
}