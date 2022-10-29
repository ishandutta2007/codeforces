#include <bits/stdc++.h>
using namespace std;

int mp[1005][1005];
char s[1005];

int calc(int n, int m) {
	if (n < 4) return ((m + 1) / 2) * 2;
	else return (m + 1) / 2 * 2 + ((n - 4 + 1) / 2) * 2;
}

int main() {
	int T; scanf("%d",&T);
	while (T --) {
		int n, m;
		scanf("%d%d", &n, &m); int flag = 0;
		if (calc(n, m) < calc(m, n)) {
			swap(n, m);
			flag = 1;
		}
		for (int i = 1; i <= m; ++ i) mp[1][i] = (i & 1);
		for (int i = 1; i <= m; ++ i) mp[2][i] = 0;
		for (int i = 3; i <= n - 2; ++ i) {
			//printf("%d", i & 1);
			mp[i][1] = i & 1;
			for (int j = 2; j <= m - 1; ++ j) mp[i][j] = 0;
			mp[i][m] = i & 1;
		}
		for (int i = 1; i <= m; ++ i) mp[n - 1][i] = 0;
		for (int i = 1; i <= m; ++ i) mp[n][i] = (i & 1);
		
		if (flag) {
			for (int i = 1; i <= m; ++ i) {
				for (int j = 1; j <= n; ++ j) {
					printf("%d", mp[j][i]);
				}
				printf("\n");
			}
		} else {
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= m; ++ j) {
					printf("%d", mp[i][j]);
				}
				printf("\n");
			}
			printf("\n"); 
		}
	}
	return 0;
}