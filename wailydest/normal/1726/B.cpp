#include <cstdio>

int n, m, t;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n > m) printf("No\n");
		else {
			if (n & 1) {
				printf("Yes\n");
				for (int i = 0; i + 1 < n; ++i) printf("1 ");
				printf("%d\n", m - n + 1);
			} else if (m & 1) printf("No\n");
			else {
				printf("Yes\n");
				for (int i = 0; i + 2 < n; ++i) printf("1 ");
				printf("%d %d\n", m - n + 2 >> 1, m - n + 2 >> 1);
			}
		}
	}
	return 0;
}