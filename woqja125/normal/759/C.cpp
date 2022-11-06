#include<stdio.h>
int stk[100001], top = -1;
int x[100001];

struct node {
	int sum = 0, max = 0;
} IT[300001];
int b;

int max(int a, int b) { return a > b ? a : b; }

void add(int x, int d) {
	x += b;
	IT[x].sum = IT[x].max = d;
	while (x /= 2) {
		IT[x].sum = IT[x*2].sum + IT[x * 2 + 1].sum;
		IT[x].max = max(IT[x * 2].max, IT[x * 2].sum + IT[x * 2 + 1].max);
	}
}

int find() {
	int x = 1, suml = 0;
	if (IT[x].max <= 0) return -1;
	while (x < b) {
		if (suml + IT[x * 2].max > 0) x = x * 2;
		else {
			suml += IT[x * 2].sum;
			x = x * 2 + 1;
		}
	}
	return x - b;
}

int main() {
	int n, p, t;
	scanf("%d", &n);
	for (b = 1; b < n; b *= 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p, &t);
		if (t == 0) {
			add(n - p, -1);
		}
		else {
			add(n - p, 1);
			scanf("%d", x+p);
		}
		int l = find();
		printf("%d\n", l == -1 ? -1 : x[n - l]);
	}
	return 0;
}