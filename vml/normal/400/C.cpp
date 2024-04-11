#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void go(int x1, int y1, int x, int y, int z, int n, int m) {
	while (x != 0) {
		x--;
		int nx1 = y1, ny1 = n - x1 + 1;
		x1 = nx1;
		y1 = ny1;
		swap(n, m);
	}
	while (y != 0) {
		y--;
		y1 = m - y1 + 1;
	}
	while (z != 0) {
		z--;
		int nx1 = m - y1 + 1, ny1 = x1;
		x1 = nx1;
		y1 = ny1;
		swap(n, m);
	}
	printf("%d %d\n", x1, y1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y, z, p;
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
	x %= 4;
	y %= 2;
	z %= 4;
	for (int i = 0; i < p; i++) {
		int x1, y1;
		scanf("%d %d", &x1, &y1);
		go(x1, y1, x, y, z, n, m);
	}
	return 0;
}