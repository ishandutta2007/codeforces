#include <cstdio>

const int N = 105;
int t, n;
bool d[2][N][N];

int main() {
	d[0][0][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			d[0][i][j] = (j ? !d[j & 1 ^ 1][i - 1][j - 1] : 0) || (i - j ? !d[j & 1 ^ 1][i - 1][j] : 0);
			d[1][i][j] = (j ? !d[j & 1][i - 1][j - 1] : 0) || (i - j ? !d[j & 1][i - 1][j] : 0);
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			cnt += x & 1;
		}
		printf("%s\n", d[0][n][cnt] ? "Alice" : "Bob");
	}
	return 0;
}