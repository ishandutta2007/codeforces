#include <cstdio>

const int N = 50;
int tt, n, m;
char s[N + 1], t[N + 1];

int main() {
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d%d%s%s", &n, &m, s, t);
		int i;
		for (i = 0; i < m && s[n - i - 1] == t[m - i - 1]; ++i);
		bool ok = 0;
		if (i == m) ok = 1;
		else if (i == m - 1) for (; i < n; ++i) if (s[n - i - 1] == t[0]) ok = 1;
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}