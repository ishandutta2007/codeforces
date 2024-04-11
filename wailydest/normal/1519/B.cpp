#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, m, k, a[N][N];

int main() 
{
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
		if (!i || !j) a[i][j] = i + j;
		else a[i][j] = std::min(100000, a[i - 1][j] + j + 1);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		if (a[n - 1][m - 1] == k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}