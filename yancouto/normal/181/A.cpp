#include <bits/stdc++.h>
using namespace std;

char g[102][102];
int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	int mn_i = INT_MAX, mx_i = INT_MIN;
	int mn_j = INT_MAX, mx_j = INT_MIN;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] != '*') continue;
			mn_i = min(mn_i, i);
			mx_i = max(mx_i, i);
			mn_j = min(mn_j, j);
			mx_j = max(mx_j, j);
		}
	for(i = 0; i < 4; i++) {
		int gi = i & 1? mn_i : mx_i;
		int gj = i & 2? mn_j : mx_j;
		if(g[gi][gj] != '*') {
			printf("%d %d\n", gi + 1, gj + 1);
			return 0;
		}
	}
}