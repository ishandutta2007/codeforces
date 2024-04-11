#include <bits/stdc++.h>

const int N = 5000;

char A[N + 5], B[N + 5];

int f[N + 5][N + 5];

int main() {
	int n, m; scanf("%d%d%s%s", &n, &m, A + 1, B + 1);
	
	int ans = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) - 1;
		if( A[i] == B[j] ) f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 2);
		f[i][j] = std::max(f[i][j], 0);
//		printf("%d %d : %d\n", i, j, f[i][j]);
		ans = std::max(ans, f[i][j]);
	}
	printf("%d\n", ans);
}