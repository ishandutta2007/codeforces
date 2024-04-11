#include <cstdio>

int t, x, a[3];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		scanf("%d%d%d", a, a + 1, a + 2);
		if (a[x - 1] != 0 && a[a[x - 1] - 1] != 0) printf("YES\n");
		else printf("NO\n");
	}
}