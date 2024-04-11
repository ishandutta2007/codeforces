#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;

const int N = 105;

int a[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &k);	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = N;
	if (n > k) {
		for (int i = 0; i < n; ++i) {
			int tmp = 0;
			for (int j = 0; j < n; ++j) {
				int cost = 0;
				for (int k = 0; k < m; ++k) {
					cost += a[i][k] != a[j][k];
				}
				tmp += min(cost, m - cost);
			}
			ans = min(ans, tmp);
		}
	} else {
		for (int st = 0; st < (1 << n); ++st) {
			int tmp = 0;
			for (int i = 0; i < m; ++i) {
				int cost = 0;
				for (int j = 0; j < n; ++j) {
					if (a[j][i] != (st >> j & 1)) {
						++cost;
					}
				}
				tmp += min(cost, n - cost);
			}
			ans = min(ans, tmp);
		}
	}
	printf("%d\n", ans > k ? -1 : ans);
	return 0;
}