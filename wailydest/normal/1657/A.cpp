#include <cstdio>

int t, x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		int d = x * x + y * y;
		if (!d) printf("0\n");
		else {
			bool ok = 0;
			for (int i = 0; i <= 100; ++i) if (i * i == d) ok = 1;
			printf("%d\n", ok ? 1 : 2);
		}
	}
	return 0;
}