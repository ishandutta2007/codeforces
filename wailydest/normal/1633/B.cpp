#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n;
char s[N + 1];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int c[2] = {0};
		for (int i = 0; s[i]; ++i) ++c[s[i] - '0'];
		if (c[0] == c[1]) printf("%d\n", c[0] - 1);
		else printf("%d\n", std::min(c[0], c[1]));
	}
	return 0;
}