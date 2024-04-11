#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int fi = -1, la = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (i && a[i] == a[i - 1]) {
				if (fi == -1) fi = i;
				la = i;
			}
		}
		printf("%d\n", la == fi ? 0 : std::max(1, la - fi - 1));
	}
	return 0;
}