#include <stdio.h>
#include <stdlib.h>

#define N	500000

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int *eh[N], eo[N];

void append(int i, int h) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		eh[i] = (int *) realloc(eh[i], o * 2 * sizeof *eh[i]);
	eh[i][o] = h;
}

int main() {
	static int aa[N], bb[N], dd[N];
	int n, c, i, j, ans;

	scanf("%d%d", &n, &c); --c;
	for (i = 0; i < N; i++)
		eh[i] = (int *) malloc(2 * sizeof *eh[i]), eo[i] = 0;
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]), --aa[i], append(aa[i], i);
	for (i = 0; i < n; i++)
		bb[i] = (i > 0 ? bb[i - 1] : 0) + (aa[i] == c ? 1 : 0);
	ans = bb[n - 1];
	for (i = 0; i < N; i++) {
		int pp, cc0, cc1;

		if (i == c || eo[i] == 0)
			continue;
		for (j = 0, pp = 0; j < eo[i]; j++) {
			dd[pp++] = 1;
			if (j + 1 < eo[i])
				dd[pp++] = bb[eh[i][j]] - bb[eh[i][j + 1]];
		}
		cc0 = cc1 = 0;
		for (j = 0; j < pp; j++)
			cc0 += dd[j], ans = max(ans, bb[n - 1] + cc0 - cc1), cc1 = min(cc1, cc0);
	}
	printf("%d\n", ans);
	return 0;
}