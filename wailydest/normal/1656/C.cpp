#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bool any = 0, all = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (a[i] == 1) any = 1;
			else all = 0;
		}
		std::sort(a, a + n);
		bool nb = 0;
		for (int i = 1; i < n; ++i) if (a[i] == a[i - 1] + 1) nb = 1;
		printf("%s\n", all || !any || !nb? "YES" : "NO");
	}
	return 0;
}