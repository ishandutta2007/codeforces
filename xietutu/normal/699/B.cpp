#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
char a[1010][1010];
int n, m, tot, x[1010], y[1010];
bool flag;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == '*') {
				++x[i]; ++y[j];
				++tot;
			}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			if ((x[i] + y[j] - (a[i][j] == '*')) == tot) {
				printf("YES\n%d %d\n", i, j);
				flag = true;
				break;
			}
		if (flag) break;
	}
	if (!flag) printf("NO\n");
}