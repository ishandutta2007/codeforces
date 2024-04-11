#include <cstdio>
#include <cstring>

const int N = 1000005;
int n, t, a[N], d[N][2][2], pr[N][2][2][2];

void upd(int i, int j, int k, int val, int ii, int jj) 
{
	if (d[i][j][k] > val) {
		d[i][j][k] = val;
		pr[i][j][k][0] = ii;
		pr[i][j][k][1] = jj;
	}
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(**d, 0xc3, 16);
		a[0] = ***d;
		for (int i = 1; i <= n; ++i) {
			memset(*d[i], 0x3f, 16);
			scanf("%d", a + i);
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					if (a[i] > a[i - 1]) {
						upd(i, j, 0, d[i - 1][k][0], k, 0);
						if (d[i - 1][k][1] > a[i]) upd(i, j, 1, d[i - 1][k][1], k, 1);
						else upd(i, j, 0, a[i - 1], k, 1);
					} else {
						if (d[i - 1][k][0] < a[i]) upd(i, j, 1, a[i - 1], k, 0);
					}
					if (i > 1) a[i - 1] *= -1;
				}
				a[i] *= -1;
			}
		}
		bool ok = 0;
		int x, y;
		for (int i = 0; i < 2; ++i) for (int j = 0; j < 2 && !ok; ++j) if (d[n][i][j] <= n) {
			ok = 1;
			x = i;
			y = j;
		}
		if (ok) {
			printf("YES\n");
			for (int i = n; i > 0; --i) {
				if (x) a[i] *= -1;
				int xx = pr[i][x][y][0], yy = pr[i][x][y][1];
				x = xx;
				y = yy;
			}
			for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
			printf("\n");
		} else printf("NO\n");
	}
	return 0;
}