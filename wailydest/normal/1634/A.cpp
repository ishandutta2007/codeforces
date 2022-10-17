#include <cstdio>

const int N = 100;
int t, n, k;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%s", &n, &k, s);
		bool ok = 1;
		for (int i = 0; i < n; ++i) if (s[i] != s[n - i - 1]) ok = 0;
		if (!ok) printf("%d\n", k ? 2 : 1);
		else printf("1\n");
	}
	return 0;
}