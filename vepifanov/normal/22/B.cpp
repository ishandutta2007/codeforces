#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m;
char g[26][26];

int main() {
	scanf ("%d%d\n", &n, &m);
	for (int i = 0; i < n; i++) gets (g[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			int cur = 0;
			for (int k = 0; k < m; k++) {
				int ok = 1;
				for (int l = i; l < j; l++)
					ok &= int (g[l][k] == '0');
				if (ok) cur++; else cur = 0;
				if (cur > 0 && (cur + j - i) * 2 > ans) ans = (cur + j - i) * 2;
			}
		}
	printf ("%d\n", ans);
	return 0;
}