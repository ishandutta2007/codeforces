#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, d[N][2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) d[i][0] = d[i][1] = 0;
		for (int i = 0; i < n; ++i) {
			int c;
			scanf("%d", &c);
			--c;
			d[c][i & 1] = std::max(d[c][i & 1], d[c][i & 1 ^ 1] + 1);
		}
		for (int i = 0; i < n; ++i) printf("%d ", std::max(d[i][0], d[i][1]));
		printf("\n");
	}
	return 0;
}