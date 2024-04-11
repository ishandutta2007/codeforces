#include <cstdio>
#include <algorithm>

const int N = 100000;
int t, n, a[N], b[N];

bool test(int k) 
{
	int amt = (n + k) - (n + k) / 4;
	int s = std::min(k, amt) * 100;
	for (int i = n - 1; i >= n - std::max(amt - k, 0); --i) s += a[i];
	for (int i = n - 1; i >= std::max(0, n - amt); --i) s -= b[i];
	return s >= 0;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		std::sort(a, a + n);
		for (int i = 0; i < n; ++i) scanf("%d", b + i);
		std::sort(b, b + n);
		int l = 0, r = n * 5, ans;
		while (l <= r) {
			int m = l + r >> 1;
			if (test(m)) {
				ans = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}