#include<stdio.h>
int p[200001];
int main() {
	int n, i, t, c=0, cnt=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", p + i);
	for (i = 1; i <= n; i++) {
		scanf("%d", &t); c += t;
	}
	c %= 2;
	for (i = 1; i <= n; i++) {
		if (p[i] != 0) {
			for (int x = i; ;) {
				int t = p[x];
				p[x] = 0;
				x = t;
				if (x == i) break;
			}
			cnt++;
		}
	}
	printf("%d", 1-c + ((cnt<=1)?0:cnt));

	return 0;
}