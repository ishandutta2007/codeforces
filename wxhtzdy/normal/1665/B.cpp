#include <stdio.h>

#define N   100000

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

static int aa[N];

void sort(int l, int r) {
	static int bb[N];
	int pp, pp0, pp1, i;

	if (l >= r)
		return;
	int m = (l + r) / 2;
	sort(l, m);
	sort(m + 1, r);
	pp = 0, pp0 = l, pp1 = m + 1;
	while (pp0 <= m || pp1 <= r) {
		if (pp1 > r || (pp0 <= m && aa[pp0] < aa[pp1]))
			bb[pp++] = aa[pp0++];
		else
			bb[pp++] = aa[pp1++];
	}
	for (i = 0; i < pp; i++)
		aa[l + i] = bb[i];
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, i, j, mx, ans;

		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &aa[i]);
		sort(0, n - 1);
		mx = 0;
		for (i = 0, j = 0; i < n; i++) {
			j = i;
			while (j + 1 < n && aa[j + 1] == aa[j])
				j++;
			mx = max(mx, j - i + 1), i = j;
		}
		ans = 0;
		while (mx < n) {
			ans++;
			ans += min(mx, n - mx);
			mx <<= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}