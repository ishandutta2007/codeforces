#include <cstdio>

const int N = 100005;
int n, t;
char s[N * 2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		int ans = 1;
		for (int i = 0; i + 1 < 2 * n; ++i) ans += s[i] == '(' && s[i + 1] == '(';
		printf("%d\n", ans);
	}
	return 0;
}