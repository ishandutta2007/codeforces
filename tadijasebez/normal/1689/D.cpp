#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char cell[N][N];

int main() {
	int tc;
	scanf("%i",&tc);
	while (tc--) {
		int n, m;
		scanf("%i %i", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%s", cell[i] + 1);

		int top = 1000, bot = 0, x = -1, y = -1;
		while (top >= bot) {
			int mid = top + bot >> 1;

			int xl = 2, xr = n + m, yl = 1 - m, yr = n - 1;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (cell[i][j] == 'B') {
						xl = max(xl, i + j - mid);
						xr = min(xr, i + j + mid);
						yl = max(yl, i - j - mid);
						yr = min(yr, i - j + mid);
					}
				}
			}

			bool ok = false;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (xl <= i + j && i + j <= xr) {
						if (yl <= i - j && i - j <= yr) {
							ok = true;
							x = i;
							y = j;
							break;
						}
					}
				}
				if (ok)
					break;
			}

			if (!ok) {
				bot = mid + 1;
			} else {
				top = mid - 1;
			}
		}
		printf("%i %i\n", x, y);
	}
    return 0;
}