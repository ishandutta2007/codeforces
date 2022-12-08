#include <cstdio>
#include <algorithm>
using namespace std;

int m, n, t[50001][6], a[50001];

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &t[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[j] = max(a[j], a[j - 1]) + t[j][i];
	printf("%d", a[1]);
	for (int i = 2; i <= m; i++)
		printf(" %d", a[i]);
}