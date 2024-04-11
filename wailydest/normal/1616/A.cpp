#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n, a[N];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			if (a[i] < 0) a[i] = -a[i];
		}
		std::sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n;) {
			int amt = 0;
			do {
				++amt;
				++i;
			} while (i < n && a[i] == a[i - 1]);
			if (!a[i - 1]) ++ans;
			else ans += std::min(2, amt);
		}
		printf("%d\n", ans);
	}
	return 0;
}