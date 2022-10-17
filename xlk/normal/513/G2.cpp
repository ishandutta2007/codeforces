#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;
double ans;
int a[1000];
double f[201][31][31];
double g[31][31];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f[0][i][j] = (i < j);
		}
	}

	for (int k = 0; k < m; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < n; l++) {
					for (int r = l; r < n; r++) {
						int ni = i;
						int nj = j;
						if (l <= i && i <= r) {
							ni = l + r - i;
						}
						if (l <= j && j <= r) {
							nj = l + r - j;
						}
						f[k + 1][i][j] += f[k][ni][nj];
					}
				}
				f[k + 1][i][j] /= (n * (n + 1) / 2);
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				ans += f[m][i][j];
			} else {
				ans += 1 - f[m][i][j];				
			}
		}
	}
	printf("%.15f\n", ans);
	return 0;
}