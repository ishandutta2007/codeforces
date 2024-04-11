#include <cstdio>
int main() {
	int T, x1, y1, x2, y2;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%lld\n", 1ll*(x2-x1)*(y2-y1)+1);
	}
}