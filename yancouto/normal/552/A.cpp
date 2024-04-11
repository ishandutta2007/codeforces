#include <cstdio>

int a[104][104];
int main() {
	int n, i, j;
	scanf("%d", &n);
	int x1, y1, x2, y2;
	for(i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--; y2--;
		for(j = y1; j <= y2; j++) {
			a[j][x1]++;
			a[j][x2]--;
		}
	}
	int tot = 0;
	for(i = 0; i < 100; i++) {
		int s = 0;
		for(j = 0; j < 100; j++) {
			s += a[i][j];
			tot += s;
			// if(a[i][j])
			// 	printf("a[%d][%d] = %d -- s %d -- tot %d\n", i, j, a[i][j], s, tot);
		}
	}
	printf("%d\n", tot);
	return 0;
}