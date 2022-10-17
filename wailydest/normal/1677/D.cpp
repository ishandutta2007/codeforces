#include <cstdio>

const int md = 998244353;
inline int mul(int a, int b) {
	return (long long)a * b % md;
}

const int N = 1000000;
int t, n, k, a[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		int ans = 1;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (i + k < n) {
				if (x == -1) ans = mul(ans, i + k + 1);
				else if (x > i) ans = 0;
				if (!x) ans = mul(ans, k + 1);
			} else {
				if (x > 0) ans = 0;
				ans = mul(ans, n - i);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}