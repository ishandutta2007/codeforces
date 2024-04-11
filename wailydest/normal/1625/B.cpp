#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 150000;
int t, n, a[N], prev[N];

int main() 
{
	memset(prev, -1, N << 2);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			if (prev[a[i]] != -1) ans = std::max(ans, prev[a[i]] + n - i);
			prev[a[i]] = i;
		}
		for (int i = 0; i < n; ++i) prev[a[i]] = -1;
		printf("%d\n", ans);
	}
	return 0;
}