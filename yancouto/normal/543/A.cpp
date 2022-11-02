#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#define mod(x) ((x) % modn)

int n, m, b, modn;
int a[505];
//int solve(int i, int bugs, int lines) {
//	//printf("(%3d, %3d, %3d) = \n", i, bugs, lines);
//	if(lines == 0) { return bugs >= 0; }
//	if(bugs < 0) return 0;
//	if(i == n) return 0;
//	int num = 0;
//	num = mod(solve(i, bugs - a[i], lines - 1) + solve(i + 1, bugs, lines));
//	//printf("(%3d, %3d, %3d) = %3d\n", i, bugs, lines, num);
//	return num;
//}

int memo[2][502][502];
int get(int i, int bugs, int lines) {
	if(lines == 0) return bugs >= 0;
	if(bugs < 0) return 0;
	if(i == n) return 0;
	return memo[i % 2][bugs][lines];
}
int main() {
	int i, j, k;
	scanf("%d %d %d %d", &n, &m, &b, &modn);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	int ind = 0;
	for(i = n - 1; i >= 0; i--)
		for(j = 0; j <= b; j++)
			for(k = 1; k <= m; k++) {
				memo[i % 2][j][k] = mod(get(i, j - a[i], k - 1) + get(i + 1, j, k));
				debug("memo[%d][%d][%d] = %d\n", i, j, k, memo[i % 2][j][k]);
			}
	printf("%d\n", memo[0][b][m]);
}