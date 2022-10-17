#include <cstdio>

const int N = 200000;
int t, n, k, ans[N];
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &k, s);
		if (k & 1) for (int i = 0; s[i]; ++i) s[i] = '0' + (s[i] - '0' ^ 1);
		for (int i = 0; i < n; ++i) {
			if (k && s[i] == '0') {
				++ans[i];
				--k;
				s[i] = '1';
			}
		}
		if (k & 1) s[n - 1] = '0';
		ans[n - 1] += k;
		printf("%s\n", s);
		for (int i = 0; i < n; ++i) {
			printf("%d ", ans[i]);
			ans[i] = 0;
		}
		printf("\n");
	}
	return 0;
}