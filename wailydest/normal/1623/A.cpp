#include <cstdio>

int t, n, m, x, y, x1, y1;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &x1, &y1);
		int dx = 1, dy = 1, ans = 0;
		while (x != x1 && y != y1) {
			if (x + dx > n || x + dx < 0) dx = -dx;
			if (y + dy > m || y + dy < 0) dy = -dy;
			x += dx;
			y += dy;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}