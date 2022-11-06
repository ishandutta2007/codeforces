#include<cstdio>
int a[1001];
int main() {
	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	int l=1, r=n;
	while (l <= r) {
		int t, i;
		scanf("%d", &t);
		if (t <= c / 2) {
			for (i = 1; i < l && a[i] <= t; i++);
			a[i] = t;
			if (i == l) l++;
			printf("%d\n", i);
			fflush(stdout);
		}
		else {
			for (i = n; i > r && a[i] >= t; i--);
			a[i] = t;
			if (i == r) r--;
			printf("%d\n", i);
			fflush(stdout);
		}
	}
	return 0;
}