#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int f[260];
bool is_face(char p[52][52], int x, int y) {
	f['f'] = f['a'] = f['c'] = f['e'] = 0;
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++) {
			debug("check[%c]\n", p[x + i][y + j]);
			f[p[x + i][y + j]]++;
		}
	debug("---\n");
	return f['f'] && f['a'] && f['c'] && f['e'];
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	char pic[52][52];
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf(" %c", &pic[i][j]);
	int count = 0;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < m - 1; j++)
			count += is_face(pic, i, j);
	printf("%d\n", count);
}