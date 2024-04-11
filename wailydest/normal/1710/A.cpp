#include <cstdio>
#include <algorithm>
#include <utility>

const int N = 100000;
int t, n, m, k, a[N], b[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		bool ok = 0;
		for (int i = 0; i < k; ++i) scanf("%d", a + i);
		for (int t = 0; t < 2; ++t) {
			std::swap(n, m);
			int len = 0;
			for (int i = 0; i < k; ++i) b[i] = a[i] / m;
			std::sort(b, b + k, std::greater<int>());
			int i;
			for (i = 0; i < k && len < n - 1; ++i) len += b[i];
			if (len == n - 1) {
				for (int j = i; j < k; ++j) if (b[j] > 1 && b[j] < b[0]) ok = 1;
			} else if (len >= n) ok = 1;
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}