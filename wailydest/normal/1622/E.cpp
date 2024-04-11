#include <cstdio>
#include <algorithm>

const int N = 10;
const int M = 10000;
int t, n, m, x[N], ans[M];
std::pair<int, int> d[M];
char s[N][M + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", x + i);
		for (int i = 0; i < n; ++i) scanf("%s", s[i]);
		int ov = -1;
		for (int i = 0; i < 1 << n; ++i) {
			for (int i = 0; i < m; ++i) d[i] = std::make_pair(0, i);
			int sum = 0;
			for (int j = 0; j < n; ++j) {
				if (i >> j & 1) sum -= x[j];
				else sum += x[j];
				for (int k = 0; k < m; ++k) if (s[j][k] == '1') {
					if (i >> j & 1) ++d[k].first;
					else --d[k].first;
				}
			}
			std::sort(d, d + m);
			for (int j = 0; j < m; ++j) sum += d[j].first * (j + 1);
			if (sum > ov) {
				for (int j = 0; j < m; ++j) ans[d[j].second] = j + 1;
				ov = sum;
			}
		}
		for (int i = 0; i < m; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}