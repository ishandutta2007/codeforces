#include <cstdio>

int t, n, r, b;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &r, &b);
		int x = (r - 1) / (b + 1) + 1;
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < x && r; ++j, --r) printf("R");
			printf("B");
			if ((x - 1) * (b - i) >= r) --x;
		}
		while (r--) printf("R");
		printf("\n");
	}
	return 0;
}