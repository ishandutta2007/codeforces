#include <cstdio>
#include <algorithm>

using namespace std;

int x[3], y[3];

int check (int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	int b = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
	int c = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	if (a > b) swap (a, b);
	if (b > c) swap (b, c);
	if (a > b) swap (a, b);
	if (a != 0 && b != 0 && c != 0 && a + b == c) return 1;
	return 0;
}

int main() {
	for (int i = 0; i < 3; i++) scanf ("%d%d", &x[i], &y[i]);
	if (check (x[0], y[0], x[1], y[1], x[2], y[2])) { printf ("RIGHT\n"); return 0; }
	int dx = 1, dy = 0;
	for (int i = 0; i < 4; i++) {
		if (check (x[0] + dx, y[0] + dy, x[1], y[1], x[2], y[2])) { printf ("ALMOST\n"); return 0; }
		if (check (x[1] + dx, y[1] + dy, x[2], y[2], x[0], y[0])) { printf ("ALMOST\n"); return 0; }
		if (check (x[2] + dx, y[2] + dy, x[0], y[0], x[1], y[1])) { printf ("ALMOST\n"); return 0; }
		swap (dx, dy);
		dx = -dx;
	}
	printf ("NEITHER\n");
	return 0;
}