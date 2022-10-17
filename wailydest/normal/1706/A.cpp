#include <cstdio>
#include <algorithm>

const int N = 50;
int t, n, m;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) s[i] = 'B';
		s[m] = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			--x;
			x = std::min(x, m - x - 1);
			if (s[x] == 'A') x = m - x - 1;
			s[x] = 'A';
		}
		printf("%s\n", s);
	}
	return 0;
}