#include <cstdio>
#include <algorithm>

const int N = 1000005;
int t, n, m, sum[N], sum1[N];
char s[N];
bool u[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &m, s);
		for (int i = 0; i < n * m; ++i) u[i] = 0;
		for (int i = 1; i <= n * m; ++i) sum[i] = sum[i - 1] + (s[i - 1] == '1');
		for (int i = 1; i <= n * m; ++i) sum1[i] = sum1[std::max(0, i - m)] + (sum[i] != sum[std::max(0, i - m)]);
		int col = 0;
		for (int i = 0; i < n * m; ++i) {
			if (s[i] == '1') {
				col += !u[i % m];
				u[i % m] = 1;
			}
			printf("%d ", col + sum1[i + 1]);
		}
		printf("\n");
	}
	return 0;
}