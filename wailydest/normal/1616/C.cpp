#include <cstdio>
#include <algorithm>

const int N = 70;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		if (n <= 2) printf("0\n");
		else {
			int ans = n - 2;
			for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
				int r = 0;
				for (int k = 0; k < n; ++k) if (k != j && k != i) r += (a[k] - a[i]) * (k - j) != (a[k] - a[j]) * (k - i);
				ans = std::min(ans, r);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}