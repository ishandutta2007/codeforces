#include <cstdio>

const int N = 200000;
int t, n, a[N];
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		for (int i = 0; s[i]; ++i) a[i + 1] = a[i] + (s[i] == '+' ? -1 : 1);
		int ans = 0;
		for (int i = 0; i < n; ++i) for (int j = i + 1; j <= n; ++j) ans += a[j] - a[i] >= 0 && !((a[j] - a[i]) % 3);
		printf("%d\n", ans);
	}
	return 0;
}