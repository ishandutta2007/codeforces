#include<cstdio>
#include<algorithm>
using namespace std;

int n, k, edge;
char map[6][250][250];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
  getchar();
  for (int i = 0; i < n; ++i) gets(map[0][i]);
  edge = n;
  --k;
	for (int i = 1; i <= k; ++i) {
	  edge *= n;
		for (int j = 0; j < edge; ++j) {
			for (int l = 0; l < edge; ++l) {
				int tx = j / n, ty = l / n;
				if (map[i - 1][tx][ty] == '*') {
					map[i][j][l] = '*';
				} else {
				  map[i][j][l] = map[i - 1][j % (edge / n)][l % (edge / n)];
				}
			}
		}
	}
	for (int i = 0; i < edge; ++i) puts(map[k][i]);
	return 0;
}