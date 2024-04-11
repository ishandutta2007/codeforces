#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, m, amt[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ++amt[std::max(i, n - i - 1) + std::max(j, m - j - 1)];
		for (int i = 0, j = 0; i < n * m; ++i) {
			while (!amt[j]) ++j;
			printf("%d ", j);
			--amt[j];
		}
		printf("\n");
	}
	return 0;
}