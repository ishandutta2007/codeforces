#include <cstdio>
#include <algorithm>

const int N = 100;
int t, n;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s);
		int prev = -5, ans = 0;
		for (int i = 0; s[i]; ++i) if (s[i] == '0') {
			ans += std::max(0, 3 - i + prev);
			prev = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}