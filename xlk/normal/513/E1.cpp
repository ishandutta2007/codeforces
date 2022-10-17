#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int f[420][60][2];
int a[420], s[420];
int ans, n, m;
int S(int l, int r) {
	return s[r + 1] - s[l];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f[i][j][0] = f[i][j][1] = -1000000000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= i; k++) {
			f[i + 1][0][0] = max(f[i + 1][0][0], -S(k, i));
			f[i + 1][0][1] = max(f[i + 1][0][1], S(k, i));
		}

		for (int k = 0; k < m; k++) {
			for (int j = 1; j <= i; j++) {
				int tmp = S(j, i);
				if (f[j][k][0] != -1000000000) {
					tmp += f[j][k][0];
					if (k == m - 2) {
						ans = max(ans, tmp);
					}
					tmp += S(j, i);
					f[i + 1][k + 1][1] = max(tmp, f[i + 1][k + 1][1]);
					tmp -= S(j, i);

					tmp -= S(j, i);
					f[i + 1][k + 1][0] = max(tmp, f[i + 1][k + 1][0]);
					tmp += S(j, i);
				}

				tmp = -S(j, i);
				if (f[j][k][1] != -1000000000) {
					tmp += f[j][k][1];
					if (k == m - 2) {
						ans = max(ans, tmp);						
					}
					tmp -= S(j, i);
					f[i + 1][k + 1][0] = max(tmp, f[i + 1][k + 1][0]);
					tmp += S(j, i);

					tmp += S(j, i);
					f[i + 1][k + 1][1] = max(tmp, f[i + 1][k + 1][1]);
					tmp -= S(j, i);
				}
			}
		}
		for (int k = 0; k < m; k++) {
			f[i + 1][k][0] = max(f[i][k][0], f[i + 1][k][0]);
			f[i + 1][k][1] = max(f[i][k][1], f[i + 1][k][1]);
		}
	}
	cout << ans << endl;
	return 0;
}