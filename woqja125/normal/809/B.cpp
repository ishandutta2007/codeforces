#include<stdio.h>
int query(int x, int y) {
	char d[20];
	printf("1 %d %d\n", x, y);
	fflush(stdout);
	scanf("%s", d);
	if (d[0] == 'N') return false;
	return true;
} // <=
int findx(int f, int r) {
	while (f < r) {
		int m = (f + r) / 2;
		if (query(m, m + 1)) r = m;
		else f = m+1;
	}
	return f;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int x = findx(1, n);
	int f = 1, r = x;
	while (f < r) {
		int m = (f + r + 1) / 2;
		if (query(m-1, m)) {
			printf("2 %d %d\n", x, findx(f, m-1));
			return 0;
		}
		else f = m;
	}
	f = x; r = n;
	while (f < r) {
		int m = (f + r) / 2;
		if (query(m+1, m)) {
			printf("2 %d %d\n", x, findx(m+1, r));
			return 0;
		}
		else r = m;
	}
	return 0;
}