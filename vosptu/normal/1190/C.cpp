#include <bits/stdc++.h>
using namespace std;

int n, k;
char c[100010];
int a[100010];
int sum[400010][2];

void update(int k) {
	sum[k][0] = sum[k * 2][0] + sum[k * 2 + 1][0];
	sum[k][1] = sum[k * 2][1] + sum[k * 2 + 1][1];
}

void make(int k, int l, int r, int* a) {
	if (l < r) {
		make(k * 2, l, (l + r) / 2, a);
		make(k * 2 + 1, (l + r) / 2 + 1, r, a);
		update(k);
	}else {
		sum[k][0] = sum[k][1] = 0;
		sum[k][a[l]] = 1;
	}
}

void modify(int k, int l, int r, int x, int y) {
	if (l == r) {
		sum[k][0] = sum[k][1] = 0;
		sum[k][y] = 1;
	}else {
		if (x <= (l + r) / 2)
			modify(k * 2, l, (l + r) / 2, x, y);
		else
			modify(k * 2 + 1, (l + r) / 2 + 1, r, x, y);
		update(k);
	}
}

int query_first(int k, int l, int r, int b) {
	if (l == r)
		return l;
	if (sum[k * 2][b])
		return query_first(k * 2, l, (l + r) / 2, b);
	else
		return query_first(k * 2 + 1, (l + r) / 2 + 1, r, b);
}

int query_last(int k, int l, int r, int b) {
	if (l == r)
		return l;
	if (sum[k * 2 + 1][b])
		return query_last(k * 2 + 1, (l + r) / 2 + 1, r, b); 
	else
		return query_last(k * 2, l, (l + r) / 2, b);
}

bool canwin() {
	if (sum[1][0] == 0 || sum[1][1] == 0)
		return true;
	for (int b = 0; b <= 1; b++) {
		if (query_last(1, 1, n, b) - query_first(1, 1, n, b) <= k - 1)
			return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", c + 1);
	for (int i = 1; i <= n; i++)
		a[i] = c[i] - '0';
	make(1, 1, n, a);

	if (canwin()) {
		printf("tokitsukaze\n");
		return 0;
	}

	bool win = true;
	for (int b = 0; b <= 1; b++) {
		make(1, 1, n, a);
		for (int i = 1; i <= k; i++)
			modify(1, 1, n, i, b);
		if (!canwin()) {
			win = false;
		}
		for (int i = k + 1; i <= n; i++) {
			modify(1, 1, n, i - k, a[i - k]);
			modify(1, 1, n, i, b);
			if (!canwin()) {
				win = false;
			}
		}
	}
	if (win) {
		printf("quailty\n");
	}else {
		printf("once again\n");
	}
}