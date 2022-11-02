#include <cstdio>
#include <cstring>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) //
#endif

int n, m, q;
bool grid[502][502];
int max_line[502];

int calc_max(int line, bool ret) {
	int j;
	int tot = 0;
	max_line[line] = 0;
	for(j = 0; j < m; j++) {
		if(grid[line][j]) tot++;
		else tot = 0;
		if(tot > max_line[line]) max_line[line] = tot;
	}
	if(ret) {
		tot = max_line[0];
		for(j = 1; j < n; j++)
			if(max_line[j] > tot)
				tot = max_line[j];
		return tot;
	}
	return 0;
}

int main() {
	int i, j, x, y;
	scanf("%d %d %d", &n, &m, &q);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf("%d", &x);
			grid[i][j] = (x == 1);
		}
	for(i = 0; i < n; i++) calc_max(i, false);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &x, &y); x--; y--;
		grid[x][y] = !grid[x][y];
		printf("%d\n", calc_max(x, true));
	}
	return 0;
}