#include <cstdio>

const int N = 100000;
int t, n, to[N], inv[N];
bool u[N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			u[i] = 0;
			int x;
			scanf("%d", &x);
			inv[x - 1] = i;
		}
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			to[i] = inv[x - 1];
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) if (!u[i]) {
			int len = 0, cur = i;
			do {
				u[cur] = 1;
				++len;
				cur = to[cur];
			} while (!u[cur]);
			sum += len & ~1;
		}
		printf("%lld\n", (long long)(sum / 2) * (sum / 2 - 1) * 2 + (long long)sum * (n - sum + 1));
	}
	return 0;
}