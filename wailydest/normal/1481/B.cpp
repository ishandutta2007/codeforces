#include <cstdio>

const int N = 100;
int t, n, k, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		if (k > N * N) printf("-1\n");
		else {
			int ans;
			for (int i = 0; i < k; ++i) {
				int j;
				for (j = 0; j < n - 1 && a[j + 1] <= a[j]; ++j);
				if (j != n - 1) ++a[j];
				if (i == k - 1) ans = j;
			}
			if (ans == n - 1) printf("-1\n");
			else printf("%d\n", ans + 1);
		}
	}
	return 0;
}