#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int p = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (a[i] < a[p]) p = i;
		}
		std::rotate(a, a + p, a + n);
		bool ok = a[0] == 1;
		for (int i = 1; i < n; ++i) if (a[i] > a[i - 1] + 1 || a[i] == 1) ok = 0;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}