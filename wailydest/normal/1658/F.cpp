#include <cstdio>

const int N = 200000;
int t, n, m;
char s[N + 1];
long long sum[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &m, s);
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += s[i] - '0';
		if ((long long)cnt * m % n) printf("-1\n");
		else {
			for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (s[i] == '1' ? n - cnt : -cnt);
			bool ok = 0;
			for (int i = m; i <= n && !ok; ++i) if (sum[i] == sum[i - m]) {
				ok = 1;
				printf("1\n%d %d\n", i - m + 1, i);
			}
			if (!ok) {
				for (int i = n - m; i <= n; ++i) if (sum[i] == sum[i - n + m]) {
					printf("2\n1 %d\n%d %d\n", i - n + m, i + 1, n);
					break;
				}
			}
		}
	}
	return 0;
}