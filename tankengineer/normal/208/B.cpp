#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char c[54][3];
bool f[54][54][54][54], g[54][54];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s", c[i]);
	for (int i = 1; i <= n; ++i) {
	  for (int j = 1; j <= n; ++j) {
		  if (c[i][0] == c[j][0] || c[i][1] == c[j][1]) {
			  g[i][j] = true;
			}
		}
	}
	
	if (n <= 2) {
	  if (n == 1) printf("YES\n");
	  if (n == 2) {if (g[1][2]) printf("YES\n"); else printf("NO\n");}
		return 0;
	}
	
	f[n][n][n - 1][n - 2] = true;
  for (int i = n; i >= 4; --i) {
		for (int j = i; j <= n; ++j) {
			for (int k = i - 1; k <= n; ++k) {
				if (j == k) continue;
				for (int l = i - 2; l <= n; ++l) {
				  if (l == k || l == j) continue;
				  if (f[i][j][k][l]) {
						//printf("%d %d %d %d\n", i, j, k, l);
					  if (g[j][k]) {
						  f[i - 1][j][l][i - 3] = true;
						}
						if (g[j][i - 3]) {
						  f[i - 1][k][l][j] = true;
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
			  if (f[3][i][j][k]) {
					if (g[i][j] && g[i][k]) {
					  puts("YES");
					  return 0;
					}
				}
			}
		}
	}
	puts("NO");
	return 0;
}