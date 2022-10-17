#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, arr[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int *a = arr;
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int z = 0;
		while (n > 1) {
			int fi = a[0];
			for (int i = 0; i < n - 1; ++i) a[i] = a[i + 1] - a[i];
			if (z) {
				a[n - 1] = fi;
				--z;
			} else --n;
			std::sort(a, a + n);
			while (n > 1 && !a[0]) {
				++z;
				++a;
				--n;
			}
		}
		printf("%d\n", a[0]);
	}
	return 0;
}