#include <bits/stdc++.h>
using namespace std;

#define N 2100
#define P 1000000007
int n, m;
char S[N];
int a[N][N], sumra[N][N], sumda[N][N], addD[N][N], addR[N][N], R[N][N], D[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", S);
		for (int j = 0; j < m; j++)
			if (S[j] == 'R')
				a[i][j + 1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j; j--)
			sumra[i][j] = sumra[i][j + 1] + a[i][j];
	}
	for (int j = 1; j <= m; j++)
		for (int i = n; i; i--)
			sumda[i][j] = sumda[i + 1][j] + a[i][j];

	addD[1][1] = addR[1][1] = 1;
	addD[2][1] = -1;
	addR[1][2] = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			D[i][j] = (D[i - 1][j] + addD[i][j]) % P;
			R[i][j] = (R[i][j - 1] + addR[i][j]) % P;
			if (i < n) {
				addD[i + 1][j] = (addD[i + 1][j] + R[i][j]) % P;
				addD[n - sumda[i + 1][j] + 1][j] = (addD[n - sumda[i + 1][j] + 1][j] - R[i][j]) % P;
			}
			if (j < m) {
				addR[i][j + 1] = (addR[i][j + 1] + D[i][j]) % P;
				addR[i][m - sumra[i][j + 1] + 1] = (addR[i][m - sumra[i][j + 1] + 1] - D[i][j]) % P;
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		printf("%d ", D[i][j]);
	// 	printf("\n");
	// }
	// printf("==========\n");
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		printf("%d ", R[i][j]);
	// 	printf("\n");
	// }
	
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	int ans = (R[n][m] + D[n][m]) % P;
	ans = (ans + P) % P;
	printf("%d\n", ans);
}