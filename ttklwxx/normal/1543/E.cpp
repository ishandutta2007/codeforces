#include <cstdio>
#include <cstring>
#include<iostream>
#define N	16
 
int main() {
	int t;
 
	scanf("%d", &t);
	while (t--) {
		static int ev[1 << N][N], eo[1 << N], qu[1 << N], dd[1 << N], bb[1 << N], cc[1 << N], pp[1 << N];
		int n, m, h, i, b, u, v, head, cnt;
 
		scanf("%d", &n), m = n << n - 1;
		memset(eo, 0, (1 << n) * sizeof *eo);
		for (h = 0; h < m; h++) {
			scanf("%d%d", &u, &v);
			ev[u][eo[u]++] = v, ev[v][eo[v]++] = u;
		}
		for (i = 0; i < 1 << n; i++)
			dd[i] = n + 1;
		head = cnt = 0;
		bb[0] = 0, dd[0] = 0, qu[head + cnt++] = 0;
		while (cnt) {
			int d, o;
 
			u = qu[cnt--, head++], d = dd[u] + 1;
			for (o = eo[u]; o--; ) {
				v = ev[u][o];
				if (dd[v] > d)
					dd[v] = d, bb[v] = u == 0 ? 1 << o : bb[u], qu[head + cnt++] = v;
				else if (dd[v] == d)
					bb[v] |= bb[u];
			}
		}
		for (u = 0; u < 1 << n; u++)
			pp[bb[u]] = u;
		for (i = 0; i < n; i++)
			cc[1 << i] = i;
		for (b = 1; b < 1 << n; b++)
			cc[b] = cc[b & b - 1] ^ cc[b & -b];
		for (b = 0; b < 1 << n; b++)
			printf("%d ", pp[b]);
		printf("\n");
		if ((n & n - 1) != 0)
			printf("-1\n");
		else {
			for (u = 0; u < 1 << n; u++)
				printf("%d ", cc[bb[u]]);
			printf("\n");
		}
	}
	return 0;
}